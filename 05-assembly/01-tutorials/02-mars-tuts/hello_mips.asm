.data
# Contains all the data for the program.
	my_msg: .asciiz "Hello, World!\n"

.text
# Contains all the instructions for the program.
.globl main
main:
	li $v0, 4
	la $a0, my_msg
	syscall

