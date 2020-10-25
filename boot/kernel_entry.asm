global _start

[bits 32]
[extern kernel]

_start:
    call kernel
    jmp $