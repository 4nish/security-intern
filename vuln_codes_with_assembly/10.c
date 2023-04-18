/* gets vuln */
#include <stdio.h>

int main()
{
	char buf[24];
	printf("Please enter your name and press <Enter>\n");
	gets(buf);
	printf("%s", buf);
	return 0;
}

/* solution for the above problem in gets is using fgets
    it accepts input of specified length
*/
// #include <stdio.h>

// int main()
// {
// 	char buf[24];
// 	printf("Please enter your name and press <Enter>\n");
// 	fgets(buf,24,stdin);
// 	printf("%s", buf);
// 	return 0;
// }

/*
.LC0:
        .string "Please enter your name and press <Enter>"
.LC1:
        .string "%s"
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 32
        mov     edi, OFFSET FLAT:.LC0
        call    puts
        lea     rax, [rbp-32]
        mov     rdi, rax
        mov     eax, 0
        call    gets
        lea     rax, [rbp-32]
        mov     rsi, rax
        mov     edi, OFFSET FLAT:.LC1
        mov     eax, 0
        call    printf
        mov     eax, 0
        leave
        ret
*/