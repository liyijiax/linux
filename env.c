/*************************************************************************
	> File Name: env.c
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月13日 星期日 14时09分29秒
 ************************************************************************/

#include <stdio.h>

int main(int argc, char **argv) {
    for (int i = 2; i <= 30; i++) {
        printf("%s\n", argv[i]);
    }
    printf("%s", $PATH);
    return 0;
}
