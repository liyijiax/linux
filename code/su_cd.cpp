/*************************************************************************
	> File Name: su_cd.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月10日 星期四 18时51分22秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#define MAX 512

int main(int argc, char *argv[]) {
    char path[MAX] = {0}; // 每一个字节设置为零
    if (argc > 2) {
        printf("Invalid Argument\n");
        return 1;
    } else if (argc == 1) {
        strcpy(path, ".");
    } else {
        strcpy(path, argv[1]);
    }
    printf("Before: %s\n", getcwd(NULL, 100));
    
    if (chdir(path) < 0) {
        perror("Path Error"); // perror只能在确定出错的地方用
        printf("Err%s\n", strerror(errno));
        return 2;
    } 

    printf("After: %s\n", getcwd(NULL, 100));
    printf("%s : ", path);
    sleep(10);
    return 0;
} // errorno 全局静态变量
// 有些bug很难复现
// 比如打开文件失败，已经打开1024个，你程序还往下走
