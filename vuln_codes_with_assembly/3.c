// non terminating recursive function
#include <stdio.h>

void fun(int x)
{
    if (x == 1)
        return;
    x = 6;
    fun(x);
}

int main()
{
    int x = 5;
    fun(x);
}

/*
fun:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     DWORD PTR [rbp-4], edi
        cmp     DWORD PTR [rbp-4], 1
        je      .L4
        mov     DWORD PTR [rbp-4], 6
        mov     eax, DWORD PTR [rbp-4]
        mov     edi, eax
        call    fun
        jmp     .L1
.L4:
        nop
.L1:
        leave
        ret
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     DWORD PTR [rbp-4], 5
        mov     eax, DWORD PTR [rbp-4]
        mov     edi, eax
        call    fun
        mov     eax, 0
        leave
        ret
*/


//explanation of above code
/*
fun:
        push    rbp             ; Push the current base pointer onto the stack
        mov     rbp, rsp        ; Move the stack pointer to the base pointer
        sub     rsp, 16         ; Allocate 16 bytes of space on the stack for local variables
        mov     DWORD PTR [rbp-4], edi   ; Move the function argument to the local variable
        cmp     DWORD PTR [rbp-4], 1     ; Compare the value of the local variable with 1
        je      .L4             ; Jump to .L4 if the values are equal
        mov     DWORD PTR [rbp-4], 6    ; Move the value 6 to the local variable
        mov     eax, DWORD PTR [rbp-4]  ; Move the value of the local variable to the EAX register
        mov     edi, eax        ; Move the value of EAX to the EDI register
        call    fun             ; Call the function again with the new value of x
        jmp     .L1             ; Jump to .L1
.L4:
        nop                     ; Do nothing
.L1:
        leave                   ; Deallocate the stack frame and restore the previous base pointer
        ret                     ; Return from the function

main:
        push    rbp             ; Push the current base pointer onto the stack
        mov     rbp, rsp        ; Move the stack pointer to the base pointer
        sub     rsp, 16         ; Allocate 16 bytes of space on the stack for local variables
        mov     DWORD PTR [rbp-4], 5   ; Move the value 5 to the local variable
        mov     eax, DWORD PTR [rbp-4]  ; Move the value of the local variable to the EAX register
        mov     edi, eax        ; Move the value of EAX to the EDI register
        call    fun             ; Call the function with the value of x
        mov     eax, 0          ; Move the value 0 to the EAX register
        leave                   ; Deallocate the stack frame and restore the previous base pointer
        ret                     ; Return from the function

*/