// Author: m0sys
// Date: 2022/7/21

// The RiscV register conventions:
// x5-x7 & x28-x31: temp regs that are not preserved by the callee on proc call. 
// x8-x9 & x18-x27: saved regs that must be preserved on proc call (if callee uses them).
// x10-x17:         eight func param regs to pass params or return vals.
// x1:              return addr reg to return the point of origin.

section: .text
.global _start
.p2align 2

_start:
	addi x10, x0, 5
	jal x1, fact

fact:
	// Save X10, and return addr (X0).
	addi sp, sp, -16 // adjust stk for 2 items
	sd x1, 8(sp) // save ret addr
	sd x10, 0(sp) // save arg n

	// Check if n>= 1. 
	addi x5, x10, -1 // x5 = n - 1
	bge x5, x0, L1 // if (n - 1) >= 0, go to L1
	// If n < 1 return 1.
	addi x10, x0, 1 // return 1
	addi sp, sp, 16 // pop 2 items off stk
	jalr x0, 0(x1)

// Recursive call fact(n-1).
L1: addi x10, x10, -1  // n--
	jal x1, fact // fact(n-1)

	// Return the result n * fact(n - 1).
	addi x6, x10, 0 // move res of fact(n - 1) to x6
	// Restore arg n and ret addr (to init caller of fact).
	ld x10, 0(sp) // restore arg n
	ld x1, 8(sp) // restore ret addr
	addi sp, sp, 16 // pop 2 items

	// Calc n * fact(n - 1).
	mul x10, x10, x6
	jalr x0, 0(x1) // ret to caller

