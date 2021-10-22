.data

.text
.globl main
main:
	addi $t0, $zero, 2000
	addi $t1, $zero, 10
	mult $t0, $t1 # results will be saved in hi, lo reg

	mflo $s0
	li $v0, 1
	move $a0, $s0
	syscall
