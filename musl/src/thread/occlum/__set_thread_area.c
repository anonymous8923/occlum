#include "pthread_impl.h"

int __set_thread_area_on_occlum(void *p);
int __set_thread_area_on_x86_64(void *p);

int __set_thread_area(void *p)
{
	if (IS_RUNNING_ON_OCCLUM)
		return __set_thread_area_on_occlum(p);
	else
		return __set_thread_area_on_x86_64(p);
}
