.data
.text
.globl main
main:
	addi $s0, $0, 30 # g
	addi $s1, $0, 20 # h

	slt $t0, $s1, $s0
	bne $t0, $0, if 

	# else
	sub $s0, $s0, $s1

	jal end

if:
	add $s0, $s0, $s1
	jal end
	
end:
	li $v0, 10
	syscall
