/* stack based buffer overflow
    we are allocating a large local memory
    1.stack store info about function calls and local variables
    */

#include <stdio.h>

int main()
{

    int n;
    printf("enter the dimensions of matrix ");
    scanf("%d", &n);
    int arr[n][n];
    printf("\nthe dimensions of matrix are %d * %d ",n,n);
    //larger values of n would result in segmentation fault
}

/*
.LC0:
        .string "enter the dimensions of matrix "
.LC1:
        .string "%d"
.LC2:
        .string "\nthe dimensions of matrix are %d * %d "
main:
        push    rbp
        mov     rbp, rsp
        push    r15
        push    r14
        push    r13
        push    r12
        push    rbx
        sub     rsp, 88
        mov     rax, rsp
        mov     rbx, rax
        mov     edi, OFFSET FLAT:.LC0
        mov     eax, 0
        call    printf
        lea     rax, [rbp-76]
        mov     rsi, rax
        mov     edi, OFFSET FLAT:.LC1
        mov     eax, 0
        call    __isoc99_scanf
        mov     ecx, DWORD PTR [rbp-76]
        mov     esi, DWORD PTR [rbp-76]
        movsx   rax, ecx
        sub     rax, 1
        mov     QWORD PTR [rbp-56], rax
        movsx   rax, ecx
        mov     QWORD PTR [rbp-128], rax
        mov     QWORD PTR [rbp-120], 0
        movsx   rax, esi
        sub     rax, 1
        mov     QWORD PTR [rbp-64], rax
        movsx   rax, ecx
        mov     QWORD PTR [rbp-96], rax
        mov     QWORD PTR [rbp-88], 0
        movsx   rax, esi
        mov     QWORD PTR [rbp-112], rax
        mov     QWORD PTR [rbp-104], 0
        mov     r8, QWORD PTR [rbp-96]
        mov     r9, QWORD PTR [rbp-88]
        mov     rdx, r9
        mov     r10, QWORD PTR [rbp-112]
        mov     r11, QWORD PTR [rbp-104]
        mov     rax, r10
        imul    rdx, rax
        mov     rax, r11
        mov     rdi, r8
        imul    rax, rdi
        lea     rdi, [rdx+rax]
        mov     rax, r8
        mul     r10
        add     rdi, rdx
        mov     rdx, rdi
        movsx   rax, ecx
        mov     r14, rax
        mov     r15d, 0
        movsx   rax, esi
        mov     r12, rax
        mov     r13d, 0
        mov     rdx, r15
        imul    rdx, r12
        mov     rax, r13
        imul    rax, r14
        lea     rdi, [rdx+rax]
        mov     rax, r14
        mul     r12
        add     rdi, rdx
        mov     rdx, rdi
        movsx   rdx, ecx
        movsx   rax, esi
        imul    rax, rdx
        lea     rdx, [0+rax*4]
        mov     eax, 16
        sub     rax, 1
        add     rax, rdx
        mov     ecx, 16
        mov     edx, 0
        div     rcx
        imul    rax, rax, 16
        sub     rsp, rax
        mov     rax, rsp
        add     rax, 3
        shr     rax, 2
        sal     rax, 2
        mov     QWORD PTR [rbp-72], rax
        mov     edx, DWORD PTR [rbp-76]
        mov     eax, DWORD PTR [rbp-76]
        mov     esi, eax
        mov     edi, OFFSET FLAT:.LC2
        mov     eax, 0
        call    printf
        mov     rsp, rbx
        mov     eax, 0
        lea     rsp, [rbp-40]
        pop     rbx
        pop     r12
        pop     r13
        pop     r14
        pop     r15
        pop     rbp
        ret
*/