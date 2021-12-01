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
@StaticTest.8
M=D
// [end write_push_pop]

// pop static 3
// [start]: pop_logic
@SP
M=M-1
A=M
D=M
// [end]: pop_logic
@StaticTest.3
M=D
// [end write_push_pop]

// pop static 1
// [start]: pop_logic
@SP
M=M-1
A=M
D=M
// [end]: pop_logic
@StaticTest.1
M=D
// [end write_push_pop]

// push static 3
@StaticTest.3
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
@StaticTest.1
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
@StaticTest.8
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
