// Desc of 2x4 decoder using for loop stmt.

module decoder (
    // OUTPUTS
    output reg [3:0] Y

    // INPUTS
    ,input [1:0] IN
    );

    integer k;
    always @(IN)
        for (k = 0; k < 4; k = k + 1)
            if (IN == k) Y[k] = 1;
            else Y[k] = 0;
endmodule
