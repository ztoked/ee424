	.file	"testbubble.c"
	.text
	.globl	bubble_a
	.type	bubble_a, @function
bubble_a:
.LFB23:
	.cfi_startproc
	leaq	-1(%rsi), %r9
	jmp	.L2
.L4:
	leaq	8(%rdi,%rax,8), %rsi
	movq	(%rsi), %rcx
	leaq	(%rdi,%rax,8), %rdx
	movq	(%rdx), %r8
	cmpq	%r8, %rcx
	jge	.L3
	movq	%r8, (%rsi)
	movq	%rcx, (%rdx)
.L3:
	addq	$1, %rax
	jmp	.L5
.L6:
	movl	$0, %eax
.L5:
	cmpq	%r9, %rax
	jl	.L4
	subq	$1, %r9
.L2:
	testq	%r9, %r9
	jg	.L6
	rep ret
	.cfi_endproc
.LFE23:
	.size	bubble_a, .-bubble_a
	.globl	bubble_p
	.type	bubble_p, @function
bubble_p:
.LFB24:
	.cfi_startproc
	leaq	-1(%rsi), %r9
	jmp	.L8
.L10:
	leaq	8(%rdi,%rax,8), %rsi
	movq	(%rsi), %rcx
	leaq	(%rdi,%rax,8), %rdx
	movq	(%rdx), %r8
	cmpq	%r8, %rcx
	jge	.L9
	movq	%r8, (%rsi)
	movq	%rcx, (%rdx)
.L9:
	addq	$1, %rax
	jmp	.L11
.L12:
	movl	$0, %eax
.L11:
	cmpq	%r9, %rax
	jl	.L10
	subq	$1, %r9
.L8:
	testq	%r9, %r9
	jg	.L12
	rep ret
	.cfi_endproc
.LFE24:
	.size	bubble_p, .-bubble_p
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"array version"
.LC1:
	.string	"  Before: "
.LC2:
	.string	"0x%.4x "
.LC3:
	.string	"  After:  "
.LC4:
	.string	"pointer version"
	.text
	.globl	main
	.type	main, @function
main:
.LFB25:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$.LC0, %edi
	call	puts
	movl	$.LC1, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	$0, %ebx
	jmp	.L14
.L15:
	movslq	%ebx, %rax
	movq	array1(,%rax,8), %rdx
	movl	$.LC2, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	addl	$1, %ebx
.L14:
	cmpl	$5, %ebx
	jle	.L15
	movl	$10, %edi
	call	putchar
	movl	$6, %esi
	movl	$array1, %edi
	call	bubble_a
	movl	$.LC3, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	$0, %ebx
	jmp	.L16
.L17:
	movslq	%ebx, %rax
	movq	array1(,%rax,8), %rdx
	movl	$.LC2, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	addl	$1, %ebx
.L16:
	cmpl	$5, %ebx
	jle	.L17
	movl	$10, %edi
	call	putchar
	movl	$.LC4, %edi
	call	puts
	movl	$.LC1, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	$0, %ebx
	jmp	.L18
.L19:
	movslq	%ebx, %rax
	movq	array2(,%rax,8), %rdx
	movl	$.LC2, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	addl	$1, %ebx
.L18:
	cmpl	$5, %ebx
	jle	.L19
	movl	$10, %edi
	call	putchar
	movl	$6, %esi
	movl	$array2, %edi
	call	bubble_p
	movl	$.LC3, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	$0, %ebx
	jmp	.L20
.L21:
	movslq	%ebx, %rax
	movq	array2(,%rax,8), %rdx
	movl	$.LC2, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	addl	$1, %ebx
.L20:
	cmpl	$5, %ebx
	jle	.L21
	movl	$10, %edi
	call	putchar
	movl	$0, %eax
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE25:
	.size	main, .-main
	.globl	array2
	.data
	.align 32
	.type	array2, @object
	.size	array2, 56
array2:
	.quad	56797
	.quad	61166
	.quad	48059
	.quad	43690
	.quad	65535
	.quad	52428
	.quad	257
	.globl	array1
	.align 32
	.type	array1, @object
	.size	array1, 56
array1:
	.quad	56797
	.quad	61166
	.quad	48059
	.quad	43690
	.quad	65535
	.quad	52428
	.quad	257
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
