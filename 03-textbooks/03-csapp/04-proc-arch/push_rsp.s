.text
.globl pushtest
pushtest:
	movq %rsp, %rax
	pushq %rsp
	popq %rdx
	subq %rdx, %rax
	ret

.global main
main:
	pushq %rbp
	movq %rsp, %rbp
	call pushtest
	movq %rax, %rdi
	call puts
	movl $0, %eax
	leave
	ret

