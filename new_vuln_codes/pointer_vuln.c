/* Null pointer dereference vulnerability */

/*code 1*/
// #include <stdio.h>

// int main()
// {
//     int *ptr = NULL; // Initialize a pointer to NULL
//     *ptr = 10;       // Dereference a null pointer
//     printf("Value: %d", *ptr);
//     return 0;
//     //cause segmentation fault
// }

/*code 2*/
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct
// {
//     char *name;
//     int age;
// } Person;

// int main()
// {
//     Person *person_ptr = NULL;
//     char *name_ptr;

//     // person_ptr = (Person *)malloc(sizeof(Person));
//     name_ptr = (char *)malloc(sizeof(char) * 20);

//     printf("Enter your name: ");
//     scanf("%s", name_ptr);

//     person_ptr->name = name_ptr; // Null pointer dereference

//     printf("Enter your age: ");
//     scanf("%d", &person_ptr->age);

//     printf("Name: %s, Age: %d\n", person_ptr->name, person_ptr->age);

//     free(name_ptr);
//     free(person_ptr);

//     return 0;
// }

// /*pointer arithmetic errors*/
/*code 3
it is possible that the operating system and the compiler allowed the program to access memory outside the bounds of the allocated array without causing a segmentation fault. However, this behavior is undefined and unpredictable, and should not be relied upon in real-world applications.
*/

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     int num_elements = 5;
//     int *arr = malloc(num_elements * sizeof(int)); // Allocate memory for an array of integers

//     // Fill the array with some values
//     for (int i = 0; i < num_elements; i++)
//     {
//         arr[i] = i + 1;
//     }

//     // Use pointer arithmetic to access elements of the array
//     int *ptr = arr + 2; // Set the pointer to point to the third element of the array
//     printf("Value at ptr: %d\n", *ptr);

//     // Try to access an element outside the bounds of the array
//     ptr = arr + 5;                      // Set the pointer to point to the sixth element of the array
//     printf("Value at ptr: %d\n", *ptr); // Error: pointer arithmetic outside the bounds of the array

//     // Free the memory allocated for the array
//     free(arr);

//     return 0;
// }

/*use after free*/

/*code 4
In your specific case, the behavior you are observing may be due to the fact that the memory pointed to by p has not been immediately overwritten by other data since it was freed, so the *p = 20 statement may still be writing to a valid memory location. However, this behavior is not guaranteed, and running this code on a different system or with different inputs may result in a segmentation fault or other unexpected behavior.
*/
// #include <stdlib.h>
// #include <stdio.h>

// int main()
// {
//     int *p = malloc(sizeof(int));   // allocate memory for an integer
//     *p = 10;                        // store a value in the memory location pointed to by p
//     printf("Value of p: %d\n", *p); // print the value of p

//     free(p); // free the memory pointed to by p

//     *p = 20;                                   // try to access the memory location pointed to by p (use-after-free error)
//     printf("Value of p after free: %d\n", *p); // print the value of p

//     return 0;
// }

/*code 5*/
// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>

// #define MAX_USERS 100

// typedef struct
// {
//     char *name;
//     int age;
// } User;

// void addUser(User *users[], int *numUsers)
// {
//     char name[50];
//     int age;

//     // Get user's name and age from user input
//     printf("Enter user's name: ");
//     scanf("%s", name);
//     printf("Enter user's age: ");
//     scanf("%d", &age);

//     // Allocate memory for the new user's name and copy it over
//     char *nameCopy = malloc(sizeof(char) * (strlen(name) + 1));
//     strcpy(nameCopy, name);

//     // Allocate memory for the new user and set its fields
//     User *newUser = malloc(sizeof(User));
//     newUser->name = nameCopy;
//     newUser->age = age;

//     // Add the new user to the array
//     users[*numUsers] = newUser;
//     (*numUsers)++;
// }

// void printUsers(User *users[], int numUsers)
// {
//     printf("Users:\n");
//     for (int i = 0; i < numUsers; i++)
//     {
//         printf("- %s (%d)\n", users[i]->name, users[i]->age);
//     }
// }

// void freeUsers(User *users[], int numUsers)
// {
//     for (int i = 0; i < numUsers; i++)
//     {
//         free(users[i]->name); // free the name string
//         free(users[i]);       // free the user struct
//     }
// }

// int main()
// {
//     User *users[MAX_USERS];
//     int numUsers = 0;

//     // Add some users to the array
//     addUser(users, &numUsers);
//     addUser(users, &numUsers);
//     addUser(users, &numUsers);

//     // Print out the users
//     printUsers(users, numUsers);

//     // Free the second user in the array
//     free(users[1]);

//     // Try to print the users again
//     printf("Printing users again after free:\n");
//     printUsers(users, numUsers);

//     // Free all the remaining users in the array
//     freeUsers(users, numUsers);

//     return 0;
// }


/*Double free*/
/*code 6*/
// #include <stdlib.h>

// int main()
// {
//     // Allocate memory for a buffer
//     char *buffer = (char *)malloc(100);

//     // Free the buffer
//     free(buffer);

//     // Attempt to free the buffer again
//     free(buffer);

//     return 0;
// }


/*code 7*/
#include <stdio.h>
#include <stdlib.h>

void fun(char *buffer, size_t length)
{
    // Print the contents of the buffer
    printf("Buffer contents: %s\n", buffer);

    // Free the buffer
    free(buffer);
}

int main()
{
    // Allocate memory for a buffer
    char *buffer = (char *)malloc(100);
    if (buffer == NULL)
    {
        printf("Failed to allocate memory.\n");
        return 1;
    }

    // Write some data to the buffer
    snprintf(buffer, 100, "Hello, world!");

    // Pass the buffer to a function that frees it
    fun(buffer, 100);

    // Attempt to free the buffer again
    free(buffer);

    return 0;
}
