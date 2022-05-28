// Behavioral desc of Universial 4bit Shift Register (example 6.1 pp284).

module univ_4bit_shift_reg_bh (
    // OUTPUTS
    output reg [3:0] A_par // reg output

    // INPUTS
    ,input     [3:0] I_par // paral input
    ,input           s0
    ,input           s1
    ,input           msb_in // serial input from msb
    ,input           lsb_in // serial input from lsb
    ,input           clk_i
    ,input           rst_i
    );

    always @(posedge clk_i, negedge rst_i)
        if (!rst_i) A_par <= 4'b0000;
        else 
            case ({s1, s0})
                2'b00: A_par <= A_par;               // no change
                2'b01: A_par <= {msb_in, A_par[3:1]}; // rshift
                2'b10: A_par <= {A_par[2:0], lsb_in}; // lshift
                2'b11: A_par <= I_par;                // paral load
            endcase
endmodule
