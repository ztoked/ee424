	.file	"3_63.c"
	.text
.Ltext0:
	.globl	switch_prob
	.type	switch_prob, @function
switch_prob:
.LFB0:
	.file 1 "3_63.c"
	.loc 1 2 0
	.cfi_startproc
.LVL0:
	.loc 1 4 0
	subq	$60, %rsi
.LVL1:
	cmpq	$5, %rsi
	ja	.L2
	jmp	*.L4(,%rsi,8)
	.section	.rodata
	.align 8
	.align 4
.L4:
	.quad	.L3
	.quad	.L2
	.quad	.L3
	.quad	.L5
	.quad	.L6
	.quad	.L7
	.text
.L3:
	.loc 1 8 0
	leaq	0(,%rdi,8), %rax
.LVL2:
	.loc 1 9 0
	ret
.LVL3:
.L5:
	.loc 1 11 0
	movq	%rdi, %rax
	sarq	$3, %rax
.LVL4:
	.loc 1 12 0
	ret
.LVL5:
.L6:
	.loc 1 14 0
	movq	%rdi, %rax
	salq	$4, %rax
.LVL6:
	.loc 1 15 0
	subq	%rdi, %rax
.LVL7:
	movq	%rax, %rdi
.LVL8:
.L7:
	.loc 1 17 0
	imulq	%rdi, %rdi
.LVL9:
.L2:
	.loc 1 19 0
	leaq	75(%rdi), %rax
.LVL10:
	.loc 1 23 0
	ret
	.cfi_endproc
.LFE0:
	.size	switch_prob, .-switch_prob
	.globl	main
	.type	main, @function
main:
.LFB1:
	.loc 1 25 0
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	.loc 1 26 0
	movl	$132, %esi
	movl	$241, %edi
	call	switch_prob
.LVL11:
	movq	%rax, %rbx
.LVL12:
	.loc 1 27 0
	movl	$103, %esi
	movl	$927, %edi
	call	switch_prob
.LVL13:
	.loc 1 28 0
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	switch_prob
.LVL14:
	movq	%rax, %rcx
.LVL15:
	.loc 1 29 0
	movabsq	$7378697629483820647, %rdx
	imulq	%rdx
.LVL16:
	sarq	$4, %rdx
	sarq	$63, %rcx
.LVL17:
	subq	%rcx, %rdx
	movq	%rdx, %rsi
	movq	%rbx, %rdi
	call	switch_prob
.LVL18:
	.loc 1 30 0
	popq	%rbx
	.cfi_def_cfa_offset 8
.LVL19:
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
.Letext0:
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x135
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF2
	.byte	0xc
	.long	.LASF3
	.long	.LASF4
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.long	.LASF5
	.byte	0x1
	.byte	0x1
	.long	0x78
	.quad	.LFB0
	.quad	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.long	0x78
	.uleb128 0x3
	.string	"x"
	.byte	0x1
	.byte	0x1
	.long	0x78
	.long	.LLST0
	.uleb128 0x3
	.string	"n"
	.byte	0x1
	.byte	0x1
	.long	0x78
	.long	.LLST1
	.uleb128 0x4
	.long	.LASF0
	.byte	0x1
	.byte	0x3
	.long	0x78
	.long	.LLST2
	.byte	0
	.uleb128 0x5
	.byte	0x8
	.byte	0x5
	.long	.LASF1
	.uleb128 0x6
	.long	.LASF6
	.byte	0x1
	.byte	0x19
	.long	0x131
	.quad	.LFB1
	.quad	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.long	0x131
	.uleb128 0x7
	.string	"x"
	.byte	0x1
	.byte	0x1a
	.long	0x78
	.long	.LLST3
	.uleb128 0x7
	.string	"y"
	.byte	0x1
	.byte	0x1b
	.long	0x78
	.long	.LLST4
	.uleb128 0x7
	.string	"z"
	.byte	0x1
	.byte	0x1c
	.long	0x78
	.long	.LLST5
	.uleb128 0x8
	.quad	.LVL11
	.long	0x2d
	.long	0xe5
	.uleb128 0x9
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x8
	.byte	0xf1
	.uleb128 0x9
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2
	.byte	0x8
	.byte	0x84
	.byte	0
	.uleb128 0x8
	.quad	.LVL13
	.long	0x2d
	.long	0x104
	.uleb128 0x9
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x3
	.byte	0xa
	.value	0x39f
	.uleb128 0x9
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2
	.byte	0x8
	.byte	0x67
	.byte	0
	.uleb128 0x8
	.quad	.LVL14
	.long	0x2d
	.long	0x11c
	.uleb128 0x9
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x73
	.sleb128 0
	.byte	0
	.uleb128 0xa
	.quad	.LVL18
	.long	0x2d
	.uleb128 0x9
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x73
	.sleb128 0
	.byte	0
	.byte	0
	.uleb128 0xb
	.byte	0x4
	.byte	0x5
	.string	"int"
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x4109
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x410a
	.byte	0
	.uleb128 0x2
	.uleb128 0x18
	.uleb128 0x2111
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x4109
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_loc,"",@progbits
.Ldebug_loc0:
.LLST0:
	.quad	.LVL0-.Ltext0
	.quad	.LVL8-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL8-.Ltext0
	.quad	.LFE0-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	0
	.quad	0
.LLST1:
	.quad	.LVL0-.Ltext0
	.quad	.LVL1-.Ltext0
	.value	0x1
	.byte	0x54
	.quad	.LVL1-.Ltext0
	.quad	.LFE0-.Ltext0
	.value	0x3
	.byte	0x74
	.sleb128 60
	.byte	0x9f
	.quad	0
	.quad	0
.LLST2:
	.quad	.LVL0-.Ltext0
	.quad	.LVL2-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL2-.Ltext0
	.quad	.LVL3-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	.LVL3-.Ltext0
	.quad	.LVL4-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL4-.Ltext0
	.quad	.LVL5-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	.LVL5-.Ltext0
	.quad	.LVL6-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL6-.Ltext0
	.quad	.LVL7-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	.LVL7-.Ltext0
	.quad	.LVL8-.Ltext0
	.value	0x5
	.byte	0x75
	.sleb128 0
	.byte	0x34
	.byte	0x24
	.byte	0x9f
	.quad	.LVL10-.Ltext0
	.quad	.LFE0-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	0
	.quad	0
.LLST3:
	.quad	.LVL12-.Ltext0
	.quad	.LVL13-1-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	.LVL13-1-.Ltext0
	.quad	.LVL19-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	0
	.quad	0
.LLST4:
	.quad	.LVL13-.Ltext0
	.quad	.LVL14-1-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	0
	.quad	0
.LLST5:
	.quad	.LVL15-.Ltext0
	.quad	.LVL16-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	.LVL16-.Ltext0
	.quad	.LVL17-.Ltext0
	.value	0x1
	.byte	0x52
	.quad	0
	.quad	0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF5:
	.string	"switch_prob"
.LASF0:
	.string	"result"
.LASF2:
	.string	"GNU C11 5.4.0 20160609 -mtune=generic -march=x86-64 -g -O1 -fstack-protector-strong"
.LASF3:
	.string	"3_63.c"
.LASF1:
	.string	"long int"
.LASF6:
	.string	"main"
.LASF4:
	.string	"/home/zachmint/School/EE424/HW/HW3"
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
