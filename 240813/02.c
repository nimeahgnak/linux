#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
	int filedes;
	//char pathname[] = "temp.txt";

	if((filedes = open("/Users/ganghaemin/24081 tem0.txt", O_CREAT | O_RDWR |O_CREAT, 0644))== -1)
	{
		printf("file open error!\n");
		exit(1);
	}
	
	close(filedes);
	return 0;

}
