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

// asm_coder.cc (234): pop pointer 1
// asm_coder.cc (574): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (579): [end_pop_logic]
@THAT
M=D
// asm_coder.cc (170): [end_write_push_pop]

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
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (234): pop that 0
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
@THAT
D=M+D
@R15
M=D
@R14
D=M
@R15
A=M
M=D
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (176): push constant 1
@1
D=A
// asm_coder.cc (563): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (569): [end_push_logic]
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (234): pop that 1
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
@THAT
D=M+D
@R15
M=D
@R14
D=M
@R15
A=M
M=D
// asm_coder.cc (170): [end_write_push_pop]

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

// asm_coder.cc (176): push constant 2
@2
D=A
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

// asm_coder.cc (234): pop argument 0
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
@ARG
D=M+D
@R15
M=D
@R14
D=M
@R15
A=M
M=D
// asm_coder.cc (170): [end_write_push_pop]

(MAIN_LOOP_START)
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

// asm_coder.cc (574): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (579): [end_pop_logic]
@COMPUTE_ELEMENT
D;JNE
@END_PROGRAM
0;JMP
(COMPUTE_ELEMENT)
// asm_coder.cc (176): push that 0
@THAT
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

// asm_coder.cc (176): push that 1
@THAT
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

// asm_coder.cc (234): pop that 2
// asm_coder.cc (574): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (579): [end_pop_logic]
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
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (176): push pointer 1
@THAT
D=M
// asm_coder.cc (563): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (569): [end_push_logic]
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (176): push constant 1
@1
D=A
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

// asm_coder.cc (234): pop pointer 1
// asm_coder.cc (574): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (579): [end_pop_logic]
@THAT
M=D
// asm_coder.cc (170): [end_write_push_pop]

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

// asm_coder.cc (176): push constant 1
@1
D=A
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

// asm_coder.cc (234): pop argument 0
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
@ARG
D=M+D
@R15
M=D
@R14
D=M
@R15
A=M
M=D
// asm_coder.cc (170): [end_write_push_pop]

@MAIN_LOOP_START
0;JMP
(END_PROGRAM)
(END)
@END
0;JMP
