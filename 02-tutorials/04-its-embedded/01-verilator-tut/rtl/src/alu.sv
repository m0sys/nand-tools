typedef enum logic[1:0] {
    add = 2'h1,
    sub = 2'h2,
    nop = 2'h0
} operation_t /* verilator public */;

module alu #(parameter WIDTH=6) (
    input  clk
    ,input rst

    ,input operation_t op_in
    ,input [WIDTH-1:0] a_in
    ,input [WIDTH-1:0] b_in
    ,input             in_valid

    ,output logic [WIDTH-1:0] out
    ,output logic             out_valid
    );
    operation_t op_in_r;
    logic [WIDTH-1:0] a_in_r;
    logic [WIDTH-1:0] b_in_r;
    logic             in_valid_r;
    logic [WIDTH-1:0] res;

    // Stage 1: Register all inputs.
    always_ff @(posedge clk, posedge rst) 
    begin
        if (rst) 
        begin
            op_in_r <= '0;
            a_in_r <= '0;
            b_in_r <= '0;
            in_valid_r <= '0;
        end

        else
        begin
            op_in_r <= op_in;
            a_in_r <= a_in;
            b_in_r <= b_in;
            in_valid_r <= in_valid;
        end
    end

    // Stage 2: Compute the result.
    always_comb
    begin
        res = '0;
        if (in_valid_r)
        begin
            case (op_in_r)
                add: res = a_in_r + b_in_r;
                sub: res = a_in_r + (~b_in_r +1'b1);
                default: res = '0;
            endcase
        end
    end

    // Register output.
    always_ff @(posedge clk, posedge rst)
    begin
        if (rst)
        begin
            out <= '0;
            out_valid <= '0;
        end

        else
        begin
            out <= res;
            out_valid <= in_valid_r;
        end
    end

endmodule
