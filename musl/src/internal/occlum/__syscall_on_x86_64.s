.global __syscall_on_x86_64
.hidden __syscall_on_x86_64
.type __syscall_on_x86_64,@function
__syscall_on_x86_64:
	movq %rdi,%rax
	movq %rsi,%rdi
	movq %rdx,%rsi
	movq %rcx,%rdx
	movq %r8,%r10
	movq %r9,%r8
	movq 8(%rsp),%r9
	syscall
	ret
