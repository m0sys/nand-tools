(SimpleFunction.test) // (161) 
@0 // (567) 
D=A // (568) 
@SP // (558) 
A=M // (590) 
M=D // (591) 
@SP // (558) 
M=M+1 // (593) 
@SP // (558) 
M=M-1 // (601) 
A=M // (602) 
D=M // (603) 
@R14 // (288) location where popped value is stored
M=D // (289) 
@0 // (567) 
D=A // (568) 
@LCL // (559) 
D=M+D // (305) location where popped val will be stored
@R15 // (573) storing D in R15
M=D // (574) 
@R14 // (575) loading R14 into D
D=M // (576) 
@R15 // (581) storing D in RAM[R15]
A=M // (582) 
M=D // (583) 
@0 // (567) 
D=A // (568) 
@SP // (558) 
A=M // (590) 
M=D // (591) 
@SP // (558) 
M=M+1 // (593) 
@SP // (558) 
M=M-1 // (601) 
A=M // (602) 
D=M // (603) 
@R14 // (288) location where popped value is stored
M=D // (289) 
@1 // (567) 
D=A // (568) 
@LCL // (559) 
D=M+D // (305) location where popped val will be stored
@R15 // (573) storing D in R15
M=D // (574) 
@R14 // (575) loading R14 into D
D=M // (576) 
@R15 // (581) storing D in RAM[R15]
A=M // (582) 
M=D // (583) 
@LCL // (559) 
D=M // (222) 
@0 // (223) 
A=D+A // (224) 
D=M // (225) 
@SP // (558) 
A=M // (590) 
M=D // (591) 
@SP // (558) 
M=M+1 // (593) 
@LCL // (559) 
D=M // (222) 
@1 // (223) 
A=D+A // (224) 
D=M // (225) 
@SP // (558) 
A=M // (590) 
M=D // (591) 
@SP // (558) 
M=M+1 // (593) 
@SP // (558) 
M=M-1 // (601) 
A=M // (602) 
D=M // (603) 
@R13 // (81) 
M=D // (82) 
@SP // (558) 
M=M-1 // (601) 
A=M // (602) 
D=M // (603) 
@R13 // (88) 
D=D+M // (92) add op
@SP // (558) 
A=M // (590) 
M=D // (591) 
@SP // (558) 
M=M+1 // (593) 
@SP // (558) 
M=M-1 // (601) 
A=M // (602) 
D=M // (603) 
D=!D // (73) negation unary op
@SP // (558) 
A=M // (590) 
M=D // (591) 
@SP // (558) 
M=M+1 // (593) 
@ARG // (561) 
D=M // (222) 
@0 // (223) 
A=D+A // (224) 
D=M // (225) 
@SP // (558) 
A=M // (590) 
M=D // (591) 
@SP // (558) 
M=M+1 // (593) 
@SP // (558) 
M=M-1 // (601) 
A=M // (602) 
D=M // (603) 
@R13 // (81) 
M=D // (82) 
@SP // (558) 
M=M-1 // (601) 
A=M // (602) 
D=M // (603) 
@R13 // (88) 
D=D+M // (92) add op
@SP // (558) 
A=M // (590) 
M=D // (591) 
@SP // (558) 
M=M+1 // (593) 
@ARG // (561) 
D=M // (222) 
@1 // (223) 
A=D+A // (224) 
D=M // (225) 
@SP // (558) 
A=M // (590) 
M=D // (591) 
@SP // (558) 
M=M+1 // (593) 
@SP // (558) 
M=M-1 // (601) 
A=M // (602) 
D=M // (603) 
@R13 // (81) 
M=D // (82) 
@SP // (558) 
M=M-1 // (601) 
A=M // (602) 
D=M // (603) 
@R13 // (88) 
D=D-M // (94) sub op
@SP // (558) 
A=M // (590) 
M=D // (591) 
@SP // (558) 
M=M+1 // (593) 
@LCL // (559) 
D=M // (428) 
@R13 // (452) FRAME
M=D // (453) 
@5 // (567) 
D=A // (568) 
@R13 // (457) 
D=M-D // (458) 
A=D // (460) 
D=M // (428) 
@R14 // (462) 
M=D // (463) 
@ARG // (561) 
D=M // (428) 
@R15 // (470) storing *ARG in R15
M=D // (471) 
@SP // (558) 
M=M-1 // (601) 
A=M // (602) 
D=M // (603) 
@R15 // (473) 
A=M // (474) 
M=D // (476) 
@ARG // (561) 
D=M // (428) 
D=D+1 // (481) 
@SP // (558) 
M=D // (483) 
@R13 // (489) 
D=M-1 // (490) 
A=D // (491) 
D=M // (428) 
@THAT // (563) 
M=D // (494) 
@2 // (567) 
D=A // (568) 
@R13 // (499) 
D=M-D // (500) 
A=D // (501) 
D=M // (428) 
@THIS // (562) 
M=D // (504) 
@3 // (567) 
D=A // (568) 
@R13 // (509) 
D=M-D // (510) 
A=D // (511) 
D=M // (428) 
@ARG // (561) 
M=D // (514) 
@4 // (567) 
D=A // (568) 
@R13 // (519) 
D=M-D // (520) 
A=D // (521) 
D=M // (428) 
@LCL // (559) 
M=D // (524) 
@R14 // (529) 
D=M // (428) 
A=D // (534) 
0;JMP // (535) 
(END) // (543) ...closing file...
@END // (544) 
0;JMP // (545) 
