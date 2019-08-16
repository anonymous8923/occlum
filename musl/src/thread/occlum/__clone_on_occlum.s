.text
.global __child_start_on_occlum
.hidden __child_start_on_occlum
.type   __child_start_on_occlum,@function
__child_start_on_occlum:
    // 16(%rsp) - void* args
    mov 16(%rsp), %rdi
    // 8(%rsp)  - int(*func)(void*)
    mov 8(%rsp), %rcx
    // Make %rsp 16-aligned before call
    and $-16, %rsp
    // Call user-given thread function
    call *%rcx

    // Call exit syscall
    //  int syscall_num - %rdi
    //  int exit_code - %rsi
    mov $60, %rdi
    mov %rax, %rsi
    call __syscall

    // This should never happen!
    hlt

.text
.global __clone_on_occlum
.hidden __clone_on_occlum
.type   __clone_on_occlum,@function
__clone_on_occlum:
    // Func args:
    //  int(*func)(void*) - %rdi
    //  void* stack - %rsi
    //  int flags   - %rdx
    //  void* args  - %rcx
    //  int* ptid   - %r8
    //  unsigned long newtls - %r9
    //  int* ctid   - *0x8(%rsp)

    //
    // Pass args to the stack of the child
    //
    // Save child stack addr into another scratch register
    mov %rsi, %r10
    // Make child stack addr 16-byte aligned initially
    and $-16, %r10
    // Push args into the stack of the child
    sub $8, %r10
    mov %rcx, (%r10)
    // Push func into the stack of the child
    sub $8, %r10
    mov %rdi, (%r10)
    // Push "return address" for syscall
    // LibOS will find the entry point of the child by popping
    // the value from the top of the stack of the new thread.
    sub $8, %r10
    mov __child_start_on_occlum@GOTPCREL(%rip), %r11
    mov %r11, (%r10)

    //
    // Pass args to regiters
    //
    // The syscall number of clone is 56
    mov $56, %rdi
    // Pass flags
    mov %rdx, %rsi
    // Pass child stack addr
    mov %r10, %rdx
    // Pass ptid
    mov %r8, %rcx
    // Pass ctid
    mov 8(%rsp), %r8
    // Pass newtls
    // mov %r9, %r9

    //
    // Call clone syscall
    //
    //  int num              - %rdi
    //  unsigned long flags  - %rsi
    //  void* stack          - %rdx
    //  int* ptid            - %rcx
    //  int* ctid            - %r8
    //  unsigned long newtls - %r9
    call __syscall
    ret
