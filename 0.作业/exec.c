/*************************************************************************
	> File Name: exec.c
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月12日 星期六 09时42分52秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv){
    pid_t pid, child_1, child_2;
    char filename[512] = {0};
    char name[512] = {0};
    char tmp[5] = {0};
    char cc_flag[50] = {0};
    char var[50] = {0};
    int num  = argc;
    /*if (argc != 2) {
        printf("Usage: ./a.out codefile\n");
        exit(1);
    }*/
    strcpy(filename, argv[1]);
    if (argc > 2) {
        strcpy(var, argv[2]);
        printf("success\n");
    }
    char *sub;

    sub = strstr(filename, ".");
    strncpy(name, filename, sub - filename);
    strcpy(tmp, sub);

    if (!strcmp(tmp, ".c")) {
        strcpy(cc_flag, "gcc");
    } else if (!strcmp(tmp, ".cpp")) {
        strcpy(cc_flag, "g++");
    } else {
        printf("Not Support File Type\n");
        exit(2);
    }

    if ((pid = fork()) < 0) {
        perror("fork");
        exit(3);
    }

    if (pid == 0) {
        if ((child_1 = fork()) < 0) {
            perror("child1");
            exit(4);
        }
        
        if (child_1 == 0) {
            execlp("/usr/bin/vim", "vim", filename, NULL);
            exit(5);
        }
        sleep(2);
        wait(NULL);

        if ((child_2 = fork()) < 0) {
            perror("child2");
            exit(4);
        }
        
        if (child_2 == 0) {
            if (!strcmp("gcc", cc_flag)) {
                int res = execlp("/usr/bin/gcc", "gcc", filename, NULL);
                printf("res: %d\n", res);
            } else {
                execlp("/usr/bin/g++", "g++", filename, NULL);
            }
            exit(6);
        }
        wait(NULL);

        if ((child_3 = fork()) < 0) {
            perror("child3:");
        }
        if (child_3 == 0) {
            
        if (num > 2) {
            //system("./a.out");
            execl("./a.out", var, NULL);
        } else {
            system("./a.out");
        }
        exit(7);

        }
    }

    wait(NULL);


    return 0;
} // 写三个子进程
