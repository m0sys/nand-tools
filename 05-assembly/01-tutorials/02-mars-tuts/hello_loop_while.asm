.data
	msg: .asciiz "After while loop is done"
	comma: .asciiz ", "
.text
.globl main
	main:
		addi $t0, $zero, 0
		while:
			bgt $t0, 10, exit
			jal print_num
			addi $t0, $t0, 1
			j while

		exit:
			li $v0, 4
			la $a0, msg
			syscall
			
		jal end
	
	print_num:
		li $v0, 1
		add $a0, $t0, $zero
		syscall

		li $v0, 4
		la $a0, comma
		syscall

		jr $ra

	end:
		li $v0, 10
		syscall
	
