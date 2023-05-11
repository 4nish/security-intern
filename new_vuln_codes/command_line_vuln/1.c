#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char buffer[100];                  // buffer to hold user input
    sprintf(buffer, "rm %s", argv[1]); // construct a command to delete the file specified by the user
    system(buffer);                    // execute the command

    printf("File '%s' deleted successfully!\n", argv[1]);

    return 0;
}
