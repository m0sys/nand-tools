.data
	nl: .asciiz "\n"

.text
.globl main
	main:
		jal end

	end:
		li $v0, 10
		syscall
