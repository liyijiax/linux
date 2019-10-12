/*************************************************************************
	> File Name: a.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月12日 星期六 10时39分09秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
    char var[50] = {0};
    if (argc > 1) {
        strcpy(var, argv[1]);
        cout << var << endl;
        cout << "var" << endl;
    }
    cout << "cpp" << endl;
    return 0;
}
