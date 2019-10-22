/*************************************************************************
	> File Name: 1.加法.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月22日 星期二 19时29分51秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/file.h>
#include <unistd.h>
#include <stdlib.h>
#define max_n 10
#define NUM 1000000

int main() {
    FILE *fp;
    pid_t num[10] = {0};
    pid_t pid;
    int x, sum = 0;
    int data[2] = {0};
    int *buff = data;
    printf("buff: %d\n", buff[0]);
    
    //创建十个进程
    for (int i = 0; i < max_n; i++) {
        x = i + 1;
        pid = fork();
        if (pid == 0) break;
    }
    if (pid == 0) {
        while(1) {
            fp = fopen("tmp", "r+"); 
            int fno = fileno(fp);
            flock(fno, LOCK_EX);
  
            fread(buff, 4, 2, fp); 
            buff[0] += 1;
            printf("buff: %d\n", buff[0]);
            if (buff[0] > NUM) {                    // 终止
                if (x == 10) printf("sum: %d\n", buff[1]); // 打印
                fclose(fp);
                flock(fno, LOCK_UN);
                break;
            }
            buff[1] += buff[0];
            fwrite(buff, 4, 2, fp);

            fclose(fp); 
            flock(fno, LOCK_UN);
        }
        printf("process NO: %d success\n", x);
    }
    

    return 0;
}

// 进程之间要通信
// socket抢了然后给父进程返回
