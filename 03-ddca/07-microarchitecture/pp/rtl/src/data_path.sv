`timescale 1ns / 1ps
// Create Date: 10/28/2021 08:03:15 AM


module data_path(
    // INPUTS
    input logic         clk_i
    ,input logic        reset_i
    ,input logic        mem_to_reg_i
    ,input logic        branch_i        // to be pipelined until DEC stage
    ,input logic        pc_beq_i        // is only valid after DEC stage
    //,input logic        pc_bne_i
    ,input logic        b_alu_input_i
    ,input logic        reg_dst_rtrd_i
    ,input logic        enable_wreg_i
    ,input logic        enable_wmem_i
    ,input logic        pc_j_i
    ,input logic        apply_shift_i
    ,input logic [1:0]  alu_alt_ctrl_i2
    ,input logic [31:0]  instr_i32
    ,input logic [31:0]  read_data_i32

    // OUTPUTS
    ,output logic [31:0] pc_o32
    ,output logic [31:0] alu_out_o32
    ,output logic        zero_o
    ,output logic [31:0] write_data_o32
    ,output logic        enable_wmem_o
    ,output logic [5:0]  op_o6
    ,output logic [5:0]  funct_o6
    ,output logic        branch_o       // to be provided to controller once
                                        // zero_o is available at DEC stage
    );

    `include "defs/mips_defs.sv"

    //logic [4:0] dst_reg_addr_l5;
    //logic [31:0] pc_next_l32;
    //logic [31:0] pc_next_br_l32;
    //logic [31:0] pc_plus4_l32;
    //logic [31:0] pc_branch_l32;
    //logic [31:0] sign_imm_l32;
    //logic [31:0] sign_immsh_l32;
    //logic [31:0] se_shamt_l32;
    //logic [31:0] src_a_reg_l32;
    //logic [31:0] src_a_l32;
    //logic [31:0] src_b_l32;
    //logic [31:0] res_l32;

    // FIXME: beq & bne form complete set.

    // -------------------------------------------------------------------- //
    // LOGIC DECLR -------------------------------------------------------- //
    // -------------------------------------------------------------------- //

    // Fetch Stage -------------------------------------------------------- //
    
    // Stage Wires.
    logic [31:0] pc_lf32;
    logic [31:0] pc_plus4_lf32;
    logic [31:0] pc_next_br_lf32;
    logic [31:0] pc_next_lf32;

    // Hazard Detection Unit Wires.
    logic stall_lf;
    //logic lw_stall_lf;
    

    // Decode Stage ------------------------------------------------------- //

    // Pipelined Data.
    logic [31:0] instr_ld32;
    logic [31:0] pc_plus4_ld32;

    // Pipelined Controls.
    //logic enable_wreg_ld;
    //logic mem_to_reg_ld;
    //logic enable_wmem_ld;

    // Stage Wires.
    logic [31:0] rd1_ld32;
    logic [31:0] rd2_ld32;
    logic [31:0] sign_imm_ld32;
    logic [31:0] sign_immsh_ld32;
    logic [31:0] se_shamt_ld32;
    logic [31:0] pc_branch_ld32;

    // Hazard Detection Unit Wires.
    logic stall_ld;
    logic forward_rd1_ld;
    logic forward_rd2_ld;
    logic [31:0] forwarding_rd1_ld32;
    logic [31:0] forwarding_rd2_ld32;
    //logic branch_stall_ld;


    // Execute Stage ------------------------------------------------------ //

    // Pipelined Data.
    logic [5:0] funct_le6;
    logic [31:0] rd1_le32;
    logic [31:0] rd2_le32;
    logic [4:0]  rs_le5;
    logic [4:0]  rt_le5;
    logic [4:0]  rd_le5;
    logic [31:0] sign_imm_le32;
    logic [31:0] se_shamt_le32;
    logic [31:0] pc_plus4_le32;

    // Pipelined Controls.
    logic enable_wreg_le;
    logic mem_to_reg_le;
    logic enable_wmem_le;
    logic branch_le;
    logic pc_j_le;
    logic [1:0] alu_alt_ctrl_le2;
    logic b_alu_input_le;
    logic apply_shift_le;
    logic reg_dst_rtrd_le;

    // Stage Wires.
    logic [31:0] src_a_le32;
    logic [31:0] src_b_le32;
    logic [31:0] write_data_le32;
    logic [4:0]  dst_reg_addr_le5;
    logic [31:0] sign_immsh_le32;
    logic [31:0] pc_branch_le32;
    logic [31:0] alu_out_le32;
    logic zero_le;

    // Hazard Detection Unit Wires.
    logic [1:0] forward_src_a_le2;
    logic [1:0] forward_src_b_le2;
    logic       flush_le;
    
    // Memory Stage ------------------------------------------------------- //

    // Pipelined Data.
    logic zero_lm;
    logic [31:0] alu_out_lm32;
    logic [31:0] write_data_lm32;
    logic [4:0] dst_reg_addr_lm5;
    logic [31:0] pc_branch_lm32;

    // Pipelined Controls.
    logic enable_wreg_lm;
    logic mem_to_reg_lm;
    logic enable_wmem_lm;
    //logic branch_lm;
    logic pc_j_lm;

    // Writeback Stage ---------------------------------------------------- //

    // Pipelined Data.
    logic [31:0] alu_out_lwb32;
    logic [31:0] read_data_lwb32;
    logic [4:0] dst_reg_addr_lwb5;

    // Pipelined Controls.
    logic enable_wreg_lwb;
    logic mem_to_reg_lwb;
    
    // Stage Wires.
    logic [31:0] res_lwb32;

    // -------------------------------------------------------------------- //
    // Hazard Unit -------------------------------------------------------- //
    // -------------------------------------------------------------------- //

    logic is_hazy_l;
    hazy_unit hu(
        // INPUTS
        .branch_id(branch_i)
        ,.mem_to_reg_ie(mem_to_reg_le)
        ,.enable_wreg_ie(enable_wreg_le)
        ,.mem_to_reg_im(mem_to_reg_lm)
        ,.enable_wreg_im(enable_wreg_lm)
        ,.enable_wreg_iwb(enable_wreg_lwb)

        ,.rs_id5(instr_ld32[25:21])
        ,.rt_id5(instr_ld32[20:16])

        ,.rs_ie5(rs_le5)
        ,.rt_ie5(rt_le5)

        ,.dst_reg_addr_ie5(dst_reg_addr_le5)
        ,.dst_reg_addr_im5(dst_reg_addr_lm5)
        ,.dst_reg_addr_iwb5(dst_reg_addr_lwb5)

        // OUTPUTS
        ,.is_hazy_o(is_hazy_l)
        ,.forward_rd1_o(forward_rd1_ld)
        ,.forward_rd2_o(forward_rd2_ld)
        ,.forward_src_a_o2(forward_src_a_le2)
        ,.forward_src_b_o2(forward_src_b_le2)
    );

    // -------------------------------------------------------------------- //
    // Fetch Stage -------------------------------------------------------- //
    // -------------------------------------------------------------------- //
    
    // FIXME: need to implement flush to handle jumps.
    // NOTE: instr_i32 is instr_lf32;
    // NOTE: We should not decode the instruction prior to the Decode Stage.


    // Stall logic for LW hazard solution. 
    //assign lw_stall_lf = ((instr_ld32[25:21] === rt_le5) || (instr_ld32[20:16] === rt_le5)) && mem_to_reg_le;
    assign stall_lf = is_hazy_l;
    assign stall_ld = is_hazy_l;
    assign flush_le = is_hazy_l;

    flopenr #(32) pc_reg(clk_i, reset_i, ~stall_lf, pc_next_lf32, pc_lf32);

    // Next PC logic.
    adder pc_add1(pc_lf32, 32'b100, pc_plus4_lf32);

    // FIXME: these branch muxes definitly have some errors.
    //        how will pc_plus4_lf32 be in sync with MEM stage if
    //        if we don't propagate it all the way to MEM stage and send it 
    //        back to FETCH stage at the same time as the rest of the 
    //        signals/data?
    mux2 #(32) pc_br_mux(pc_plus4_lf32, pc_branch_ld32, pc_beq_i,
                         pc_next_br_lf32);

    // TODO: make sure this also goes here.
    // FIXME: instr_i32 is not valid when branch is to be taken i.e. at MEM
    //        stage. Might have to propagate to MEM stage and then send back?
    mux2 #(32) pc_mux(pc_next_br_lf32, { pc_plus4_lf32[31:28],
                                         instr_i32[25:0], 2'b00 },
                      pc_j_lm, pc_next_lf32); 

    assign pc_o32 = pc_lf32;

    // Stage Transition: FETCH -> DECODE.
    if_id_flopenr #(32) fd_flopenr(
        .clk_i(clk_i)
        ,.reset_i(reset_i)
        ,.flush_i(pc_beq_i)
        ,.en_i(~stall_ld)
        
        // FETCH
        ,.instr_if32(instr_i32)
        ,.pc_plus4_if32(pc_plus4_lf32)
        //,.enable_wreg_if(enable_wreg_i)
        //,.mem_to_reg_if(mem_to_reg_i)
        //,.enable_wmem_if(enable_wmem_i)

        // DECODE
        ,.instr_od32(instr_ld32)
        ,.pc_plus4_od32(pc_plus4_ld32)
        //,.enable_wreg_od(enable_wreg_ld)
        //,.mem_to_reg_od(mem_to_reg_ld)
        //,.enable_wmem_od(enable_wmem_ld)
    );

    // -------------------------------------------------------------------- //
    // Decode Stage ------------------------------------------------------- //
    // -------------------------------------------------------------------- //

    // NOTE: After this stage all input controls are D stage type controls.
    //      e.g. enable_wreg_i === enable_wreg_ld

    // Hazard solution for handling control hazard.
    assign branch_o = branch_i;
    assign zero_o = forwarding_rd1_ld32 == forwarding_rd2_ld32;


    // Handle RAW for beq args.
    mux2 #(32) forward_rd1_mux(rd1_ld32, alu_out_lm32, forward_rd1_ld,
                               forwarding_rd1_ld32
                               );
    mux2 #(32) forward_rd2_mux(rd2_ld32, alu_out_lm32, forward_rd2_ld,
                               forwarding_rd2_ld32
                               );
    
    // Hazard Detection logic.
    /*
    assign forward_rd1_ld = (instr_ld32[25:21] != 0) && (instr_ld32[25:21] == dst_reg_addr_lm5) && enable_wreg_lm;
    assign forward_rd2_ld = (instr_ld32[20:16] != 0) && (instr_ld32[20:16] == dst_reg_addr_lm5) && enable_wreg_lm;

    assign branch_stall_ld = branch_i && enable_wreg_le
    && (dst_reg_addr_le5 == instr_ld32[25:21] || dst_reg_addr_le5 == instr_ld32[20:16])
    || branch_i && mem_to_reg_lm 
    && (dst_reg_addr_lm5 == instr_ld32[25:21] || dst_reg_addr_lm5 == instr_ld32[20:16]);
    */


    // PC branch logic.
    sl2 immsh(sign_imm_ld32, sign_immsh_ld32);
    adder pc_add2(pc_plus4_ld32, sign_immsh_ld32, pc_branch_ld32);
    

    // Register file logic.
    // NOTE: write back is done at WB stage - and read is done at DECODE 
    //       stage.
    reg_file rf(clk_i, enable_wreg_lwb, instr_ld32[25:21], instr_ld32[20:16],
                dst_reg_addr_lwb5, res_lwb32, rd1_ld32, rd2_ld32);

    // Extension logic.
    sign_ext se(instr_ld32[15:0], sign_imm_ld32);
    sign_ext #(5) se2(instr_ld32[10:6], se_shamt_ld32);


    // Decode Control Wiring.
    assign op_o6 = instr_ld32[31:26];
    assign funct_o6 = instr_ld32[5:0];

    // Stage Transition: DECODE -> EXECUTE.
    id_ex_flopr #(32) de_flopr (
        .clk_i(clk_i)
        ,.reset_i(reset_i)
        ,.flush_i(flush_le)

        // DECODE
        ,.funct_id6(instr_ld32[5:0])
        ,.rd1_id32(rd1_ld32)
        ,.rd2_id32(rd2_ld32)
        ,.rs_id5(instr_ld32[25:21])
        ,.rt_id5(instr_ld32[20:16])
        ,.rd_id5(instr_ld32[15:11])
        ,.sign_imm_id32(sign_imm_ld32)
        ,.se_shamt_id32(se_shamt_ld32)
        ,.pc_plus4_id32(pc_plus4_ld32)

        ,.enable_wreg_id(enable_wreg_i)
        ,.mem_to_reg_id(mem_to_reg_i)
        ,.enable_wmem_id(enable_wmem_i)
        ,.branch_id(branch_i)
        ,.pc_j_id(pc_j_i)
        ,.alu_alt_ctrl_id2(alu_alt_ctrl_i2)
        ,.b_alu_input_id(b_alu_input_i)
        ,.apply_shift_id(apply_shift_i)
        ,.reg_dst_rtrd_id(reg_dst_rtrd_i)

        // EXECUTE
        ,.funct_oe6(funct_le6)
        ,.rd1_oe32(rd1_le32)
        ,.rd2_oe32(rd2_le32)
        ,.rs_oe5(rs_le5)
        ,.rt_oe5(rt_le5)
        ,.rd_oe5(rd_le5)
        ,.sign_imm_oe32(sign_imm_le32)
        ,.se_shamt_oe32(se_shamt_le32)
        ,.pc_plus4_oe32(pc_plus4_le32)

        ,.enable_wreg_oe(enable_wreg_le)
        ,.mem_to_reg_oe(mem_to_reg_le)
        ,.enable_wmem_oe(enable_wmem_le)
        ,.branch_oe(branch_le)
        ,.pc_j_oe(pc_j_le)
        ,.alu_alt_ctrl_oe2(alu_alt_ctrl_le2)
        ,.b_alu_input_oe(b_alu_input_le)
        ,.apply_shift_oe(apply_shift_le)
        ,.reg_dst_rtrd_oe(reg_dst_rtrd_le)
    );

    // -------------------------------------------------------------------- //
    // Execute Stage ------------------------------------------------------ //
    // -------------------------------------------------------------------- //


    // Forwarding logic for RAW hazard solution.
    logic [31:0] forwarding_src_a_le32;
    logic [31:0] forwarding_src_b_le32;
    mux4 #(32) forward_a_mux(rd1_le32,
                             res_lwb32, 
                             alu_out_lm32, 
                             alu_out_lm32,
                             forward_src_a_le2,
                             forwarding_src_a_le32
                         );
    mux4 #(32) foward_b_mux(rd2_le32,
                            res_lwb32,
                            alu_out_lm32,
                            alu_out_lm32,
                            forward_src_b_le2,
                            forwarding_src_b_le32
                         );

    // Hazard Detection Unit.
    /*
    always_comb 
        if (rs_le5 != 0 && rs_le5 == dst_reg_addr_lm5 && enable_wreg_lm) 
            forward_src_a_le = 2'b10;

        else if (rs_le5 != 0 && rs_le5 == dst_reg_addr_lwb5 && enable_wreg_lwb)
            forward_src_a_le = 2'b01;

        else 
            forward_src_a_le = 2'b00;

    always_comb 
        if (rt_le5 != 0 && rt_le5 == dst_reg_addr_lm5 && enable_wreg_lm)
            forward_src_b_le = 2'b10;

        else if (rt_le5 != 0 && rt_le5 == dst_reg_addr_lwb5 && enable_wreg_lwb)
            forward_src_b_le = 2'b01;

        else 
            forward_src_b_le = 2'b00;
    */

    assign write_data_le32 = forwarding_src_b_le32;
 
    mux2 #(5) dst_reg_mux(rt_le5, rd_le5,
                     reg_dst_rtrd_le, dst_reg_addr_le5);
                 

    // ALU input selects.
    mux4 #(32) src_b_mux(write_data_le32, sign_imm_le32, se_shamt_le32,
                         se_shamt_le32,
                         { apply_shift_le, b_alu_input_le }, src_b_le32);
    mux2 #(32) src_a_mux(forwarding_src_a_le32, write_data_le32, 
                         apply_shift_le,
                         src_a_le32);

    // ALU logic.
    alu alu(
        .a_i32(src_a_le32)
        ,.b_i32(src_b_le32)
        ,.funct_i6(funct_le6)
        ,.alt_ctrl_i2(alu_alt_ctrl_le2)
        ,.y_o32(alu_out_le32)
        ,.zero_o(zero_le));

    // Stage Transition: EXECUTE -> MEM.
    ex_mem_flopr #(32) em_flopr(
        .clk_i(clk_i)
        ,.reset_i(reset_i)

        // EXECUTE
        ,.zero_ie(zero_le)
        ,.alu_out_ie32(alu_out_le32)
        ,.write_data_ie32(write_data_le32)
        ,.dst_reg_addr_ie5(dst_reg_addr_le5)
        ,.pc_branch_ie32(pc_branch_le32)

        ,.enable_wreg_ie(enable_wreg_le)
        ,.mem_to_reg_ie(mem_to_reg_le)
        ,.enable_wmem_ie(enable_wmem_le)
        ,.branch_ie(branch_le)
        ,.pc_j_ie(pc_j_le)

        // MEM
        ,.zero_om(zero_lm)
        ,.alu_out_om32(alu_out_lm32)
        ,.write_data_om32(write_data_lm32)
        ,.dst_reg_addr_om5(dst_reg_addr_lm5)
        ,.pc_branch_om32(pc_branch_lm32)

        ,.enable_wreg_om(enable_wreg_lm)
        ,.mem_to_reg_om(mem_to_reg_lm)
        ,.enable_wmem_om(enable_wmem_lm)
        ,.branch_om(branch_lm)
        ,.pc_j_om(pc_j_lm)
    );

    // -------------------------------------------------------------------- //
    // Memory Stage ------------------------------------------------------- //
    // -------------------------------------------------------------------- //

    // NOTE: read_data_i32 is read_data_im32.
    
    assign enable_wmem_o = enable_wmem_lm;
    assign alu_out_o32 = alu_out_lm32;
    assign write_data_o32 = write_data_lm32;
    //assign branch_o = branch_lm;

    // Stage Transition: MEM -> WB.
    mem_wb_flopr #(32) mem_wb_flopr(
        .clk_i(clk_i)
        ,.reset_i(reset_i)

        // MEM
        ,.alu_out_im32(alu_out_lm32)
        ,.read_data_im32(read_data_i32)
        ,.dst_reg_addr_im5(dst_reg_addr_lm5)

        ,.enable_wreg_im(enable_wreg_lm)
        ,.mem_to_reg_im(mem_to_reg_lm)

        // WB
        ,.alu_out_owb32(alu_out_lwb32)
        ,.read_data_owb32(read_data_lwb32)
        ,.dst_reg_addr_owb5(dst_reg_addr_lwb5)

        ,.enable_wreg_owb(enable_wreg_lwb)
        ,.mem_to_reg_owb(mem_to_reg_lwb)
    );

    // -------------------------------------------------------------------- //
    // Writeback Stage ---------------------------------------------------- //
    // -------------------------------------------------------------------- //

    mux2 #(32) res_mux(alu_out_lwb32, read_data_lwb32, mem_to_reg_lwb,
                       res_lwb32);



    // TODO: remove when done with op implementations.
    always @(posedge clk_i)
    begin
        // FIXME: BEQ is causing issues with pipeline hazards.
        $display("\n\n");
        $display("instr_ld32: %b", instr_ld32);
        case(instr_ld32[31:26])
            `INSTR_RTYPE: $display("RTYPE"); 
            `INSTR_LW:    $display("LW");    
            `INSTR_SW:    $display("SW");    
            `INSTR_BEQ:   $display("BEQ");
            `INSTR_BNE:   $display("BNE");  
            `INSTR_J:     $display("J");     
            `INSTR_ADDI:  $display("ADDI"); 
            `INSTR_SLTI:  $display("SLTI");  
            default: $display("What you doin bruh!!?");
        endcase

        if (instr_ld32[5:0] == `FUNCT6_SLL && instr_ld32[31:26] == `INSTR_RTYPE)
        begin
            $display("INSTR_SLL");
            $display("src_a_le32 value: ", src_a_le32);
            $display("src_a_le32 value binary: %b", src_a_le32);
            $display("src_b_le32 value: ", src_b_le32);
            $display("src_b_le32 value: binary: %b", src_b_le32);
            $display("se_shamt_le32: ", se_shamt_le32);
            $display("alu_out_o32: ", alu_out_o32);
            $display("res_lwb32: ", res_lwb32);
            $display("res_lwb32: binary: %b", res_lwb32);
            $display("write_data_o32: ", write_data_o32);
            $display("write_data_o32: binary: %b", write_data_o32);
            $display("apply_shift_le: ", apply_shift_le);
            $display("enable_wreg_lwb: ", enable_wreg_lwb);
            $display("dst_reg_addr_lwb5 ", dst_reg_addr_lwb5);
        end

        else if (instr_ld32[5:0] == `FUNCT6_SRL && instr_ld32[31:26] == `INSTR_RTYPE)
        begin
            $display("INSTR_SRL");
            $display("src_a_le32 value: ", src_a_le32);
            $display("src_a_le32 value binary: %b", src_a_le32);
            $display("src_b_le32 value: ", src_b_le32);
            $display("src_b_le32 value: binary: %b", src_b_le32);
            $display("se_shamt_le32: ", se_shamt_le32);
            $display("alu_out_o32: ", alu_out_o32);
            $display("res_lwb32: ", res_lwb32);
            $display("res_lwb32: binary: %b", res_lwb32);
            $display("write_data_o32: ", write_data_o32);
            $display("write_data_o32: binary: %b", write_data_o32);
            $display("apply_shift_le: ", apply_shift_le);
            $display("enable_wreg_lwb: ", enable_wreg_lwb);
            $display("dst_reg_addr_lwb5 ", dst_reg_addr_lwb5);
        end

        else if (instr_ld32[31:26] == `INSTR_SW)
        begin
            $display("INSTR_SW");
            $display("src_a_le32 value: ", src_a_le32);
            $display("src_a_le32 value binary: %b", src_a_le32);
            $display("src_b_le32 value: ", src_b_le32);
            $display("src_b_le32 value: binary: %b", src_b_le32);
            $display("se_shamt_le32: ", se_shamt_le32);
            $display("alu_out_o32: ", alu_out_o32);
            $display("res_lwb32: ", res_lwb32);
            $display("res_lwb32: binary: %b", res_lwb32);
            $display("write_data_o32: ", write_data_o32);
            $display("write_data_o32: binary: %b", write_data_o32);
            $display("apply_shift_le: ", apply_shift_le);
            $display("enable_wreg_lwb: ", enable_wreg_lwb);
            $display("dst_reg_addr_lwb5 ", dst_reg_addr_lwb5);
        end

        else if (instr_ld32[31:26] == `INSTR_LW)
        begin
            $display("INSTR_LW");
            $display("src_a_le32 value: ", src_a_le32);
            $display("src_a_le32 value binary: %b", src_a_le32);
            $display("src_b_le32 value: ", src_b_le32);
            $display("src_b_le32 value: binary: %b", src_b_le32);
            $display("se_shamt_le32: ", se_shamt_le32);
            $display("alu_out_o32: ", alu_out_o32);
            $display("res_lwb32: ", res_lwb32);
            $display("res_lwb32: binary: %b", res_lwb32);
            $display("write_data_o32: ", write_data_o32);
            $display("write_data_o32: binary: %b", write_data_o32);
            $display("apply_shift_le: ", apply_shift_le);
            $display("enable_wreg_lwb: ", enable_wreg_lwb);
            $display("dst_reg_addr_lwb5 ", dst_reg_addr_lwb5);
        end
        else if (instr_ld32[31:26] == `INSTR_J)
            $display("JUMPING BRUH");
        else
        begin
            $display("NO MATCH FOUND");
            $display("INSTR IS: ");
            case (instr_ld32[31:26])
                `INSTR_ADDI: $display("INSTR_ADDI");
                `INSTR_BEQ: $display("INSTR_BEQ");
                `INSTR_BNE: $display("INSTR_BNE");
                default: $display("NO CASE");
            endcase
        end
    end
endmodule
