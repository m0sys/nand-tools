.data
	msg1: .asciiz "The numbers are equal."
	msg2: .asciiz "Nothing happened."

.text
.globl main
	main:
		addi $t0, $zero, 20
		addi $t1, $zero, 20

		beq $t0, $t1, nums_equal

		# Display user input.
		li $v0, 4
		la $a0, msg2
		syscall

		jal end

	nums_equal:
		# Display user input.
		li $v0, 4
		la $a0, msg1
		syscall
		jal end
	

	end:
		li $v0, 10
		syscall
