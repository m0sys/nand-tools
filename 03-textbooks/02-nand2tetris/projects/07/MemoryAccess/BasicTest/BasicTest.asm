// push constant 10
@10
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// pop local 0
// [start]: pop_logic
@SP
M=M-1
A=M
D=M
// [end]: pop_logic
@R14
M=D
@0
D=A
@LCL
D=M+D
@R15
M=D
@R14
D=M
@R15
A=M
M=D
// [end write_push_pop]

// push constant 21
@21
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// push constant 22
@22
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// pop argument 2
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
@ARG
D=M+D
@R15
M=D
@R14
D=M
@R15
A=M
M=D
// [end write_push_pop]

// pop argument 1
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
@ARG
D=M+D
@R15
M=D
@R14
D=M
@R15
A=M
M=D
// [end write_push_pop]

// push constant 36
@36
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// pop this 6
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

// push constant 42
@42
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// push constant 45
@45
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// pop that 5
// [start]: pop_logic
@SP
M=M-1
A=M
D=M
// [end]: pop_logic
@R14
M=D
@5
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

// pop that 2
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

// push constant 510
@510
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// pop temp 6
// [start]: pop_logic
@SP
M=M-1
A=M
D=M
// [end]: pop_logic
@R14
M=D
@5
D=A
@6
D=D+A
@R15
M=D
@R14
D=M
@R15
A=M
M=D
// [end write_push_pop]

// push local 0
@LCL
D=M
@0
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

// push that 5
@THAT
D=M
@5
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

// push argument 1
@ARG
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

// push this 6
@THIS
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

// push this 6
@THIS
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

// push temp 6
@5
D=A
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
