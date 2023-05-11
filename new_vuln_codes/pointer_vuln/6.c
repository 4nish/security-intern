//double free
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
