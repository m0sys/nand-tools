// asm_coder.cc (327): Sys.vm: [start_func]: Sys.init
(Sys.init)
// asm_coder.cc (337): Sys.vm: [end_func]: Sys.init
// asm_coder.cc (176): push constant 4000
@4000
D=A
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (234): pop pointer 0
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
@THIS
M=D
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (176): push constant 5000
@5000
D=A
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (234): pop pointer 1
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
@THAT
M=D
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (349): [start_call]: Sys.main
@Sys.main$ret0
D=A
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
@LCL
D=M
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
@ARG
D=M
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
@THIS
D=M
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
@THAT
D=M
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
@SP
D=M
@ARG
M=D
@5
D=A
@ARG
M=M-D
@0
D=A
@ARG
M=M-D
@SP
D=M
@LCL
M=D
@Sys.main
0;JMP
(Sys.main$ret0)
// asm_coder.cc (408): [end_call]: Sys.main
// asm_coder.cc (234): pop temp 1
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
@R14
M=D
@5
D=A
@1
D=D+A
@R15
M=D
@R14
D=M
@R15
A=M
M=D
// asm_coder.cc (170): [end_write_push_pop]

(Sys.init$LOOP)
@Sys.init$LOOP
0;JMP
// asm_coder.cc (327): Sys.vm: [start_func]: Sys.main
(Sys.main)
// asm_coder.cc (176): push constant 0
@0
D=A
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
// asm_coder.cc (234): pop local 0
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
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
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
// asm_coder.cc (234): pop local 1
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
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
// asm_coder.cc (176): push constant 0
@0
D=A
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
// asm_coder.cc (234): pop local 2
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
@R14
M=D
@2
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
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
// asm_coder.cc (234): pop local 3
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
@R14
M=D
@3
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
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
// asm_coder.cc (234): pop local 4
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
@R14
M=D
@4
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
// asm_coder.cc (337): Sys.vm: [end_func]: Sys.main
// asm_coder.cc (176): push constant 4001
@4001
D=A
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (234): pop pointer 0
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
@THIS
M=D
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (176): push constant 5001
@5001
D=A
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (234): pop pointer 1
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
@THAT
M=D
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (176): push constant 200
@200
D=A
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (234): pop local 1
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
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
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (176): push constant 40
@40
D=A
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (234): pop local 2
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
@R14
M=D
@2
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
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (176): push constant 6
@6
D=A
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (234): pop local 3
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
@R14
M=D
@3
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
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (176): push constant 123
@123
D=A
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (349): [start_call]: Sys.add12
@Sys.add12$ret0
D=A
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
@LCL
D=M
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
@ARG
D=M
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
@THIS
D=M
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
@THAT
D=M
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
@SP
D=M
@ARG
M=D
@5
D=A
@ARG
M=M-D
@1
D=A
@ARG
M=M-D
@SP
D=M
@LCL
M=D
@Sys.add12
0;JMP
(Sys.add12$ret0)
// asm_coder.cc (408): [end_call]: Sys.add12
// asm_coder.cc (234): pop temp 0
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
@R14
M=D
@5
D=A
@0
D=D+A
@R15
M=D
@R14
D=M
@R15
A=M
M=D
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (176): push local 0
@LCL
D=M
@0
A=D+A
D=M
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (176): push local 1
@LCL
D=M
@1
A=D+A
D=M
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (176): push local 2
@LCL
D=M
@2
A=D+A
D=M
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (176): push local 3
@LCL
D=M
@3
A=D+A
D=M
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (176): push local 4
@LCL
D=M
@4
A=D+A
D=M
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (34): add
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
@R13
M=D
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
@R13
D=D+M
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
// asm_coder.cc (114): [end_write_arith]

// asm_coder.cc (34): add
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
@R13
M=D
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
@R13
D=D+M
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
// asm_coder.cc (114): [end_write_arith]

// asm_coder.cc (34): add
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
@R13
M=D
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
@R13
D=D+M
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
// asm_coder.cc (114): [end_write_arith]

// asm_coder.cc (34): add
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
@R13
M=D
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
@R13
D=D+M
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
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
A=D
D=M
@R14
M=D
@ARG
D=M
@R15
M=D
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
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
// asm_coder.cc (521): [end_return]
// asm_coder.cc (327): Sys.vm: [start_func]: Sys.add12
(Sys.add12)
// asm_coder.cc (337): Sys.vm: [end_func]: Sys.add12
// asm_coder.cc (176): push constant 4002
@4002
D=A
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (234): pop pointer 0
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
@THIS
M=D
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (176): push constant 5002
@5002
D=A
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (234): pop pointer 1
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
@THAT
M=D
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (176): push argument 0
@ARG
D=M
@0
A=D+A
D=M
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (176): push constant 12
@12
D=A
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
// asm_coder.cc (170): [end_write_push_pop]

// asm_coder.cc (34): add
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
@R13
M=D
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
@R13
D=D+M
// asm_coder.cc (572): [start_push_logic]
@SP
A=M
M=D
@SP
M=M+1
// asm_coder.cc (578): [end_push_logic]
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
A=D
D=M
@R14
M=D
@ARG
D=M
@R15
M=D
// asm_coder.cc (583): [start_pop_logic]
@SP
M=M-1
A=M
D=M
// asm_coder.cc (588): [end_pop_logic]
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
// asm_coder.cc (521): [end_return]
(END)
@END
0;JMP
