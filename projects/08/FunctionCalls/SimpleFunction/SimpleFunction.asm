// SimpleFunction.vm: [start_func]: SimpleFunction.test
(SimpleFunction.SimpleFunction.test)
// push constant 0
@0
D=A
// [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// [end_push_logic]
// pop local 0
// [start_pop_logic]
@SP
M=M-1
A=M
D=M
// [end_pop_logic]
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
// push constant 0
@0
D=A
// [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// [end_push_logic]
// pop local 1
// [start_pop_logic]
@SP
M=M-1
A=M
D=M
// [end_pop_logic]
@R14
M=D
@1
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
// SimpleFunction.vm: [end_func]: SimpleFunction.test
// push local 0
@LCL
D=M
@0
A=D+A
D=M
// [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// [end_push_logic]
// [end_write_push_pop]

// push local 1
@LCL
D=M
@1
A=D+A
D=M
// [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// [end_push_logic]
// [end_write_push_pop]

// add
// [start_pop_logic]
@SP
M=M-1
A=M
D=M
// [end_pop_logic]
@R13
M=D
// [start_pop_logic]
@SP
M=M-1
A=M
D=M
// [end_pop_logic]
@R13
D=D+M
// [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// [end_push_logic]
// [end_write_arith]

// not
// [start_pop_logic]
@SP
M=M-1
A=M
D=M
// [end_pop_logic]
D=!D
// [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// [end_push_logic]
// push argument 0
@ARG
D=M
@0
A=D+A
D=M
// [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// [end_push_logic]
// [end_write_push_pop]

// add
// [start_pop_logic]
@SP
M=M-1
A=M
D=M
// [end_pop_logic]
@R13
M=D
// [start_pop_logic]
@SP
M=M-1
A=M
D=M
// [end_pop_logic]
@R13
D=D+M
// [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// [end_push_logic]
// [end_write_arith]

// push argument 1
@ARG
D=M
@1
A=D+A
D=M
// [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// [end_push_logic]
// [end_write_push_pop]

// sub
// [start_pop_logic]
@SP
M=M-1
A=M
D=M
// [end_pop_logic]
@R13
M=D
// [start_pop_logic]
@SP
M=M-1
A=M
D=M
// [end_pop_logic]
@R13
D=D-M
// [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// [end_push_logic]
// [end_write_arith]

// [start_return]
@LCL
D=M
@R13
M=D
@5
D=A
@R13
D=M-D
@R14
M=D
@ARG
D=M
@R15
M=D
// [start_pop_logic]
@SP
M=M-1
A=M
D=M
// [end_pop_logic]
@R15
A=M
M=D
@ARG
D=M
D=D+1
@SP
M=D
@R13
D=M-1
A=D
D=M
@THAT
M=D
@2
D=A
@R13
D=M-D
A=D
D=M
@THIS
M=D
@3
D=A
@R13
D=M-D
A=D
D=M
@ARG
M=D
@4
D=A
@R13
D=M-D
A=D
D=M
@LCL
M=D
@R14
D=M
A=D
0;JMP
// [end_return]
(END)
@END
0;JMP
