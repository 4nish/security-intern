// // A C program to demonstrate buffer overflow
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int main(int argc, char *argv[])
// {

// 	// Reserve 5 byte of buffer plus the terminating NULL.
// 	// should allocate 8 bytes = 2 double words,
// 	// To overflow, need more than 8 bytes...
// 	char buffer[5]; // If more than 8 characters input
// 						// by user, there will be access
// 						// violation, segmentation fault

// 	// a prompt how to execute the program...
// 	if (argc < 2)
// 	{
// 			printf("strcpy() NOT executed....\n");
// 			printf("Syntax: %s <characters>\n", argv[0]);
// 			exit(0);
// 	}

// 	// copy the user input to mybuffer, without any
// 	// bound checking a secure version is strcpy_s()
// 	strcpy(buffer, argv[1]);
// 	printf("buffer content= %s\n", buffer);

// 	// you may want to try strcpy_s()
// 	printf("strcpy() executed...\n");

// 	return 0;
// }

/* stack based buffer overflow
    we are allocating a large local memory
    1.stack store info about function calls and local variables
    */

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

// // non terminating recursive function
// #include <stdio.h>

// void fun(int x)
// {
//     if (x == 1)
//         return;
//     x = 6;
//     fun(x);
// }

// int main()
// {
//     int x = 5;
//     fun(x);
// }

/* buffer overflow using heap overflow
1. Heap stores dynamic variables
*/

// 1. memory is being allocated continuosly but not freed , result in memory leakage

// #include<stdio.h>
// #include<stdlib.h>

// int main()
// {
// 	for (int i=0; i<10000000; i++)
// 	{
// 	// Allocating memory without freeing it
// 	int *ptr = (int *)malloc(sizeof(int));
// 	}
// }

// by allocating large memory
// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
// 	int *ptr = (int *)malloc(sizeof(int)*10000000);
// }

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
//     char buff[15];
//     int pass = 0;

//     printf("\n Enter the password : \n");
//     gets(buff);

//     if (strcmp(buff, "thegeekstuff"))
//     {
//         printf("\n Wrong Password \n");
//     }
//     else
//     {
//         printf("\n Correct Password \n");
//         pass = 1;
//     }

//     if (pass)
//     {
//         /* Now Give root or admin rights to user*/
//         printf("\n Root privileges given to the user \n");
//     }

//     return 0;
// }

/* integer overflow examples
 */

// #include <stdio.h>

// int main()
// {
//     int x = 2147483647; // maximum value of a 32-bit signed integer
//     x = x + 1;          // add 1 to x, causing an integer overflow
//     printf("%d\n", x);  // expected output: -2147483648
//     return 0;
// }

// /*  heap overflow */
// #include <stdlib.h>
// #include <stdio.h>

// int main()
// {
//     int *x = malloc(sizeof(int) * 2);                          // allocate memory for 2 integers
//     x[0] = 1;                                                  // assign value to the first integer
//     x[1] = 2;                                                  // assign value to the second integer
//     printf("Before overflow: x[0]=%d, x[1]=%d\n", x[0], x[1]); // expected output: x[0]=1, x[1]=2

//     int *y = x + 3; // point to the memory location 3 integers away from the start of x
//     *y = 3;         // write a value to the memory location pointed by y, causing a heap overflow

//     printf("After overflow: x[0]=%d, x[1]=%d\n", x[0], x[1]); // unexpected output: x[0]=1, x[1]=2 or program may crash

//     free(x); // free the allocated memory
//     return 0;
// }

// /* stack overflow*/
// #include <stdio.h>

// void recursive_function(int x) {
//     printf("x = %d, address of x = %p\n", x, &x);
//     recursive_function(x + 1); // recursively call the function with an incremented value of x
// }

// int main() {
//     int x = 0;
//     recursive_function(x); // call the recursive function with initial value of x

//     return 0;
// }


// /* gets vuln */
// #include <stdio.h>

// int main()
// {
// 	char buf[24];
// 	printf("Please enter your name and press <Enter>\n");
// 	gets(buf);
// 	printf("%s", buf);
// 	return 0;
// }

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


/* vuln regarding string */
// #include <stdio.h>
// #include <string.h>
// #define BUFFER_SIZE 10

// // Driver code
// int main()
// {
// 	// 24 is the buffer size
// 	char str1[BUFFER_SIZE];
// 	char str2[] = "GeeksforGeeks";

// 	// Limits number of characters
// 	// to be copied
// 	strncpy(str1, str2, BUFFER_SIZE);
// 	printf("Copied string is: %s\n", str1);
// 	return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main(int argc, char *argv[]) {
//     if (argc < 2) {
//         printf("Usage: %s <string>\n", argv[0]);
//         exit(1);
//     }

//     char buffer[10]; // buffer of size 10 to hold user input
//     strcpy(buffer, argv[1]); // copy user input to buffer without validating its size

//     printf("Input string: %s\n", buffer); // print the input string

//     // format string vulnerability
//     printf("User input: ");
//     printf("%s",argv[1]); // user input is passed as a format string, which can be exploited by an attacker
//     printf("\n");

//     return 0;
// }


/*==== commnad line vuln=====*/

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// int main()
// {
// 	char str[40];
// 	fgets(str, 39, stdin);
// 	system(str);
// 	printf("%s", str);
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main(int argc, char *argv[]) {
//     if (argc < 2) {
//         printf("Usage: %s <filename>\n", argv[0]);
//         exit(1);
//     }

//     char buffer[100]; // buffer to hold user input
//     sprintf(buffer, "rm %s", argv[1]); // construct a command to delete the file specified by the user
//     system(buffer); // execute the command

//     printf("File '%s' deleted successfully!\n", argv[1]);

//     return 0;
// }

// //improved version of above code is
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>

// int main(int argc, char *argv[]) {
//     if (argc < 2) {
//         printf("Usage: %s <filename>\n", argv[0]);
//         exit(1);
//     }

//     char buffer[100]; // buffer to hold user input
//     char *filename = argv[1];

//     // Check if the filename contains any illegal characters
//     char *illegal_chars = "`|&;<>()$`\\\"' \t\n";
//     if (strpbrk(filename, illegal_chars) != NULL) {
//         printf("Invalid filename specified\n");
//         exit(1);
//     }

//     // Check if the file exists and is writable
//     if (access(filename, W_OK) == -1) {
//         printf("Unable to delete file '%s': %s\n", filename, strerror(errno));
//         exit(1);
//     }

//     // Construct the command to delete the file
//     sprintf(buffer, "rm %s", filename);

//     // Change to the home directory to avoid deleting unintended files
//     chdir(getenv("HOME"));

//     // Execute the command
//     system(buffer);

//     printf("File '%s' deleted successfully!\n", filename);

//     return 0;
// }


/* null pointer derefencing*/
// #include <stdio.h>

// int main()
// {
// 	int val = 1;
// 	int* p = NULL;
// 	*p = val;
// 	printf("%d", *p);
// 	return 0;
// }


/*dangling pointer*/

// #include <stdio.h>
// int* fun()
// {
// 	int y = 10;
// 	return &y;
// }

// int main()
// {
// 	int* p = fun();
// 	printf("%d", *p);
// 	return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// int *create_array(int size) {
//     int *arr = (int *) malloc(size * sizeof(int));
//     return arr;
// }

// void print_array(int *arr, int size) {
//     for (int i = 0; i < size; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// int main() {
//     int *arr = create_array(5);
//     print_array(arr, 5);

//     free(arr); // deallocate memory pointed to by arr
//     arr = NULL; // set arr to NULL to prevent it from being used again

//     print_array(arr, 5); // using a dangling pointer here can cause undefined behavior

//     return 0;
// }


/* array index out of bound*/
// #include <stdio.h>
// int main()
// {
// 	int arr[] = { 1, 2, 3, 4, 5 };
// 	printf("arr [0] is %d\n", arr[0]);
// 	printf("arr[10] is %d\n", arr[10]);

	
// 	arr[10] = 11;
// 	printf("arr[10] is %d\n", arr[10]);
// 	return 0;
// }
