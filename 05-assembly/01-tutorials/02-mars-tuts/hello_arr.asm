.data
	my_arr: .space 12
	nl: .asciiz "\n"
	msg: .asciiz "After while loop is done"

.text
.globl main
	main:
		addi $s0, $zero, 4
		addi $s1, $zero, 10
		addi $s2, $zero, 12

		# Index = $t0
		addi $t0, $zero, 0
		sw $s0, my_arr($t0)

		addi $t0, 4
		sw $s1, my_arr($t0)

		addi $t0, 4
		sw $s2, my_arr($t0)


		# Clear t0 to 0.
		addi $t0, $zero, 0

		while:
			beq $t0, 12, exit
			
			lw $t6, my_arr($t0)
			addi $t0, 4

			# Print curr value.
			li $v0, 1
			addi $a0, $t6, 0
			syscall

			# Print a newline.
			li $v0, 4
			la $a0, nl
			syscall

			j while

		exit:
			li $v0, 4
			la $a0, msg
			syscall

		jal end

	end:
		li $v0, 10
		syscall
