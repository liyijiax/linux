/*************************************************************************
	> File Name: fork.c
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月10日 星期四 19时56分27秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    char *a = "abcd";
    int status;
    pid  = fork();

    if (pid == 0) {
        printf("Child: %d -> %d\n", getpid(), getppid());
        sleep(2);
        exit(2);
    } else {
        wait(&status);
        printf("Father: %d, [%d]\n", getpid(), status);
    }
    



    return 0;
} // 所有孤儿进程由systemd收养
