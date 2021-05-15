	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 3
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	movl	$0, -16(%rbp)
	movl	$300, -20(%rbp)                 ## imm = 0x12C
	movl	$20, -24(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, -8(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-8(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jg	LBB0_3
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-8(%rbp), %esi
	movl	-8(%rbp), %eax
	subl	$32, %eax
	imull	$5, %eax, %eax
	cltd
	movl	$9, %ecx
	idivl	%ecx
	leaq	L_.str(%rip), %rdi
	movl	%eax, %edx
	movb	$0, %al
	callq	_printf
	movl	-24(%rbp), %ecx
	addl	-8(%rbp), %ecx
	movl	%ecx, -8(%rbp)
	jmp	LBB0_1
LBB0_3:
	xorl	%eax, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d\t%d\n"

.subsections_via_symbols
