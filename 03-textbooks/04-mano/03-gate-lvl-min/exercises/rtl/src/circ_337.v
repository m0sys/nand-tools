`timescale 1ns / 1ps
// 4bit majority circuit.

primitive circ_337(
    // OUTPUTS
    output M
    
    // INPUTS
    ,input w
    ,input x
    ,input y
    ,input z
    );

    // Truth Table: M(w, x, y, z) = SOP(7, 11, 13, 14, 15)
    table
    //  w   x   y   z   :   D
        0   0   0   0   :   0;
        0   0   0   1   :   0;
        0   0   1   0   :   0;
        0   0   1   1   :   0;
        0   1   0   0   :   0;
        0   1   0   1   :   0;
        0   1   1   0   :   0;
        0   1   1   1   :   1;
        1   0   0   0   :   0;
        1   0   0   1   :   0;
        1   0   1   0   :   0;
        1   0   1   1   :   1;
        1   1   0   0   :   0;
        1   1   0   1   :   1;
        1   1   1   0   :   1;
        1   1   1   1   :   1;
    endtable
endprimitive
