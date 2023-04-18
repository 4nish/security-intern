// /* stack overflow*/
#include <stdio.h>

void recursive_function(int x) {
    printf("x = %d, address of x = %p\n", x, &x);
    recursive_function(x + 1); // recursively call the function with an incremented value of x
}

int main() {
    int x = 0;
    recursive_function(x); // call the recursive function with initial value of x

    return 0;
}

/*
.LC0:
        .string "x = %d, address of x = %p\n"
recursive_function:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     DWORD PTR [rbp-4], edi
        mov     eax, DWORD PTR [rbp-4]
        lea     rdx, [rbp-4]
        mov     esi, eax
        mov     edi, OFFSET FLAT:.LC0
        mov     eax, 0
        call    printf
        mov     eax, DWORD PTR [rbp-4]
        add     eax, 1
        mov     edi, eax
        call    recursive_function
        nop
        leave
        ret
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     DWORD PTR [rbp-4], 0
        mov     eax, DWORD PTR [rbp-4]
        mov     edi, eax
        call    recursive_function
        mov     eax, 0
        leave
        ret
*/