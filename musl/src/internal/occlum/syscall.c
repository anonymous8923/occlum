#include "libc.h"

#ifdef __OCCLUM
long __syscall_on_occlum(int num, long a, long b, long c, long d, long e, long f);
#endif
long __syscall_on_x86_64(int num, long a, long b, long c, long d, long e, long f);

long __syscall(int num, long a, long b, long c, long d, long e, long f) {
#ifdef __OCCLUM
    if (IS_RUNNING_ON_OCCLUM)
        return __syscall_on_occlum(num, a, b, c, d, e, f);
    else
#endif
        return __syscall_on_x86_64(num, a, b, c, d, e, f);
}
