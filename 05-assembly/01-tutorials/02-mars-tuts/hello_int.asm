.data
	age: .word 23

.text
.globl main
main:
	li $v0, 1 # print a word
	lw $a0, age # a0 is argument reg
	syscall
	
