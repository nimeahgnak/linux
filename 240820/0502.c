#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
	DIR *dirp;
	struct dirent *dentry;
	int dircnt = 0;
	int filecnt = 0;

	if ((dirp = opendir(argv[1])) == NULL)
	exit(1);

	while ((dentry = readdir(dirp))) {
		if (dentry->d_ino != 0) {
			if (dentry-›d_type == DT_DIR) {
				dircnt++;
			} else {
				filecnt++;}
			printf("%sIn", dentry->d_name);
		
		}
	}

	closedir (dirp);
	printf("디렉토리 개수: %d, 파일 개수: %dln", dircnt, filecnt);
	return 0;
}
