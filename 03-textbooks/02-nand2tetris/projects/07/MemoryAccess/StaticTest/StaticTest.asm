// push constant 111
@111
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// push constant 333
@333
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// push constant 888
@888
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// pop static 8
// [start]: pop_logic
@SP
M=M-1
A=M
D=M
// [end]: pop_logic
@R14
M=D
@8
D=A
D=M+D
@R15
M=D
@R14
D=M
@R15
A=M
M=D
// [end write_push_pop]

// pop static 3
// [start]: pop_logic
@SP
M=M-1
A=M
D=M
// [end]: pop_logic
@R14
M=D
@3
D=A
D=M+D
@R15
M=D
@R14
D=M
@R15
A=M
M=D
// [end write_push_pop]

// pop static 1
// [start]: pop_logic
@SP
M=M-1
A=M
D=M
// [end]: pop_logic
@R14
M=D
@1
D=A
D=M+D
@R15
M=D
@R14
D=M
@R15
A=M
M=D
// [end write_push_pop]

// push static 3
D=M
@3
A=D+A
D=M
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// push static 1
D=M
@1
A=D+A
D=M
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// sub
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
D=D-M
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_arith]

// push static 8
D=M
@8
A=D+A
D=M
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
