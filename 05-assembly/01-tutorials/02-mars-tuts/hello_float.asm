.data
	PI: .float 3.14

.text
.globl main
main:
	li $v0, 2 # print a float
	lwc1 $f12, PI # load to coprocessor 1
	syscall
	
