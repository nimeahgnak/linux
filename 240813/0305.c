#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main()
{
	int filedes;
	off_t newpos;

	filedes = open("datal.txt",O_RDONLY);

	newpos = lseek(filedes, (off_t)0, SEEK_END);

	printf("file size : %lld\n", newpos);
}
