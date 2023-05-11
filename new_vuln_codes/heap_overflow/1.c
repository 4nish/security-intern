#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *buffer = malloc(10);
    if (buffer == NULL)
    {
        printf("Error: Failed to allocate memory.\n");
        exit(1);
    }

    // produce overflow
    strcpy(buffer, "helloAnishJangir");
    printf("Buffer contains: %s\n", buffer);

    // does not produce overflow
    // strcpy(buffer, "helloAnish");
    // printf("Buffer contains: %s\n", buffer);

    strcpy(buffer + 5, " world");
    printf("Buffer now contains: %s\n", buffer);

    free(buffer);
    return 0;
}
