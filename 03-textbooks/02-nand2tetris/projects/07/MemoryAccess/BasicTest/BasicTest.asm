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

(END)
@END
0;JMP
