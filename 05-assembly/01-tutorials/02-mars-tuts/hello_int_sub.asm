.data
	num1: .word 20
	num2: .word 8

.text
.globl main
main:
	lw $s0, num1($zero)
	lw $s1, num2($zero)
	sub $t0, $s0, $s1 # sub s0 + s1 and save result in t0
	li $v0, 1
	move $a0, $t0 # pseudo instruction
	syscall
