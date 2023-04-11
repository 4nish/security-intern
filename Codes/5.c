#include <stdio.h>
#include <string.h>

int main()
{
    char s1[20] = "Anish Jangir";
    char s2[20];

    memcpy(s2, s1, 1);
    printf("%s\n", s1);

    return 0;
}
