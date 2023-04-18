//improved version of above code is
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char buffer[100]; // buffer to hold user input
    char *filename = argv[1];

    // Check if the filename contains any illegal characters
    char *illegal_chars = "`|&;<>()$`\\\"' \t\n";
    if (strpbrk(filename, illegal_chars) != NULL) {
        printf("Invalid filename specified\n");
        exit(1);
    }

    // Check if the file exists and is writable
    if (access(filename, W_OK) == -1) {
        printf("Unable to delete file '%s': %s\n", filename, strerror(errno));
        exit(1);
    }

    // Construct the command to delete the file
    sprintf(buffer, "rm %s", filename);

    // Change to the home directory to avoid deleting unintended files
    chdir(getenv("HOME"));

    // Execute the command
    system(buffer);

    printf("File '%s' deleted successfully!\n", filename);

    return 0;
}