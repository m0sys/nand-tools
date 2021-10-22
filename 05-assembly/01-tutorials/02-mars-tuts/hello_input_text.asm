.data
	prompt: .asciiz "What is your name? "
	user_input: .space 20
	input_lim: .word 20
	msg: .asciiz "Hello, "

.text
.globl main
	main:
		# Display prompt to user.
		li $v0, 4
		la $a0, prompt
		syscall

		# Get text from user.
		li $v0, 8
		la $a0, user_input
		lw $a1, input_lim
		syscall

		# Display user input.
		li $v0, 4
		la $a0, msg
		syscall

		li $v0, 4
		la $a0, user_input
		syscall


		jal end

	end:
		li $v0, 10
		syscall
