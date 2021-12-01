// push constant 3030
@3030
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// pop pointer 0
// [start]: pop_logic
@SP
M=M-1
A=M
D=M
// [end]: pop_logic
@THIS
M=D
// [end write_push_pop]

// push constant 3040
@3040
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// pop pointer 1
// [start]: pop_logic
@SP
M=M-1
A=M
D=M
// [end]: pop_logic
@THAT
M=D
// [end write_push_pop]

// push constant 32
@32
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// pop this 2
// [start]: pop_logic
@SP
M=M-1
A=M
D=M
// [end]: pop_logic
@R14
M=D
@2
D=A
@THIS
D=M+D
@R15
M=D
@R14
D=M
@R15
A=M
M=D
// [end write_push_pop]

// push constant 46
@46
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// pop that 6
// [start]: pop_logic
@SP
M=M-1
A=M
D=M
// [end]: pop_logic
@R14
M=D
@6
D=A
@THAT
D=M+D
@R15
M=D
@R14
D=M
@R15
A=M
M=D
// [end write_push_pop]

// push pointer 0
@THIS
D=M
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// push pointer 1
@THAT
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

// push this 2
@THIS
D=M
@2
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

// push that 6
@THAT
D=M
@6
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
