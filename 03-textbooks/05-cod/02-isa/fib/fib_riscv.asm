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
	jal x1, fib


fib: // TODO
	// Save x10 and ret addr (x0) and x8.
	addi sp, sp, -24 // adjust stk for 3 items
	sd x8, 16(sp) // save x8 (holds call to fib(n - 1))
	sd x1, 8(sp) // save ret addr
	sd x10, 0(sp) // save arg n

	// Check if n != 0.
	bne x10, x0, L0 
	// If n == 0 return n.
	addi sp, sp, 24 // pop 3 items off stk
	jalr x0, 0(x1)


L0: // Check if n != 1.
	addi x5, x10, -1 // x5 = n -1
	bne x10, x0, L1
	// If n == 1 return n.
	addi sp, sp, 24 // pop 3 items off stk
	jalr x0, 0(x1)

// Recursive call fib(n - 1).
L1: addi x10, x10, -1 // n--
	jal x1, fact // fib(n - 1)

	// Save result of fib(n-1).
	addi x8, x10, 0 // move res of fib(n -1) to x8
	// Restore arg n and ret addr (to init caller of fib) and x8.
	ld x10, 0(sp) // restore arg n
	ld x1, 8(sp) // restore ret addr 
	ld x8, 16(sp) // restore x8 (fib(n - 1))
	addi sp, sp, 24 // pop 3 items

	// Recursive call fib(n - 2).
	addi x10, x10, -1 // n--
	jal x1, fact // fib(n - 2)

	// Return fib(n - 1) + fib(n - 2).
	addi x6, x10, 0 // move res of fact(n - 2) to x6
	// Restore arg n and ret addr (to init caller of fib) and x8.
	ld x10, 0(sp) // restore arg n
	ld x1, 8(sp) // restore ret addr 
	ld x8, 16(sp) // restore x8 (fib(n - 1))
	addi sp, sp, 24 // pop 3 items

	// Calc fib(n - 1) + fib(n - 2).
	add x10, x8, x10
	jalr x0, 0(x1) // ret to caller

