/*************** gets vuln
solution: use fgets
 */
/*********************code 1****************************/
// #include <stdio.h>

// int main()
// {
// 	char buf[10];
// 	printf("Please enter your name\n");
// 	gets(buf);
// 	printf("%s", buf);
// 	return 0;
// }

/********************code 2******************/
/*********************** array index out of bound******************/
// #include <stdio.h>
// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5};
//     printf("arr [0] is %d\n", arr[0]);
//     printf("arr[10] is %d\n", arr[10]);

//     arr[10] = 11;
//     printf("arr[10] is %d\n", arr[10]);
//     return 0;
// }

/*********code 3 Strcpy*********/
// #include <stdio.h>
// int main()
// {
//     char s1[10];
//     char s2[12];
//     printf("enter the string\n");
//     scanf("%s", s2);
//     strcpy(s1, s2); // strcpy does perform bounds checking
//     printf("s1 is %s\n", s1);
//     return 0;
// }

/**************code 4 Strcat*****************/
// #include <stdio.h>
// int main()
// {
//     char s1[10];
//     char s2[12];
//     printf("enter the string\n");
//     scanf("%s", s2);
//     strcat(s1, s2); // strcat does perform bounds checking
//     printf("s1 is %s\n", s1);
//     return 0;
// }

/****************code 4 Strncpy****************/
// Strncpy is safer than Strcpy however it can be vulnerable to buffer overflow if the size of the destination string is not specified correctly.
/*
In this example, the source string is longer than the destination buffer. When strncpy is used to copy the source string to the destination buffer, it will copy only the first sizeof(dest) characters of the source string to the destination buffer, but will not null-terminate the destination buffer if the source string is longer than sizeof(dest).

This means that the dest buffer will not contain a null terminator and may contain a partial or complete copy of the source string beyond its intended length, potentially overwriting other data on the stack or heap.

To avoid this vulnerability, it is important to always ensure that the destination buffer is large enough to hold the entire source string, including the null terminator.
*/
// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char source[] = "I am student of engineering and also a badminon player";
//     char dest[10];
//     strncpy(dest, source, sizeof(dest));
//     printf("%s\n", dest);
//     return 0;
// }

/*******************A better alternative to Strncpy is Strlcpy***************/
/*Unlike strncpy, strlcpy always null-terminates the destination buffer, and it also ensures that the copy operation does not write beyond the end of the destination buffer.

The strlcpy function returns the length of the source string (i.e., the number of characters it tried to copy), so we can check if the destination buffer was large enough to hold the entire source string by comparing the return value to the size of the destination buffer.*/
// #include <stdio.h>
// #include <string.h>

// #define DEST_SIZE 10

// int main()
// {
//     char source[] = "I am student of engineering and also a badminon player";
//     char dest[DEST_SIZE];
//     size_t len = strlcpy(dest, source, sizeof(dest));
//     if (len >= sizeof(dest))
//     {
//         printf("Destination buffer too small!\n");
//     }
//     else
//     {
//         printf("%s\n", dest);
//     }
//     return 0;
// }

/**********code 5 Strcmp*********/
// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char buffer[10];
//     char *password = "password";
//     printf("Enter your password: ");
//     scanf("%s", buffer);
//     if (strcmp(buffer, password) == 0)
//     {
//         printf("Access granted.\n");
//     }
//     else
//     {
//         printf("Access denied.\n");
//     }
//     return 0;
// }

/**************code 6 Strncmp*************/
// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char password[10] = "password";
//     char input[20];
//     printf("Enter your password: ");
//     scanf("%s", input);
//     if (strncmp(input, password, strlen(input)) == 0)
//     {
//         printf("Access granted.\n");
//     }
//     else
//     {
//         printf("Access denied.\n");
//     }
//     return 0;
// }
/*if the user enters a string that is longer than the password array (which is only 10 bytes long), the strncmp function will read past the end of the password array and into adjacent memory.

An attacker can exploit this vulnerability by inputting a string that is longer than 10 bytes. This will cause strncmp to read past the end of the password array and potentially overwrite sensitive data or cause a segmentation fault.*/

/****************code 7 memcpy*******************/
// #include <stdio.h>
// #include <string.h>

// void copy_string(char *dst, char *src, int len)
// {
//     memcpy(dst, src, len);
//     printf("Copied string: %s\n", dst);
// }

// int main()
// {
//     char buf[10];
//     char input[20];
//     printf("Enter a string: ");
//     scanf("%s", input);
//     copy_string(buf, input, strlen(input));
//     return 0;
// }

// cause undefined behaviour

/***************code 8 memset****************/
#include <stdio.h>
#include <string.h>

void fun(char *s1, char *s2)
{
    memset(s1, 0, 10);
    strcpy(s1, s2);
    printf("s1 is %s\n", s1);
}
int main()
{
    char buf[10];
    char s1[8];
    memset(buf, 0, sizeof(buf));
    printf("Enter a string: ");
    scanf("%s", buf);
    printf("String: %s\n", buf);
    fun(buf, s1);
    return 0;
}
