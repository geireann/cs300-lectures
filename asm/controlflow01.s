	.file	"controlflow01.c"
	.text
	.globl	_Z1fv
	.type	_Z1fv, @function
_Z1fv:
.LFB0:
	movl	a(%rip), %eax
	cmpl	b(%rip), %eax
	jl	.L4
.L1:
	rep ret
.L4:
	movl	$0, %eax
	jmp	.L1
.LFE0:
	.size	_Z1fv, .-_Z1fv
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
