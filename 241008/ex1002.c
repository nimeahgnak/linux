#include<signal.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	sigset_t set;
	int result;

	sigemptyset(&set);
	result=sigismember(&set, SIGALRM);
	printf("SIGNAL is %s a member\n", result?"":"not");
	sigaddset(&set, SIGALRM);
	result=sigismember(&set, SIGALRM);
	printf("SIGALRM is %s a member\n", result?"":"not");

	sigfillset(&set);
	result=sigismember(&set, SIGCHLD);
	printf("SIGCHLD is %s a member\n", result?"":"not");
	sigddelest(&set, SIGCHLD);
	result=sigismember(&set,SIGCHLD);
	printf("SIGCHLD is %s a member\n", result?"":"not");
}
