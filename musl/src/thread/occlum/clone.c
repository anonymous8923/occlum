#include <stdarg.h>
#include "pthread_impl.h"

int __clone_on_occlum(int (*)(void *), void *, int, void *, ...);
int __clone_on_x86_64(int (*)(void *), void *, int, void *, ...);

int __clone(int (*func)(void *), void * stack, int flags, void * arg, ...) {
	va_list ap;
	pid_t *ptid, *ctid;
	void  *tls;

	va_start(ap, arg);
	ptid = va_arg(ap, pid_t *);
	tls  = va_arg(ap, void *);
	ctid = va_arg(ap, pid_t *);
	va_end(ap);

	if (IS_RUNNING_ON_OCCLUM)
		return __clone_on_occlum(func, stack, flags, arg, ptid, tls, ctid);
	else
		return __clone_on_x86_64(func, stack, flags, arg, ptid, tls, ctid);
}
