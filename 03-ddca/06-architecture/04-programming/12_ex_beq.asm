.data

.text
.globl main
main:
	addi $s0, $0, 4
	addi $s1, $0, 1
	sll $s1, $s1, 2
	beq $s0, $s1, target
	addi $s1, $s1, 1
	sub $s1, $s1, $s0

	jal end

target:
	add $s1, $s1, $s0
	jal end

end:
	li $v0, 10
	syscall
