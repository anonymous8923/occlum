#include "libc.h"

void __unmapself_on_occlum(void *base, size_t size);
void __unmapself_on_x86_64(void *base, size_t size);

void __unmapself(void *base, size_t size)
{
	if (IS_RUNNING_ON_OCCLUM)
		return __unmapself_on_occlum(base, size);
	else
		return __unmapself_on_x86_64(base, size);
}
