.global __vfork_on_x86_64
.hidden __vfork_on_x86_64
.type __vfork_on_x86_64,@function
__vfork_on_x86_64:
	pop %rdx
	mov $58,%eax
	syscall
	push %rdx
	mov %rax,%rdi
	.hidden __syscall_ret
	jmp __syscall_ret
