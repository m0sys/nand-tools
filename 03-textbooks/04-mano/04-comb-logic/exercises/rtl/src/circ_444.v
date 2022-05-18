// Behaviour desc of one Byte ALU.

module circ_444 (
    // OUTPUTS
    output reg [7:0] y_o8

    // INPUTS
    ,input [7:0] A_i8
    ,input [7:0] B_i8
    ,input [2:0] sel_i3
    );

    // HACK THE PLANET.
    always  @(A_i8, B_i8, sel_i3) begin
        case (sel_i3)
            3'b000: y_o8 = 8'b0;
            3'b001: y_o8 = A_i8 & B_i8;
            3'b010: y_o8 = A_i8 | B_i8;
            3'b011: y_o8 = A_i8 ^ B_i8;
            3'b100: y_o8 = ~A_i8;
            3'b101: y_o8 = A_i8 - B_i8;
            3'b110: y_o8 = A_i8 + B_i8;
            3'b111: y_o8 = 8'hFF;
        endcase
    end
endmodule

