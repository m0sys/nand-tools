.data

.text
.globl main
main:
	addi $t0, $zero, 30
	addi $t1, $zero, 5

	div $s0, $t0, $t1 # divide t0 by t1 and store result in s0 reg
	li $v0, 1
	move $a0, $s0
	syscall

