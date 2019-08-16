/* Copyright 2011-2012 Nicholas J. Kain, licensed under standard MIT license */
.text
.global __unmapself_on_x86_64
.type   __unmapself_on_x86_64,@function
__unmapself_on_x86_64:
	movl $11,%eax   /* SYS_munmap */
	syscall         /* munmap(arg2,arg3) */
	xor %rdi,%rdi   /* exit() args: always return success */
	movl $60,%eax   /* SYS_exit */
	syscall         /* exit(0) */
