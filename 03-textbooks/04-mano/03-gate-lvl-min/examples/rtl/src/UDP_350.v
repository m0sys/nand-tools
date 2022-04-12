// Verilog model: User-defined Primitive.
primitive UDP_350(
    // OUTPUTS
    output D

    // INPUTS
    ,input A
    ,input B
    ,input C
    );
    // Truth table: D(A, B, C) = SOP(0, 2, 4, 6, 7)
    table
    //  A   B   C   :   D
        0   0   0   :   1;
        0   0   1   :   0;
        0   1   0   :   1;
        0   1   1   :   0;
        1   0   0   :   1;
        1   0   1   :   0;
        1   1   0   :   1;
        1   1   1   :   1;
    endtable 
endprimitive
