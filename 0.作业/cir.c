/*************************************************************************
	> File Name: cir.c
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月12日 星期六 16时19分24秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int flag = 0;
    for (int i = 0; i < 256; i++) {
        flag && printf(" ");
        printf("%d", i);
        flag = 1;
        i &= 0377;
    }
    return 0;
}
