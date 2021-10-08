`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/08/2021 09:09:36 AM
// Design Name: 
// Module Name: sevenseg
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module sevenseg(
    input logic [3:0]data,
    input logic [1:0]select,
    output logic [3:0]digits,
    output logic [6:0] segments
    );
    
    // NOTE: basys 3 is active low.
    always_comb
        case (data)
            //                   abc_defg
            0:       segments=7'b000_0001; // "0"
            1:       segments=7'b100_1111; // "1"
            2:       segments=7'b001_0010; // "2"
            3:       segments=7'b000_0110; // "3"
            4:       segments=7'b100_1100; // "4"
            5:       segments=7'b010_0100; // "5"
            6:       segments=7'b010_0000; // "6"
            7:       segments=7'b000_1111; // "7"
            8:       segments=7'b000_0000; // "8"
            9:       segments=7'b000_1100; // "9"
            10:      segments=7'b000_1000; // "A"
            11:      segments=7'b110_0000; // "b"
            12:      segments=7'b011_0001; // "C"
            13:      segments=7'b100_0010; // "d"
            14:      segments=7'b011_0000; // "E"
            15:      segments=7'b011_1000; // "F"
            default: segments=7'b000_0001;
        endcase

    always_comb
    begin
        case (select)
            0:       digits=4'b0111;
            1:       digits=4'b1011;
            2:       digits=4'b1101;
            3:       digits=4'b1110;
            default: digits=4'b0000;
        endcase
    end
endmodule
