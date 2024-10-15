#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

void handler(int sig) {
    printf("[parent] received signal %d\n", sig);
}

int main()
{
    pid_t pid;
    int count = 5;

    if ((pid = fork()) > 0) {
        signal(SIGINT, handler);
        pause();
        printf("[parent] bye!\n");
    } 
    else if (pid == 0) 
    {
	printf("나 왓당~\n");
        while (count) {
            printf("[child] count is %d\n", count--);
            sleep(1);
        }
        kill(getppid(), SIGINT);
        printf("[child] bye!\n");
        exit(0);
    } 
    else {
        printf("fail to fork\n");
    }

    return 0;
}

