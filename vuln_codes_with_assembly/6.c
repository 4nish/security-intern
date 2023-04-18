#include <stdio.h>
#include <string.h>

int main(void)
{
    char buff[15];
    int pass = 0;

    printf("\n Enter the password : \n");
    gets(buff);

    if (strcmp(buff, "thegeekstuff"))
    {
        printf("\n Wrong Password \n");
    }
    else
    {
        printf("\n Correct Password \n");
        pass = 1;
    }

    if (pass)
    {
        /* Now Give root or admin rights to user*/
        printf("\n Root privileges given to the user \n");
    }

    return 0;
}


// using X86-64 gcc-12.2
/*
.LC0:
        .string "\n Enter the password : "
.LC1:
        .string "thegeekstuff"
.LC2:
        .string "\n Wrong Password "
.LC3:
        .string "\n Correct Password "
.LC4:
        .string "\n Root privileges given to the user "
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 32
        mov     DWORD PTR [rbp-4], 0
        mov     edi, OFFSET FLAT:.LC0
        call    puts
        lea     rax, [rbp-19]
        mov     rdi, rax
        mov     eax, 0
        call    gets
        lea     rax, [rbp-19]
        mov     esi, OFFSET FLAT:.LC1
        mov     rdi, rax
        call    strcmp
        test    eax, eax
        je      .L2
        mov     edi, OFFSET FLAT:.LC2
        call    puts
        jmp     .L3
.L2:
        mov     edi, OFFSET FLAT:.LC3
        call    puts
        mov     DWORD PTR [rbp-4], 1
.L3:
        cmp     DWORD PTR [rbp-4], 0
        je      .L4
        mov     edi, OFFSET FLAT:.LC4
        call    puts
.L4:
        mov     eax, 0
        leave
        ret
*/