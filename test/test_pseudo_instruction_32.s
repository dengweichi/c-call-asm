;定义为32位程序
bits 32

section .data
EXTERN  externVar
section .data

section .text
global testExternFun
testExternFun:
    mov dword [externVar],1
    ret
section .text


section .data
global testGlobalVar
testGlobalVar dd 1
section .data

section .text
global testGlobalFun
testGlobalFun:
    mov eax,1
    ret
section .text

section .data
equArray db '123456'
equArrayLength EQU $-equArray
section .data

section .text
global testEquFun
testEquFun:
    mov eax, equArrayLength
    ret
section .text

section .data
timesArray times 10 db '1'
timesArrayLength EQU $-timesArray
section .data

section .text
global testTimesFun
testTimesFun:
    mov eax, timesArrayLength
    ret
section .text
