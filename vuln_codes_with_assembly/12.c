#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        exit(1);
    }

    char buffer[10]; // buffer of size 10 to hold user input
    strcpy(buffer, argv[1]); // copy user input to buffer without validating its size

    printf("Input string: %s\n", buffer); // print the input string

    // format string vulnerability
    printf("User input: ");
    printf("%s",argv[1]); // user input is passed as a format string, which can be exploited by an attacker
    printf("\n");

    return 0;
}

/*
.LC0:
        .string "Usage: %s <string>\n"
.LC1:
        .string "Input string: %s\n"
.LC2:
        .string "User input: "
.LC3:
        .string "%s"
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 32
        mov     DWORD PTR [rbp-20], edi
        mov     QWORD PTR [rbp-32], rsi
        cmp     DWORD PTR [rbp-20], 1
        jg      .L2
        mov     rax, QWORD PTR [rbp-32]
        mov     rax, QWORD PTR [rax]
        mov     rsi, rax
        mov     edi, OFFSET FLAT:.LC0
        mov     eax, 0
        call    printf
        mov     edi, 1
        call    exit
.L2:
        mov     rax, QWORD PTR [rbp-32]
        add     rax, 8
        mov     rdx, QWORD PTR [rax]
        lea     rax, [rbp-10]
        mov     rsi, rdx
        mov     rdi, rax
        call    strcpy
        lea     rax, [rbp-10]
        mov     rsi, rax
        mov     edi, OFFSET FLAT:.LC1
        mov     eax, 0
        call    printf
        mov     edi, OFFSET FLAT:.LC2
        mov     eax, 0
        call    printf
        mov     rax, QWORD PTR [rbp-32]
        add     rax, 8
        mov     rax, QWORD PTR [rax]
        mov     rsi, rax
        mov     edi, OFFSET FLAT:.LC3
        mov     eax, 0
        call    printf
        mov     edi, 10
        call    putchar
        mov     eax, 0
        leave
        ret
*/