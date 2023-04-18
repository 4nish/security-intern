#include <stdio.h>
#include <stdlib.h>

int *create_array(int size) {
    int *arr = (int *) malloc(size * sizeof(int));
    return arr;
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int *arr = create_array(5);
    print_array(arr, 5);

    free(arr); // deallocate memory pointed to by arr
    arr = NULL; // set arr to NULL to prevent it from being used again

    print_array(arr, 5); // using a dangling pointer here can cause undefined behavior

    return 0;
}

/*
create_array:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 32
        mov     DWORD PTR [rbp-20], edi
        mov     eax, DWORD PTR [rbp-20]
        cdqe
        sal     rax, 2
        mov     rdi, rax
        call    malloc
        mov     QWORD PTR [rbp-8], rax
        mov     rax, QWORD PTR [rbp-8]
        leave
        ret
.LC0:
        .string "%d "
print_array:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 32
        mov     QWORD PTR [rbp-24], rdi
        mov     DWORD PTR [rbp-28], esi
        mov     DWORD PTR [rbp-4], 0
        jmp     .L4
.L5:
        mov     eax, DWORD PTR [rbp-4]
        cdqe
        lea     rdx, [0+rax*4]
        mov     rax, QWORD PTR [rbp-24]
        add     rax, rdx
        mov     eax, DWORD PTR [rax]
        mov     esi, eax
        mov     edi, OFFSET FLAT:.LC0
        mov     eax, 0
        call    printf
        add     DWORD PTR [rbp-4], 1
.L4:
        mov     eax, DWORD PTR [rbp-4]
        cmp     eax, DWORD PTR [rbp-28]
        jl      .L5
        mov     edi, 10
        call    putchar
        nop
        leave
        ret
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     edi, 5
        call    create_array
        mov     QWORD PTR [rbp-8], rax
        mov     rax, QWORD PTR [rbp-8]
        mov     esi, 5
        mov     rdi, rax
        call    print_array
        mov     rax, QWORD PTR [rbp-8]
        mov     rdi, rax
        call    free
        mov     QWORD PTR [rbp-8], 0
        mov     rax, QWORD PTR [rbp-8]
        mov     esi, 5
        mov     rdi, rax
        call    print_array
        mov     eax, 0
        leave
        ret
*/