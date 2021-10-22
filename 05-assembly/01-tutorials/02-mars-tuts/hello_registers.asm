.data
	nl: .asciiz "\n"

.text
.globl main
# NOTE: By convention "s" registers are caller safe while "t" registers are calle safe.
	main:
		addi $s0, $zero, 10

		jal inc_reg


		move $a1, $s0
		jal disp_word
		
		jal end

	inc_reg:
		# Remember that mips is byte addressable.
		addi $sp, $sp, -8
		sw $s0, 0($sp)
		# NOTE: to deal with nested functions we need to store the caller addr
		# 		in the stack.

		sw $ra, 4($sp)

		addi $s0, $s0, 1

		move $a1, $s0
		jal disp_word

		# Reset stack and register.
		lw $s0, 0($sp)
		lw $ra, 4($sp)
		addi $sp, $sp, 8

		jr $ra

	disp_word:
		li $v0, 1
		move $a0, $a1
		syscall

		# Print a newline.
		li $v0, 4
		la $a0, nl
		syscall

		jr $ra

	end:
		li $v0, 10
		syscall
