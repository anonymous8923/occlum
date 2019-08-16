#include <unistd.h>
#include "syscall.h"

/* Occlum's notes:
 * We haven't implemented llseek. So, just use lseek.
 */
#ifdef __OCCLUM
#undef SYS__llseek
#endif

off_t lseek(int fd, off_t offset, int whence)
{
#ifdef SYS__llseek
	off_t result;
	return syscall(SYS__llseek, fd, offset>>32, offset, &result, whence) ? -1 : result;
#else
	return syscall(SYS_lseek, fd, offset, whence);
#endif
}

weak_alias(lseek, lseek64);
