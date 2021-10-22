.data
	num1: .word 5
	num2: .word 10

.text
.globl main
main:
	lw $t0, num1($zero)
	lw $t1, num2($zero)
	add $t2, $t0, $t1 # add t0 + t1 and save result in t2
	li $v0, 1
	add $a0, $zero, $t2
	syscall
