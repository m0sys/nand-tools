.data
	prompt: .asciiz "Enter your age: "
	msg: .asciiz "\n Your age is "
.text
.globl main
	main:
		# Prompt, the user to enter their age.
		li $v0, 4
		la $a0, prompt
		syscall
	
		# Get the user's age.
		li $v0, 5 # get int input from keyboard
		syscall
	
		# Store the result in t0.
		move $t0, $v0
	
		# Display
		li $v0, 4
		la $a0, msg
		syscall
	
		li $v0, 1
		move $a0, $t0
		syscall

		jal end
	
	end:
		li $v0, 10
		syscall
