/*************************************************************************
	> File Name: ls.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月08日 星期二 15时27分28秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <unistd.h>
#include <ctime>
using namespace std;
#define max_n 100

char str[max_n];
string res[max_n];

int cmp(string a, string b) {
    return a < b;
}

void my_print(string name, struct stat log)
{	char *wday[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    struct passwd *pwd1 = getpwuid(log.st_uid);
    struct passwd *pwd2 = getpwuid(log.st_gid);
    cout << log.st_mode << " ";
    printf("\t");
    cout << pwd1->pw_name << " ";
    printf("\t");
    cout << pwd2->pw_name << " ";
    printf("\t");
    //cout << log.st_gid << " ";
    cout << log.st_size << " ";
    printf("\t");
    //cout << log.st_mtime << " ";
    printf("\t");
    struct tm *p;
    p = localtime(&log.st_mtime);
	printf("%d/%d/%d ", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
    printf("%s %d:%d:%d\t", wday[p->tm_wday], p->tm_hour,
        p->tm_min, p->tm_sec);
    cout << name << endl;
}

int main(int arg, char *argv[]) {
    DIR *dir;
    struct dirent *rent;
    if (arg <= 1) dir = opendir(".");
    else dir = opendir(argv[2]);
    int cnt = 0;
    struct stat buf;
    while (rent = readdir(dir)) {
        strcpy(str, rent->d_name);
        stat(rent->d_name, &buf);
        my_print(rent->d_name, buf);
        if (str[0] == '.') continue;
        res[cnt++] = str;
    }
    sort(res, res + cnt, cmp);
    /*for (int i = 0; i < cnt; i++) {
        cout << res[i] << endl;
    }*/
    closedir(dir);
    return 0;
}//怎么走下去这条路，这条特别的路
// 规矩怎么定
// 项目自己做，没有人带着，这门课特殊之处
// 之前的学习方式都是带着，没有什么压力
// 这门课任务量太多，代码多，自己考虑方法，实现方式不明确
// 不会把任何一个知识点告诉你
// 位掩码，怎么看文档
// 想法设法实现
//
