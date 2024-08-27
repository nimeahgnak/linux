#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int num;
    printf("양의 정수를 입력하세요: ");
    scanf("%d", &num);

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork 실패");
        exit(1);
    } else if (pid == 0) {
        long long product = 1;
        for (int i = 1; i <= num; i++) {
            product *= i;
        }
        printf("1부터 %d까지의 곱: %lld\n", num, product);
        exit(0);
    } else {
        int sum = 0;
        for (int i = 1; i <= num; i++) {
            sum += i;
        }
        printf("1부터 %d까지의 합: %d\n", num, sum);
        wait(NULL);
    }

    return 0;
}

