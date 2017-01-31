	

	sub	$0x3c, %rsi
	cmp	$0x5, %rsi	
	ja	4005c3 <switch_prob+0x33>
	jmpq	*0x4006f8(,%rsi,8)
	lea	0x0(,%rdi,8), %rax
	
	retq
	mov	%rdi, %rax
	sar	$0x3, %rax
	retq
	mov	%rdi,%rax
	shl	$0x4,%rax
	sub	$rdi,%rax
	mov	%rax,%rdi
	imul	%rdi,%rdi
	lea	0x4b(%rdi),%rax
	retq


