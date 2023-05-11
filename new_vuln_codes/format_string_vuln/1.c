#include <stdio.h>

int main()
{
	char buf[10];
	printf("Please enter your name\n");
	gets(buf);
	printf("%s", buf);
	return 0;
}
