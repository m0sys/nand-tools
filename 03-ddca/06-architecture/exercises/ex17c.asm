.data
.text
.globl main
main:
	addi $s0, $0, 19 # g
	addi $s1, $0, 20 # h

	slt $t0, $s1, $s0
	beq $t0, $0, if 
	beq $s1, $s0, if

	# else
	addi $s0, $s0, -1

	jal end

if:
	addi $s0, $s0, 1
	jal end
	
end:
	li $v0, 10
	syscall
