/*************************************************************************
	> File Name: fork_path.c
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月13日 星期日 14时18分44秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    char *patharg;
    patharg = getenv("PATH");
    printf(" a.out %s\n", patharg);

    if (fork() == 0) {
        execlp("./b.out", NULL);
    }

    wait(NULL);
    return 0;
}
