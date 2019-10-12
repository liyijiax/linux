/*************************************************************************
	> File Name: fork.c
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月12日 星期六 14时15分25秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#define max_n 10

int main() {
    pid_t num[max_n + 5] = {0};
    int i, flag = 0;
    pid_t pid;
    int x = 0;
    for (i = 0; i < max_n; i++) {
        pid = fork();
        x = i + 1;
        if (pid == 0) {
            break;
        }
    }
    if (pid == 0) {
        printf("num: %d PID: %d\n", x, getpid());
    } else {
        printf("This is the parent process\n");
    }
    return 0;
}
