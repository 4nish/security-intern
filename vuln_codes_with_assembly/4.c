/* buffer overflow using heap overflow
1. Heap stores dynamic variables
*/

// 1. memory is being allocated continuosly but not freed , result in memory leakage

#include<stdio.h>
#include<stdlib.h>

int main()
{
	for (int i=0; i<10000000; i++)
	{
	// Allocating memory without freeing it
	int *ptr = (int *)malloc(sizeof(int));
	}
}

/*
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     DWORD PTR [rbp-4], 0
        jmp     .L2
.L3:
        mov     edi, 4
        call    malloc
        mov     QWORD PTR [rbp-16], rax
        add     DWORD PTR [rbp-4], 1
.L2:
        cmp     DWORD PTR [rbp-4], 9999999
        jle     .L3
        mov     eax, 0
        leave
        ret
*/


//explaination of above code
/*
main:
        push    rbp         ; Push the value of rbp onto the stack
        mov     rbp, rsp    ; Move the value of rsp (the stack pointer) into rbp (the base pointer)
        sub     rsp, 16     ; Allocate space on the stack for local variables
        mov     DWORD PTR [rbp-4], 0 ; Initialize the variable at rbp-4 to 0

        ; Jump to label .L2
        jmp     .L2

.L3:
        ; Call malloc function with argument 4 (bytes)
        mov     edi, 4
        call    malloc

        ; Move the pointer returned by malloc to rbp-16
        mov     QWORD PTR [rbp-16], rax

        ; Increment the value at rbp-4 by 1
        add     DWORD PTR [rbp-4], 1

.L2:
        ; Compare the value at rbp-4 to 9999999
        cmp     DWORD PTR [rbp-4], 9999999

        ; If the value at rbp-4 is less than or equal to 9999999, jump to label .L3
        jle     .L3

        ; If the value at rbp-4 is greater than 9999999, set eax to 0
        mov     eax, 0

        ; Clean up the stack frame and return
        leave
        ret

*/