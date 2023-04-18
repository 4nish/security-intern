/* vuln regarding string */
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 10

// Driver code
int main()
{
    // 24 is the buffer size
    char str1[BUFFER_SIZE];
    char str2[] = "GeeksforGeeks";

    // Limits number of characters
    // to be copied
    strncpy(str1, str2, BUFFER_SIZE);
    printf("Copied string is: %s\n", str1);
    return 0;
}

/*
.LC0:
        .string "Copied string is: %s\n"
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 32
        movabs  rax, 8245922088647746887
        mov     QWORD PTR [rbp-24], rax
        movabs  rax, 32487705556775535
        mov     QWORD PTR [rbp-18], rax
        lea     rcx, [rbp-24]
        lea     rax, [rbp-10]
        mov     edx, 10
        mov     rsi, rcx
        mov     rdi, rax
        call    strncpy
        lea     rax, [rbp-10]
        mov     rsi, rax
        mov     edi, OFFSET FLAT:.LC0
        mov     eax, 0
        call    printf
        mov     eax, 0
        leave
        ret
*/


// explanation of above code
/*
.LC0:
    .string "Copied string is: %s\n"  # Define string constant with label ".LC0"

main:
    push    rbp         # Push base pointer onto stack
    mov     rbp, rsp    # Move stack pointer to base pointer to make room for local variables
    sub     rsp, 32     # Make room for local variables on the stack

    # Load two 64-bit constants into registers rax and rbx and store them in memory at offsets -24 and -18 from the base pointer, respectively
    movabs  rax, 8245922088647746887
    mov     QWORD PTR [rbp-24], rax
    movabs  rax, 32487705556775535
    mov     QWORD PTR [rbp-18], rax

    # Load address of the first constant into register rcx and the address of a buffer on the stack into register rax
    lea     rcx, [rbp-24]
    lea     rax, [rbp-10]

    # Call strncpy function with arguments rcx, rax, 10 to copy 10 bytes from memory location rcx to memory location rax
    mov     edx, 10
    mov     rsi, rcx
    mov     rdi, rax
    call    strncpy

    # Load address of buffer on the stack into register rax and address of the string constant ".LC0" into register edi
    lea     rax, [rbp-10]
    mov     rsi, rax
    mov     edi, OFFSET FLAT:.LC0

    # Call printf function with arguments rsi and edi to print the formatted string to stdout
    mov     eax, 0
    call    printf

    mov     eax, 0     # Set return value to 0
    leave             # Release stack frame
    ret               # Return from function

*/