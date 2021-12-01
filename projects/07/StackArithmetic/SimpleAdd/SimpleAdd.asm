// push constant 7
@7
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// push constant 8
@8
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// add
// [start]: pop_logic
@SP
M=M-1
A=M
D=M
// [end]: pop_logic
@R13
M=D
// [start]: pop_logic
@SP
M=M-1
A=M
D=M
// [end]: pop_logic
@R13
D=D+M
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_arith]

(END)
@END
0;JMP
