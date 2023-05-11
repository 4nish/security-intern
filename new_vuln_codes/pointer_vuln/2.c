//null pointer dereference
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *name;
    int age;
} Person;

int main()
{
    Person *person_ptr = NULL;
    char *name_ptr;

    // person_ptr = (Person *)malloc(sizeof(Person));
    name_ptr = (char *)malloc(sizeof(char) * 20);

    printf("Enter your name: ");
    scanf("%s", name_ptr);

    person_ptr->name = name_ptr; // Null pointer dereference

    printf("Enter your age: ");
    scanf("%d", &person_ptr->age);

    printf("Name: %s, Age: %d\n", person_ptr->name, person_ptr->age);

    free(name_ptr);
    free(person_ptr);

    return 0;
}