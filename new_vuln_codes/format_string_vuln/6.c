#include <stdio.h>
#include <string.h>

void copy_string(char *dst, char *src, int len)
{
    memcpy(dst, src, len);
    printf("Copied string: %s\n", dst);
}

int main()
{
    char buf[10];
    char input[20];
    printf("Enter a string: ");
    scanf("%s", input);
    copy_string(buf, input, strlen(input));
    return 0;
}