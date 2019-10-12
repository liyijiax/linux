/*************************************************************************
	> File Name: for.c
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月12日 星期六 09时38分58秒
 ************************************************************************/

#include <stdio.h>
#define max_n 256

int main() {
    unsigned char i = 0;
    int flag = 0;
    for ( ; i < max_n; i++ ) {
        flag && printf(" ");
        printf("%d", i);
        flag = 1;
    }
    return 0;
} // 整形提升
