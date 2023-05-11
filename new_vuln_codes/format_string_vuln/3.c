#include <stdio.h>
int main()
{
    char s1[10];
    char s2[12];
    printf("enter the string\n");
    scanf("%s", s2);
    strcpy(s1, s2); // strcpy does perform bounds checking
    printf("s1 is %s\n", s1);
    return 0;
}
