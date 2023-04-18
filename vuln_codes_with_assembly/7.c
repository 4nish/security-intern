/* integer overflow examples
 */

#include <stdio.h>

int main()
{
    int x = 2147483647; // maximum value of a 32-bit signed integer
    x = x + 1;          // add 1 to x, causing an integer overflow
    printf("%d\n", x);  // expected output: -2147483648
    return 0;
}

/*
.LC0:
        .string "%d\n"
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     DWORD PTR [rbp-4], 2147483647
        add     DWORD PTR [rbp-4], 1
        mov     eax, DWORD PTR [rbp-4]
        mov     esi, eax
        mov     edi, OFFSET FLAT:.LC0
        mov     eax, 0
        call    printf
        mov     eax, 0
        leave
        ret
*/