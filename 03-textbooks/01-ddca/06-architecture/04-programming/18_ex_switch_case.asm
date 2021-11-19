.data

.text
.globl main
main:
	# $s0 = amount, $s1 = fee
	addi $s0, $0, 20

	case20:
		addi $t0, $0, 20
		bne $s0, $t0, case50
		addi $s1, $0, 2
		j done

	case50:
		addi $t0, $0, 50
		bne $s0, $t0, case100
		addi $s1, $0, 3
		j done

	case100:
		addi $t0, $0, 100
		bne $s0, $t0, default
		addi $s1, $0, 5
		j done

	default:
		addi $s1, $0, 10

	done:

	jal end

end:
	li $v0, 10
	syscall
