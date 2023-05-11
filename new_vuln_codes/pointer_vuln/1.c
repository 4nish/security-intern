// null pointer dereferencing
#include <stdio.h>

int main()
{
    int *ptr = NULL; // Initialize a pointer to NULL
    *ptr = 10;       // Dereference a null pointer
    printf("Value: %d", *ptr);
    return 0;
    //cause segmentation fault
}
