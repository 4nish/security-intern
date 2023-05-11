#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[10];
    char *password = "password";
    printf("Enter your password: ");
    scanf("%s", buffer);
    if (strcmp(buffer, password) == 0)
    {
        printf("Access granted.\n");
    }
    else
    {
        printf("Access denied.\n");
    }
    return 0;
}