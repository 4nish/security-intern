// A C program to demonstrate buffer overflow
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	// Reserve 5 byte of buffer plus the terminating NULL.
	// should allocate 8 bytes = 2 double words,
	// To overflow, need more than 8 bytes...
	char buffer[5]; // If more than 8 characters input
						// by user, there will be access
						// violation, segmentation fault

	// a prompt how to execute the program...
	if (argc < 2)
	{
			printf("strcpy() NOT executed....\n");
			printf("Syntax: %s <characters>\n", argv[0]);
			exit(0);
	}

	// copy the user input to mybuffer, without any
	// bound checking a secure version is strcpy_s()
	strcpy(buffer, argv[1]);
	printf("buffer content= %s\n", buffer);

	// you may want to try strcpy_s()
	printf("strcpy() executed...\n");

	return 0;
}

/*
.LC0:
        .string "strcpy() NOT executed...."
.LC1:
        .string "Syntax: %s <characters>\n"
.LC2:
        .string "buffer content= %s\n"
.LC3:
        .string "strcpy() executed..."
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 32
        mov     DWORD PTR [rbp-20], edi
        mov     QWORD PTR [rbp-32], rsi
        cmp     DWORD PTR [rbp-20], 1
        jg      .L2
        mov     edi, OFFSET FLAT:.LC0
        call    puts
        mov     rax, QWORD PTR [rbp-32]
        mov     rax, QWORD PTR [rax]
        mov     rsi, rax
        mov     edi, OFFSET FLAT:.LC1
        mov     eax, 0
        call    printf
        mov     edi, 0
        call    exit
.L2:
        mov     rax, QWORD PTR [rbp-32]
        add     rax, 8
        mov     rdx, QWORD PTR [rax]
        lea     rax, [rbp-5]
        mov     rsi, rdx
        mov     rdi, rax
        call    strcpy
        lea     rax, [rbp-5]
        mov     rsi, rax
        mov     edi, OFFSET FLAT:.LC2
        mov     eax, 0
        call    printf
        mov     edi, OFFSET FLAT:.LC3
        call    puts
        mov     eax, 0
        leave
        ret
*/
