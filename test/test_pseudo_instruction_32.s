;定义为32位程序
bits 32

section .data
EXTERN  externVar
section .data

section .text
global testExternFun
testExternFun:
    mov eax,1
    mov [externVar],eax
    ret
section .text
