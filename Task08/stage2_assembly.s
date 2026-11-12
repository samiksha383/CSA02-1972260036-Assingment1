	.file	"task5.c"
	.text
	.globl	consumption
	.def	consumption;	.scl	2;	.type	32;	.endef
	.seh_proc	consumption
consumption:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movw	%cx, 16(%rbp)
	movw	%dx, 24(%rbp)
	movzwl	24(%rbp), %eax
	subw	16(%rbp), %ax
	movzwl	%ax, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	compute_bill
	.def	compute_bill;	.scl	2;	.type	32;	.endef
	.seh_proc	compute_bill
compute_bill:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	$5000, -4(%rbp)
	cmpl	$200, 16(%rbp)
	jle	.L4
	movl	16(%rbp), %eax
	subl	$200, %eax
	imull	$450, %eax, %eax
	addl	$22500, %eax
	addl	%eax, -4(%rbp)
	jmp	.L5
.L4:
	cmpl	$100, 16(%rbp)
	jle	.L5
	movl	16(%rbp), %eax
	subl	$100, %eax
	imull	$225, %eax, %eax
	addl	%eax, -4(%rbp)
.L5:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "Final Bill: Rs %ld.%02ld\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	movl	$120, %edx
	movl	$65400, %ecx
	call	consumption
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %ecx
	call	compute_bill
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$1374389535, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$5, %edx
	movl	%eax, %ecx
	sarl	$31, %ecx
	subl	%ecx, %edx
	imull	$100, %edx, %ecx
	subl	%ecx, %eax
	movl	%eax, %edx
	movl	-8(%rbp), %eax
	movslq	%eax, %rcx
	imulq	$1374389535, %rcx, %rcx
	shrq	$32, %rcx
	sarl	$5, %ecx
	sarl	$31, %eax
	subl	%eax, %ecx
	leaq	.LC0(%rip), %rax
	movl	%edx, %r8d
	movl	%ecx, %edx
	movq	%rax, %rcx
	call	printf
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (MinGW-W64 x86_64-ucrt-posix-seh, built by Brecht Sanders, r3) 16.2.0"
	.def	printf;	.scl	2;	.type	32;	.endef
