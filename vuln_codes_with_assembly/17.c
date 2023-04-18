/*dangling pointer*/

#include <stdio.h>
int* fun()
{
	int y = 10;
	return &y;
}

int main()
{
	int* p = fun();
	printf("%d", *p);
	return 0;
}

/*
fun:
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], 10
        mov     eax, 0
        pop     rbp
        ret
.LC0:
        .string "%d"
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     eax, 0
        call    fun
        mov     QWORD PTR [rbp-8], rax
        mov     rax, QWORD PTR [rbp-8]
        mov     eax, DWORD PTR [rax]
        mov     esi, eax
        mov     edi, OFFSET FLAT:.LC0
        mov     eax, 0
        call    printf
        mov     eax, 0
        leave
        ret
*/