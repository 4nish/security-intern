#include <stdio.h>
#include <string.h>

#define S 20
#define N 1000

int main(int argc, char *argv[])
{
    char out[S];
    char buf[N];
    char msg[] = "Hey! What are doing here?\n";
    int len = 0;
    buf[0] = '\0';
    printf(msg);
    while (argc)
    {
        sprintf(out, "argument %d is %s\n", argc - 1, argv[argc - 1]);
        argc--;
        printf("%s", out);
        strncat(buf, out, sizeof(buf) - len - 1);
        len = strlen(buf);
    }
    // printf("%s", buf);
    return 0;
}