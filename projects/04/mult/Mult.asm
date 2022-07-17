// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

// Even better than commented pseudo code is python!
// i = 0
// res = 0
// LOOP:
// 	if (i >= R0)
// 		goto STOP
// 	res += R1
//  i++
// STOP:
// 	R2 = res

// i = 0
@i
M=0

// res = 0
@res
M=0

(LOOP)
	// if (i >= R0)
	@i
	D=M
	@R0
	D=D-M
	@STOP
	D;JGE
	// res += R1
	@res
	D=M
	@R1
	D=D+M
	@res
	M=D
	// i++
	@i
	M=M+1
	// goto LOOP
	@LOOP
	0;JMP
(STOP)
	// R2 = res
	@res
	D=M
	@R2
	M=D
(END)
	@END
	0;JMP



