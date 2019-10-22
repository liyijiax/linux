/*************************************************************************
	> File Name: cd.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月10日 星期四 17时50分25秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <unistd.h>
using namespace std;

int main(int arg, char *argv[]) {
    chdir(argv[1]);
    printf("%s\n", getcwd(NULL, NULL));
    return 0;
}
