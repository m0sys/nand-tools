// asm_coder.cc (327): SimpleFunction.vm: [start_func]: SimpleFunction.test
(SimpleFunction.test)
// asm_coder.cc (176): push constant 0
@0
D=A
// asm_coder.cc (563): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (569): [end_push_logic]
// asm_coder.cc (234): pop local 0
// asm_coder.cc (574): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (579): [end_pop_logic]
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
// asm_coder.cc (176): push constant 0
@0
D=A
// asm_coder.cc (563): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (569): [end_push_logic]
// asm_coder.cc (234): pop local 1
// asm_coder.cc (574): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (579): [end_pop_logic]
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
// asm_coder.cc (337): SimpleFunction.vm: [end_func]: SimpleFunction.test
// asm_coder.cc (176): push local 0
@LCL
D=M
@0
A=D+A
D=M
// asm_coder.cc (563): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (569): [end_push_logic]
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (176): push local 1
@LCL
D=M
@1
A=D+A
D=M
// asm_coder.cc (563): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (569): [end_push_logic]
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (34): add
// asm_coder.cc (574): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (579): [end_pop_logic]
@R13
M=D
// asm_coder.cc (574): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (579): [end_pop_logic]
@R13
D=D+M
// asm_coder.cc (563): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (569): [end_push_logic]
// asm_coder.cc (114): [end_write_arith]

// asm_coder.cc (34): not
// asm_coder.cc (574): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (579): [end_pop_logic]
D=!D
// asm_coder.cc (563): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (569): [end_push_logic]
// asm_coder.cc (176): push argument 0
@ARG
D=M
@0
A=D+A
D=M
// asm_coder.cc (563): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (569): [end_push_logic]
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (34): add
// asm_coder.cc (574): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (579): [end_pop_logic]
@R13
M=D
// asm_coder.cc (574): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (579): [end_pop_logic]
@R13
D=D+M
// asm_coder.cc (563): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (569): [end_push_logic]
// asm_coder.cc (114): [end_write_arith]

// asm_coder.cc (176): push argument 1
@ARG
D=M
@1
A=D+A
D=M
// asm_coder.cc (563): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (569): [end_push_logic]
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (34): sub
// asm_coder.cc (574): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (579): [end_pop_logic]
@R13
M=D
// asm_coder.cc (574): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (579): [end_pop_logic]
@R13
D=D-M
// asm_coder.cc (563): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (569): [end_push_logic]
// asm_coder.cc (114): [end_write_arith]

// asm_coder.cc (429): [start_return]
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
// asm_coder.cc (574): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (579): [end_pop_logic]
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
// asm_coder.cc (512): [end_return]
(END)
@END
0;JMP
