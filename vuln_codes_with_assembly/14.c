#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char buffer[100]; // buffer to hold user input
    sprintf(buffer, "rm %s", argv[1]); // construct a command to delete the file specified by the user
    system(buffer); // execute the command

    printf("File '%s' deleted successfully!\n", argv[1]);

    return 0;
}

/*
.LC0:
        .string "Usage: %s <filename>\n"
.LC1:
        .string "rm %s"
.LC2:
        .string "File '%s' deleted successfully!\n"
main:
        push    rbp
        mov     rbp, rsp
        add     rsp, -128
        mov     DWORD PTR [rbp-116], edi
        mov     QWORD PTR [rbp-128], rsi
        cmp     DWORD PTR [rbp-116], 1
        jg      .L2
        mov     rax, QWORD PTR [rbp-128]
        mov     rax, QWORD PTR [rax]
        mov     rsi, rax
        mov     edi, OFFSET FLAT:.LC0
        mov     eax, 0
        call    printf
        mov     edi, 1
        call    exit
.L2:
        mov     rax, QWORD PTR [rbp-128]
        add     rax, 8
        mov     rdx, QWORD PTR [rax]
        lea     rax, [rbp-112]
        mov     esi, OFFSET FLAT:.LC1
        mov     rdi, rax
        mov     eax, 0
        call    sprintf
        lea     rax, [rbp-112]
        mov     rdi, rax
        call    system
        mov     rax, QWORD PTR [rbp-128]
        add     rax, 8
        mov     rax, QWORD PTR [rax]
        mov     rsi, rax
        mov     edi, OFFSET FLAT:.LC2
        mov     eax, 0
        call    printf
        mov     eax, 0
        leave
        ret
*/