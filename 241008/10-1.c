#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
    FILE *file = fopen("exit_message.txt", "a");
    if (file) {
        fprintf(file, "종료되엇다.\n");
        fclose(file);
    }
    exit(0);
}

int main() {
    struct sigaction sa = { .sa_handler = handle_sigint };
    sigemptyset(&sa.sa_mask);
    
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("띠로리 실패");
        return 1;
    }

    printf("느낌있게 종려하려무나 ㅎ.ㅎ");
    while (1) sleep(1);
    
    return 0;
}

