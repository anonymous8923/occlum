; NOTE: Assertions have been autogenerated by utils/update_llc_test_checks.py
; RUN: llc -mtriple=x86_64-linux-gnu            -global-isel -verify-machineinstrs < %s -o - | FileCheck %s --check-prefix=ALL

define i8 @test() {
; ALL-LABEL: test:
; ALL:       # %bb.0:
; ALL-NEXT:    retq
  ret i8 undef
}

define i8 @test2(i8 %a) {
; ALL-LABEL: test2:
; ALL:       # %bb.0:
; ALL-NEXT:    movl %edi, %eax
; ALL-NEXT:    addb %al, %al
; ALL-NEXT:    # kill: def $al killed $al killed $eax
; ALL-NEXT:    retq
  %r = add i8 %a, undef
  ret i8 %r
}


define float @test3() {
; ALL-LABEL: test3:
; ALL:       # %bb.0:
; ALL-NEXT:    retq
  ret float undef
}

define float @test4(float %a) {
; ALL-LABEL: test4:
; ALL:       # %bb.0:
; ALL-NEXT:    addss %xmm0, %xmm0
; ALL-NEXT:    retq
  %r = fadd float %a, undef
  ret float %r
}
