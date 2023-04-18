/*==== commnad line vuln=====*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char str[40];
	fgets(str, 39, stdin);
	system(str);
	printf("%s", str);
}

/*
.LC0:
        .string "%s"
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 48
        mov     rdx, QWORD PTR stdin[rip]
        lea     rax, [rbp-48]
        mov     esi, 39
        mov     rdi, rax
        call    fgets
        lea     rax, [rbp-48]
        mov     rdi, rax
        call    system
        lea     rax, [rbp-48]
        mov     rsi, rax
        mov     edi, OFFSET FLAT:.LC0
        mov     eax, 0
        call    printf
        mov     eax, 0
        leave
        ret
*/