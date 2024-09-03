#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *file;
    char ch;
    long pos;

    file = fopen("alpha.txt", "r+");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (islower(ch)) {
            pos = ftell(file) - 1;
            fseek(file, pos, SEEK_SET);
            fputc(toupper(ch), file);
        }
    }

    fclose(file);

    printf("변환 완료.\n");

    return 0;
}


