	.file	"stack-growth.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"Callee function stack addresses:"
.LC1:
	.string	"  local_int_2       : %p\n"
.LC2:
	.string	"  local_char_arr[0] : %p\n"
.LC3:
	.string	"  local_char_arr[1] : %p\n"
	.text
	.globl	foobar
	.type	foobar, @function
foobar:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$5, -36(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-36(%rbp), %rax
	leaq	.LC1(%rip), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-32(%rbp), %rax
	leaq	.LC2(%rip), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-32(%rbp), %rax
	leaq	1(%rax), %rdx
	leaq	.LC3(%rip), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	call	pause@PLT
	nop
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L2
	call	__stack_chk_fail@PLT
.L2:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	foobar, .-foobar
	.section	.rodata
	.align 8
.LC5:
	.string	"Caller function stack addresses:"
.LC6:
	.string	"  local_int_1       : %p\n"
.LC7:
	.string	"  local_double_1    : %p\n"
.LC8:
	.string	"  local_int_arr[0]  : %p\n"
.LC9:
	.string	"  local_int_arr[1]  : %p\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$10, -60(%rbp)
	movsd	.LC4(%rip), %xmm0
	movsd	%xmm0, -56(%rbp)
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-60(%rbp), %rax
	leaq	.LC6(%rip), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-56(%rbp), %rax
	leaq	.LC7(%rip), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-48(%rbp), %rax
	leaq	.LC8(%rip), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-48(%rbp), %rax
	leaq	4(%rax), %rdx
	leaq	.LC9(%rip), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	call	foobar
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC4:
	.long	1717986918
	.long	1073899110
	.ident	"GCC: (GNU) 15.2.1 20250813"
	.section	.note.GNU-stack,"",@progbits
