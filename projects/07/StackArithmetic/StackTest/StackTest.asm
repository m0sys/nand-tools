// push constant 17
@17
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// push constant 17
@17
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// eq
// [eq_start]
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

// [start]: pop_logic
@SP
M=M-1
A=M
D=M
// [end]: pop_logic
@StackTest.EQ0
D;JEQ
D=0
@StackTest.EQ0.CONTINUE
0;JMP
(StackTest.EQ0)
D=-1
@StackTest.EQ0.CONTINUE
0;JMP
(StackTest.EQ0.CONTINUE)
// [eq_end]
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_arith]

// push constant 17
@17
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// push constant 16
@16
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// eq
// [eq_start]
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

// [start]: pop_logic
@SP
M=M-1
A=M
D=M
// [end]: pop_logic
@StackTest.EQ1
D;JEQ
D=0
@StackTest.EQ1.CONTINUE
0;JMP
(StackTest.EQ1)
D=-1
@StackTest.EQ1.CONTINUE
0;JMP
(StackTest.EQ1.CONTINUE)
// [eq_end]
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_arith]

// push constant 16
@16
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// push constant 17
@17
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// eq
// [eq_start]
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

// [start]: pop_logic
@SP
M=M-1
A=M
D=M
// [end]: pop_logic
@StackTest.EQ2
D;JEQ
D=0
@StackTest.EQ2.CONTINUE
0;JMP
(StackTest.EQ2)
D=-1
@StackTest.EQ2.CONTINUE
0;JMP
(StackTest.EQ2.CONTINUE)
// [eq_end]
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_arith]

// push constant 892
@892
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// push constant 891
@891
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// lt
// [lt_start]
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

// [start]: pop_logic
@SP
M=M-1
A=M
D=M
// [end]: pop_logic
@StackTest.LT0
D;JLT
D=0
@StackTest.LT0.CONTINUE
0;JMP
(StackTest.LT0)
D=-1
@StackTest.LT0.CONTINUE
0;JMP
(StackTest.LT0.CONTINUE)
// [lt_end]
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_arith]

// push constant 891
@891
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// push constant 892
@892
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// lt
// [lt_start]
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

// [start]: pop_logic
@SP
M=M-1
A=M
D=M
// [end]: pop_logic
@StackTest.LT1
D;JLT
D=0
@StackTest.LT1.CONTINUE
0;JMP
(StackTest.LT1)
D=-1
@StackTest.LT1.CONTINUE
0;JMP
(StackTest.LT1.CONTINUE)
// [lt_end]
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_arith]

// push constant 891
@891
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// push constant 891
@891
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// lt
// [lt_start]
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

// [start]: pop_logic
@SP
M=M-1
A=M
D=M
// [end]: pop_logic
@StackTest.LT2
D;JLT
D=0
@StackTest.LT2.CONTINUE
0;JMP
(StackTest.LT2)
D=-1
@StackTest.LT2.CONTINUE
0;JMP
(StackTest.LT2.CONTINUE)
// [lt_end]
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_arith]

// push constant 32767
@32767
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// push constant 32766
@32766
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// gt
// [gt_start]
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

// [start]: pop_logic
@SP
M=M-1
A=M
D=M
// [end]: pop_logic
@StackTest.GT0
D;JGT
D=0
@StackTest.GT0.CONTINUE
0;JMP
(StackTest.GT0)
D=-1
@StackTest.GT0.CONTINUE
0;JMP
(StackTest.GT0.CONTINUE)
// [gt_end]
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_arith]

// push constant 32766
@32766
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// push constant 32767
@32767
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// gt
// [gt_start]
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

// [start]: pop_logic
@SP
M=M-1
A=M
D=M
// [end]: pop_logic
@StackTest.GT1
D;JGT
D=0
@StackTest.GT1.CONTINUE
0;JMP
(StackTest.GT1)
D=-1
@StackTest.GT1.CONTINUE
0;JMP
(StackTest.GT1.CONTINUE)
// [gt_end]
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_arith]

// push constant 32766
@32766
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// push constant 32766
@32766
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// gt
// [gt_start]
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

// [start]: pop_logic
@SP
M=M-1
A=M
D=M
// [end]: pop_logic
@StackTest.GT2
D;JGT
D=0
@StackTest.GT2.CONTINUE
0;JMP
(StackTest.GT2)
D=-1
@StackTest.GT2.CONTINUE
0;JMP
(StackTest.GT2.CONTINUE)
// [gt_end]
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_arith]

// push constant 57
@57
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// push constant 31
@31
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// push constant 53
@53
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

// push constant 112
@112
D=A
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

// neg
// [start]: pop_logic
@SP
M=M-1
A=M
D=M
// [end]: pop_logic
D=-D
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// and
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
D=D&M
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_arith]

// push constant 82
@82
D=A
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_push_pop]

// or
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
D=D|M
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
// [end write_arith]

// not
// [start]: pop_logic
@SP
M=M-1
A=M
D=M
// [end]: pop_logic
D=!D
// [start]: push_logic
@SP
A=M
M=D
@SP
M=M+1
// [end]: push_logic
(END)
@END
0;JMP
