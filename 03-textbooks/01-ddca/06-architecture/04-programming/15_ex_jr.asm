.data

.text
.globl main
main:
	0x00002000 addi $s0, $0, 0x2010
	0x00002004 jr $s0
	0x00002008 addi $s1, $0, 1
	0x0000200c sra $s1, $s1, 2
	0x00002010 lw $s3, 44($s1)
	jal end

end:
	li $v0, 10
	syscall
