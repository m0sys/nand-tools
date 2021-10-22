.data
	prompt: .asciiz "Enter the value of PI: "
	msg: .asciiz "\n Your age is "
	float_zero: .float 0.0
.text
.globl main
	main:
		lwc1 $f4, float_zero

		# Prompt user.
		li $v0, 4
		la $a0, prompt
		syscall

		# Read user's input.
		li $v0, 6 # get float from keyboard - stores in f0 not v0
		syscall

		# Display value.
		li $v0, 2
		add.s $f12, $f0, $f4
		syscall

		jal end
	
	end:
		li $v0, 10
		syscall
