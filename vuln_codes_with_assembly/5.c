// by allocating large memory
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *ptr = (int *)malloc(sizeof(int)*10000000);
}

/*
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     edi, 40000000
        call    malloc
        mov     QWORD PTR [rbp-8], rax
        mov     eax, 0
        leave
        ret
*/