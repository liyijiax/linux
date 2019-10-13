/*************************************************************************
	> File Name: prime.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月12日 星期六 19时33分48秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define max_n 10000

int prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i < max_n; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max_n) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}
int main() {
    init();
    int flag = 0;
    for (int i = 1; i <= prime[0]; i++) {
        flag && cout << " ";
        cout << prime[i];
        flag = 1;
    }
    return 0;
}
