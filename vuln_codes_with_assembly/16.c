/* null pointer derefencing*/
#include <stdio.h>

int main()
{
	int val = 1;
	int* p = NULL;
	*p = val;
	printf("%d", *p);
	return 0;
}

/*
.LC0:
        .string "%d"
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     DWORD PTR [rbp-4], 1
        mov     QWORD PTR [rbp-16], 0
        mov     rax, QWORD PTR [rbp-16]
        mov     edx, DWORD PTR [rbp-4]
        mov     DWORD PTR [rax], edx
        mov     rax, QWORD PTR [rbp-16]
        mov     eax, DWORD PTR [rax]
        mov     esi, eax
        mov     edi, OFFSET FLAT:.LC0
        mov     eax, 0
        call    printf
        mov     eax, 0
        leave
        ret
*/