.data
	msg: .asciiz "It was true.\n"
	msg2: .asciiz "It was false.\n"
	num1: .float 10.4
	num2: .float 10.4

.text
.globl main
	main:
		lwc1 $f0, num1
		lwc1 $f2, num2

		c.eq.s $f0, $f2
		bc1t print_true 

		li $v0, 4
		la $a0, msg2
		syscall

		jal end

	print_true:
		li $v0, 4
		la $a0, msg
		syscall
		jal end

	end:
		li $v0, 10
		syscall
	
