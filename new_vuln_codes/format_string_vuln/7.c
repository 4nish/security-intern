#include <stdio.h>
#include <string.h>

void fun(char *s1, char *s2)
{
    memset(s1, 0, 10);
    strcpy(s1, s2);
    printf("s1 is %s\n", s1);
}
int main()
{
    char buf[10];
    char s1[8];
    memset(buf, 0, sizeof(buf));
    printf("Enter a string: ");
    scanf("%s", buf);
    printf("String: %s\n", buf);
    fun(buf, s1);
    return 0;
}
