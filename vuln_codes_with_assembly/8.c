// /*  heap overflow */
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int *x = malloc(sizeof(int) * 2);                          // allocate memory for 2 integers
    x[0] = 1;                                                  // assign value to the first integer
    x[1] = 2;                                                  // assign value to the second integer
    printf("Before overflow: x[0]=%d, x[1]=%d\n", x[0], x[1]); // expected output: x[0]=1, x[1]=2

    int *y = x + 3; // point to the memory location 3 integers away from the start of x
    *y = 3;         // write a value to the memory location pointed by y, causing a heap overflow

    printf("After overflow: x[0]=%d, x[1]=%d\n", x[0], x[1]); // unexpected output: x[0]=1, x[1]=2 or program may crash

    free(x); // free the allocated memory
    return 0;
}

/*
.LC0:
        .string "Before overflow: x[0]=%d, x[1]=%d\n"
.LC1:
        .string "After overflow: x[0]=%d, x[1]=%d\n"
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     edi, 8
        call    malloc
        mov     QWORD PTR [rbp-8], rax
        mov     rax, QWORD PTR [rbp-8]
        mov     DWORD PTR [rax], 1
        mov     rax, QWORD PTR [rbp-8]
        add     rax, 4
        mov     DWORD PTR [rax], 2
        mov     rax, QWORD PTR [rbp-8]
        add     rax, 4
        mov     edx, DWORD PTR [rax]
        mov     rax, QWORD PTR [rbp-8]
        mov     eax, DWORD PTR [rax]
        mov     esi, eax
        mov     edi, OFFSET FLAT:.LC0
        mov     eax, 0
        call    printf
        mov     rax, QWORD PTR [rbp-8]
        add     rax, 12
        mov     QWORD PTR [rbp-16], rax
        mov     rax, QWORD PTR [rbp-16]
        mov     DWORD PTR [rax], 3
        mov     rax, QWORD PTR [rbp-8]
        add     rax, 4
        mov     edx, DWORD PTR [rax]
        mov     rax, QWORD PTR [rbp-8]
        mov     eax, DWORD PTR [rax]
        mov     esi, eax
        mov     edi, OFFSET FLAT:.LC1
        mov     eax, 0
        call    printf
        mov     rax, QWORD PTR [rbp-8]
        mov     rdi, rax
        call    free
        mov     eax, 0
        leave
        ret
*/