//use after free
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_USERS 100

typedef struct
{
    char *name;
    int age;
} User;

void addUser(User *users[], int *numUsers)
{
    char name[50];
    int age;

    // Get user's name and age from user input
    printf("Enter user's name: ");
    scanf("%s", name);
    printf("Enter user's age: ");
    scanf("%d", &age);

    // Allocate memory for the new user's name and copy it over
    char *nameCopy = malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(nameCopy, name);

    // Allocate memory for the new user and set its fields
    User *newUser = malloc(sizeof(User));
    newUser->name = nameCopy;
    newUser->age = age;

    // Add the new user to the array
    users[*numUsers] = newUser;
    (*numUsers)++;
}

void printUsers(User *users[], int numUsers)
{
    printf("Users:\n");
    for (int i = 0; i < numUsers; i++)
    {
        printf("- %s (%d)\n", users[i]->name, users[i]->age);
    }
}

void freeUsers(User *users[], int numUsers)
{
    for (int i = 0; i < numUsers; i++)
    {
        free(users[i]->name); // free the name string
        free(users[i]);       // free the user struct
    }
}

int main()
{
    User *users[MAX_USERS];
    int numUsers = 0;

    // Add some users to the array
    addUser(users, &numUsers);
    addUser(users, &numUsers);
    addUser(users, &numUsers);

    // Print out the users
    printUsers(users, numUsers);

    // Free the second user in the array
    free(users[1]);

    // Try to print the users again
    printf("Printing users again after free:\n");
    printUsers(users, numUsers);

    // Free all the remaining users in the array
    freeUsers(users, numUsers);

    return 0;
}
