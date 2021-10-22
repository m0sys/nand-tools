.data
	my_double: .double 7.202
	zero_double: .double 0.0
.text
.globl main
main:
	# Since mips is 32bits and doubles are 64bits we need two registers to
	# load double from memory. Hence, the double is loaded into f2 and f3.
	ldc1 $f2, my_double  # load into f2, f3 regs
	ldc1 $f0, zero_double # load into f0, f1 regs
	li $v0, 3 # print a double
	add.d $f12, $f2, $f0
	syscall
