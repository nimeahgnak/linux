#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char *argv[]) {
    	if (access(argv[1], F_OK) != -1) {
        printf("%s 파일이 존재합니다.\n", argv[1]);
    } else {
        printf("%s 파일이 존재하지 않습니다.\n", argv[1]);
    }

    return EXIT_SUCCESS;
}

