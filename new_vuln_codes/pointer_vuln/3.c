//arithmetic problems
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_elements = 5;
    int *arr = malloc(num_elements * sizeof(int)); // Allocate memory for an array of integers

    // Fill the array with some values
    for (int i = 0; i < num_elements; i++)
    {
        arr[i] = i + 1;
    }

    // Use pointer arithmetic to access elements of the array
    int *ptr = arr + 2; // Set the pointer to point to the third element of the array
    printf("Value at ptr: %d\n", *ptr);

    // Try to access an element outside the bounds of the array
    ptr = arr + 5;                      // Set the pointer to point to the sixth element of the array
    printf("Value at ptr: %d\n", *ptr); // Error: pointer arithmetic outside the bounds of the array

    // Free the memory allocated for the array
    free(arr);

    return 0;
}