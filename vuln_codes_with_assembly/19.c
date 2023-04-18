/* array index out of bound*/
#include <stdio.h>
int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	printf("arr [0] is %d\n", arr[0]);
	printf("arr[10] is %d\n", arr[10]);

	arr[10] = 11;
	printf("arr[10] is %d\n", arr[10]);
	return 0;
}

/*
.LC0:
        .string "arr [0] is %d\n"
.LC1:
        .string "arr[10] is %d\n"
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 32
        mov     DWORD PTR [rbp-32], 1
        mov     DWORD PTR [rbp-28], 2
        mov     DWORD PTR [rbp-24], 3
        mov     DWORD PTR [rbp-20], 4
        mov     DWORD PTR [rbp-16], 5
        mov     eax, DWORD PTR [rbp-32]
        mov     esi, eax
        mov     edi, OFFSET FLAT:.LC0
        mov     eax, 0
        call    printf
        mov     eax, DWORD PTR [rbp+8]
        mov     esi, eax
        mov     edi, OFFSET FLAT:.LC1
        mov     eax, 0
        call    printf
        mov     DWORD PTR [rbp+8], 11
        mov     eax, DWORD PTR [rbp+8]
        mov     esi, eax
        mov     edi, OFFSET FLAT:.LC1
        mov     eax, 0
        call    printf
        mov     eax, 0
        leave
        ret
*/