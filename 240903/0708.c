#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

void func1(void);
void func2(void);

int main()
{
	printf("hello\n");
	atexit(func1);
	atexit(func2);

	printf("bye\n");
	exit(0);
}

void funcl(void)
{
	printf("funcl\n");
}

void func2(void)
{
	printf("func2\n");
}
