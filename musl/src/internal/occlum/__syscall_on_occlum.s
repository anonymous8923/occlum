.text
.globl __syscall_on_occlum
.hidden __syscall_on_occlum
.type __syscall_on_occlum,@function
__syscall_on_occlum:
	// Do Occlum syscall
	movq __occlum_entry(%rip), %rax
	jmpq *%rax
	// This should never happen!
	ud2

.hidden __occlum_entry
