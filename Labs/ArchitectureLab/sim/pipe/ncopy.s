	.file	"ncopy.c"
	.text
	.globl	ncopy
	.type	ncopy, @function
ncopy:
.LFB23:
	.cfi_startproc
	leal	14(%rdx), %eax
	movl	%edx, %ecx
	addl	$7, %ecx
	cmovs	%eax, %ecx
	sarl	$3, %ecx
	movl	%edx, %eax
	sarl	$31, %eax
	shrl	$29, %eax
	addl	%eax, %edx
	andl	$7, %edx
	subl	%eax, %edx
	cmpl	$7, %edx
	ja	.L13
	movl	%edx, %edx
	jmp	*.L4(,%rdx,8)
	.section	.rodata
	.align 8
	.align 4
.L4:
	.quad	.L14
	.quad	.L15
	.quad	.L16
	.quad	.L17
	.quad	.L18
	.quad	.L19
	.quad	.L20
	.quad	.L21
	.text
.L14:
	movl	$0, %eax
.L3:
	leaq	4(%rdi), %r8
	movl	(%rdi), %edx
	movl	%edx, (%rsi)
	addq	$4, %rsi
	movq	%r8, %rdi
	testl	%edx, %edx
	jle	.L11
	addl	$1, %eax
	jmp	.L11
.L21:
	movl	$0, %eax
.L11:
	leaq	4(%rdi), %rdx
	movl	(%rdi), %edi
	movl	%edi, (%rsi)
	addq	$4, %rsi
	testl	%edi, %edi
	setg	%dil
	movzbl	%dil, %edi
	addl	%edi, %eax
	jmp	.L10
.L20:
	movq	%rdi, %rdx
	movl	$0, %eax
.L10:
	leaq	4(%rdx), %rdi
	movl	(%rdx), %edx
	movl	%edx, (%rsi)
	addq	$4, %rsi
	testl	%edx, %edx
	setg	%dl
	movzbl	%dl, %edx
	addl	%edx, %eax
	jmp	.L9
.L19:
	movl	$0, %eax
.L9:
	leaq	4(%rdi), %rdx
	movl	(%rdi), %edi
	movl	%edi, (%rsi)
	addq	$4, %rsi
	testl	%edi, %edi
	setg	%dil
	movzbl	%dil, %edi
	addl	%edi, %eax
	jmp	.L8
.L18:
	movq	%rdi, %rdx
	movl	$0, %eax
.L8:
	leaq	4(%rdx), %rdi
	movl	(%rdx), %edx
	movl	%edx, (%rsi)
	addq	$4, %rsi
	testl	%edx, %edx
	setg	%dl
	movzbl	%dl, %edx
	addl	%edx, %eax
	jmp	.L7
.L17:
	movl	$0, %eax
.L7:
	leaq	4(%rdi), %rdx
	movl	(%rdi), %edi
	movl	%edi, (%rsi)
	addq	$4, %rsi
	testl	%edi, %edi
	setg	%dil
	movzbl	%dil, %edi
	addl	%edi, %eax
	jmp	.L6
.L16:
	movq	%rdi, %rdx
	movl	$0, %eax
.L6:
	leaq	4(%rdx), %rdi
	movl	(%rdx), %edx
	movl	%edx, (%rsi)
	addq	$4, %rsi
	testl	%edx, %edx
	setg	%dl
	movzbl	%dl, %edx
	addl	%edx, %eax
	jmp	.L5
.L15:
	movl	$0, %eax
.L5:
	movl	(%rdi), %edx
	movl	%edx, (%rsi)
	testl	%edx, %edx
	setg	%dl
	movzbl	%dl, %edx
	addl	%edx, %eax
	subl	$1, %ecx
	testl	%ecx, %ecx
	jle	.L2
	addq	$4, %rdi
	addq	$4, %rsi
	jmp	.L3
.L13:
	movl	$0, %eax
.L2:
	rep ret
	.cfi_endproc
.LFE23:
	.size	ncopy, .-ncopy
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"count=%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	movl	$src, %edx
	movl	$0, %eax
.L24:
	addl	$1, %eax
	movl	%eax, (%rdx)
	addq	$4, %rdx
	cmpl	$8, %eax
	jne	.L24
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$8, %edx
	movl	$dst, %esi
	movl	$src, %edi
	call	ncopy
	movl	%eax, %edx
	movl	$.LC0, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	$0, %edi
	call	exit
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.comm	dst,32,32
	.comm	src,32,32
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
