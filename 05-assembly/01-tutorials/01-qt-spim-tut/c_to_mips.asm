.text
.globl main
main:
	li $t0, 10 # num iters
	li $t1, 0 # t1 is counter (i)
	li $t2, 17 # t2 holds value to modify
loop:
	beq $t1, $t0, end # if counter is equal to num iters end the loop
	add $t2, $t2, $t1
	addi $t1, $t1, 1
	j loop
end:
	li $v0, 10
	syscall
