/*code 1*/
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int main(int argc, char *argv[])
// {

//     // Reserve 5 byte of buffer plus the terminating NULL.
//     // should allocate 8 bytes = 2 double words,
//     // To overflow, need more than 8 bytes...
//     char buffer[5]; // If more than 8 characters input
//                     // by user, there will be access
//                     // violation, segmentation fault

//     // a prompt how to execute the program...
//     if (argc < 2)
//     {
//         printf("strcpy() NOT executed....\n");
//         printf("Syntax: %s <characters>\n", argv[0]);
//         exit(0);
//     }

//     // copy the user input to mybuffer, without any
//     // bound checking a secure version is strcpy_s()
//     strcpy(buffer, argv[1]);
//     printf("buffer content= %s\n", buffer);

//     // you may want to try strcpy_s()
//     printf("strcpy() executed...\n");

//     return 0;
// }

/*
Pattern of input:
./a.out AnishJangir
then overflow will take place
*/

/*code 2*/
// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
//     char buffer[10];
//     printf("What is your name: ");
//     scanf("%s", buffer);
//     printf("You are in, %s!\n", buffer);
//     return 0;
// }

/*code 3*/
// #include <stdio.h>

// int main()
// {

//     int n;
//     printf("enter the dimensions of matrix ");
//     scanf("%d", &n);
//     int arr[n][n];
//     printf("\nthe dimensions of matrix are %d * %d ",n,n);
//     //larger values of n would result in segmentation fault
// }

/*Possible solution for code 2 using stack canaries*/

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <time.h>

// void foo(char *str)
// {
//     char canary[4]; // 4-byte canary
//     char buffer[10];

//     // Generate random canary value
//     srand(time(NULL));
//     for (int i = 0; i < sizeof(canary); i++)
//     {
//         canary[i] = rand() % 100;
//     }

//     // Write canary to stack before buffer
//     memcpy(buffer - sizeof(canary), canary, sizeof(canary));

//     // Copy user input to buffer
//     strcpy(buffer, str);

//     // Check canary value
//     if (memcmp(buffer - sizeof(canary), canary, sizeof(canary)) != 0)
//     {
//         printf("Buffer overflow detected!\n");
//         exit(1);
//     }

//     printf("Hello, %s!\n", buffer);
// }

// int main(void)
// {
//     char input[20];
//     printf("Enter your name: ");
//     scanf("%s", input);
//     foo(input);
//     return 0;
// }

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <time.h>

// #define BUFFER_SIZE 10

// void foo(char *str)
// {
//     char buffer[BUFFER_SIZE];
//     char canary[BUFFER_SIZE];

//     // Generate random canary value
//     srand(time(NULL));
//     for (int i = 0; i < BUFFER_SIZE; i++)
//     {
//         canary[i] = rand() % 256;
//     }

//     // Write canary to stack before buffer
//     memcpy(buffer - BUFFER_SIZE, canary, BUFFER_SIZE);

//     // Copy user input to buffer
//     strncpy(buffer, str, BUFFER_SIZE - 1);
//     buffer[BUFFER_SIZE - 1] = '\0';

//     // Check canary value
//     if (memcmp(buffer - BUFFER_SIZE, canary, BUFFER_SIZE) != 0)
//     {
//         printf("Buffer overflow detected!\n");
//         exit(1);
//     }

//     printf("Hello, %s!\n", buffer);
// }

// int main(void)
// {
//     char input[20];
//     printf("Enter your name: ");
//     fgets(input, sizeof(input), stdin);
//     input[strcspn(input, "\n")] = '\0'; // remove trailing newline
//     foo(input);
//     return 0;
// }


/*code 4*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char buff[15];
    int pass = 0;

    printf("\n Enter the password : \n");
    gets(buff);

    if (strcmp(buff, "mansarovar"))
    {
        printf("\n Wrong Password \n");
    }
    else
    {
        printf("\n Correct Password \n");
        pass = 1;
    }

    if (pass)
    {
        /* Now Give root or admin rights to user*/
        printf("\n Root privileges given to the user \n");
    }

    return 0;
}
