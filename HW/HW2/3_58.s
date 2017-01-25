	.file	"3_58.c"
	.text
	.globl	decode2
	.type	decode2, @function
decode2:
.LFB0:
	.cfi_startproc
	subq	%rdx, %rsi
	movq	%rdi, %rax
	imulq	%rsi, %rax
	salq	$63, %rsi
	sarq	$63, %rsi
	xorq	%rsi, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	decode2, .-decode2
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movl	$2882837, %edx
	movl	$28183, %esi
	movl	$12838, %edi
	call	decode2
	movq	%rax, %rbx
	movl	$12838, %edx
	movl	$2882837, %esi
	movl	$28183, %edi
	call	decode2
	movq	%rax, %rbp
	movl	$28183, %edx
	movl	$12838, %esi
	movl	$2882837, %edi
	call	decode2
	movq	%rax, %rdx
	movq	%rbp, %rsi
	movq	%rbx, %rdi
	call	decode2
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
