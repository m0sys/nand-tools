.data
	prompt: .asciiz "Enter the value of e: "

.text
.globl main
	main:
		# Display prompt to user.
		li $v0, 4
		la $a0, prompt
		syscall

		# Get double from user.
		li $v0, 7
		syscall

		# Display user input.
		li $v0, 3
		add.d $f12, $f0, $f10
		syscall


		jal end

	end:
		li $v0, 10
		syscall
