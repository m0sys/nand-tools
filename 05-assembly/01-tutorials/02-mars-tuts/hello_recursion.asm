.data
	promt: .asciiz "Enter a number to find its factorial: "
	res_msg: .asciiz "\nThe factorial of the number is "
	num: .word 0
	ans: .word 0
.text
.globl main
	main:
		# Read the num from user.
		li $v0, 4
		la $a0, promt
		syscall

		li $v0, 5
		syscall

		sw $v0, num

		# Call the factorial func.
		lw $a0, num
		jal fact 
		sw $v0, ans

		# Display the results.
		li $v0, 4
		la $a0, res_msg
		syscall

		li $v0, 1
		lw $a0, ans
		syscall

		jal end
	
	fact:
		subu $sp, $sp, 8
		sw $ra, 0($sp)
		sw $s0, 4($sp)

		# Base Case:
		li $v0, 1
		beq $a0, 0, fact_base

		# Recursive Case:
		move $s0, $a0
		sub $a0, $a0, 1
		jal fact

		mul $v0, $s0, $v0 # tail-non-recurisive

	fact_base:
		lw $ra, 0($sp)
		lw $s0, 4($sp)
		addu $sp, $sp, 8

		jr $ra

	end:
		li $v0, 10
		syscall
	
