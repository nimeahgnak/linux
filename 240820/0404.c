#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	char *filename ="test.txt";

	if ( access(filename, R_OK)==-1 )
	{
		fprintf(stderr, "User cannot read file %s\n", argv[1]);
		exit(1);
	}
	printf("%s readabel, proceeding\n", argv[1]);

}
		