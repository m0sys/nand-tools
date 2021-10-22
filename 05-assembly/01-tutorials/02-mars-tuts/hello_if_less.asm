.data
	msg1: .asciiz "The numbers is less than the other."
	msg2: .asciiz "Nothing happened."

.text
.globl main
	main:
		addi $t0, $zero, 400
		addi $t1, $zero, 200

		slt $s0, $t0, $t1 
		bne $s0, $zero, is_less

		# Display user input.
		li $v0, 4
		la $a0, msg2
		syscall

		jal end

	is_less:
		# Display user input.
		li $v0, 4
		la $a0, msg1
		syscall
		jal end
	

	end:
		li $v0, 10
		syscall
