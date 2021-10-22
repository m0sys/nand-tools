.data
	msg: .asciiz "Hi, everybody!\nMy name is Moe!\n"

.text
.globl main
	main:
		addi $a1, $zero, 50
		addi $a2, $zero, 100
		
		jal add_nums
		# add $a1, $zero, $v1
		jal disp_res
		jal end

	disp_res:
		li $v0, 1
		add $a0, $zero, $v1  
		syscall
		jr $ra # return to caller

	add_nums:
		# "v" regs are for return values, "a" regs are for arg values.
		add $v1, $a1, $a2
		jr $ra

	end:
		li $v0, 10
		syscall

