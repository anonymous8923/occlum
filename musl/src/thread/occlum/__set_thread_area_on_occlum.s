.text
.global __set_thread_area_on_occlum
.hidden __set_thread_area_on_occlum
.type __set_thread_area_on_occlum,@function
__set_thread_area_on_occlum:
    // Func args:
    //  void* addr - %rdi

    // Make %rsp 16-aligned before call
    sub $8, %rsp

    // Pass addr
    mov %rdi, %rdx
    // Pass SET_FS
    mov $158, %edi
    // Pass syscall num
    mov $0x1002, %esi
    // arch_prctl syscall args:
    //  int num     - %rdi
    //  int code    - %rsi
    //  void* addr  - %rdx
    call __syscall

    // Restore %rsp
    add $8, %rsp

    ret
