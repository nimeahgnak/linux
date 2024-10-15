#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    sigset_t set;
    int count = 5;

    sigemptyset(&set);

    for (int sig = 1; sig < NSIG; sig++) {
        if (sig != SIGKILL && sig != SIGSTOP) {
            sigaddset(&set, sig);
        }
    }

    sigprocmask(SIG_BLOCK, &set, NULL);

    while (count) {
        printf("don't disturb me (%d)\n", count--);
        sleep(1);
    }

    sigdelset(&set, SIGINT);
    sigprocmask(SIG_UNBLOCK, &set, NULL);

    printf("disturb me\n");

    return 0;
}

