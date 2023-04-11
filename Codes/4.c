#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to copy the string
char *copyString(char s[])
{
    char *s2;
    s2 = (char *)malloc(40);

    strcpy(s2, s);
    return (char *)s2;
}

int main()
{
    char s1[40] = "Mnit is located in Jaipur, Rajasthan.";
    char *s2;

    s2 = copyString(s1);
    printf("%s", s2);
    return 0;
}
