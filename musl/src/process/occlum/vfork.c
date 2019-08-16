#define _GNU_SOURCE
#include <unistd.h>
#include <errno.h>
#include "libc.h"

int __vfork_on_x86_64();

pid_t vfork(void)
{
	if (IS_RUNNING_ON_OCCLUM) {
		/* Occlum does NOT support fork. Use posix_spawn instead. */
		errno = ENOSYS;
		return -1;
	}
	else {
		return __vfork_on_x86_64();
	}
}
