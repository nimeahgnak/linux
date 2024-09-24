#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>

int main()
{
	pid_t pid;
	int status=0;

	if((pid=fork())>0)
	{
		while(!wairpid(pid, &status, WNOHANG))
		{
			 printf("parent:child-exit(%d)/n",status);
		}
		 
		else if (pid==0)
		{
			sleep(5);
			printf(("bye!\n");
			exit(0);
		}

		else printf("fall to fork\n");
		}

		}
