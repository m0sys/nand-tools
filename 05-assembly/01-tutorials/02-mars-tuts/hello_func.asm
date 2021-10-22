.data
	msg: .asciiz "Hi, everybody!\nMy name is Moe!\n"

.text
.globl main
	main:
		jal disp_msg # jump to func
		jal end

	# Tell the system that prog is done.
	# NOTE: if you do not call these two lines then the prog will rerun
	# 		ad infinitum.
	end:
		li $v0, 10
		syscall

	disp_msg:
		li $v0, 4
		la $a0, msg
		syscall

		jr $ra # return to caller
