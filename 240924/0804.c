#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid > 0) {
        exit(0);
    }

    if (setsid() < 0) {
        perror("setsid failed");
        exit(1);
    }

    FILE *file = fopen("curtime.txt", "a");
    if (file == NULL) {
        perror("file open failed");
        exit(1);
    }

    while (1) {
        time_t now = time(NULL);
        struct tm *tm_info = localtime(&now);
        fprintf(file, "Current Time: %s", asctime(tm_info));
        fflush(file);
        sleep(10);
    }

    fclose(file);
    return 0;
}

