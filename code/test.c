/*************************************************************************
	> File Name: test.c
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月13日 星期日 10时37分09秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    int flag = strncmp("AB", "ABC", 3);
    printf("%d\n", flag);
    printf("%d\n", sizeof("PATH"));
    return 0;
}
