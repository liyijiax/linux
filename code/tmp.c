/*************************************************************************
	> File Name: tmp.c
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月13日 星期日 10时16分54秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#define max_n 256


int get_env_path(char *str) {
    int i = 0, flag = 0;
    char tmp[512] = {0};
    char path[512] = {0};
      while (__environ[i] != NULL) {
          char *sub = strstr(__environ[i], "=");
          strncpy(tmp, __environ[i], sub - __environ[i]);
          //printf("\ntmp: %s\nsub: %s\n\n", tmp, sub + 1);
          if (strncmp(__environ[i], "PATH", 4)) {
              i++;
              continue;
          }
          strcpy(tmp, sub + 1);
          DIR *dir;
          struct dirent *rent;
          while (sub != NULL) {
              sub = strstr(tmp, ":");
              if (!sub) strncpy(path, tmp, sub - tmp);
              else break;
              printf("path: %s\n", path);
              if ((dir = opendir(path)) == NULL) {
                  strcpy(tmp, sub + 1);
                  continue;
              }
              while (rent = readdir(dir)) {
                  if (!strcmp(rent->d_name, str)) {
                      flag = 1;
                      break;
                  }
              }
              if (flag == 1) break;
              strcpy(tmp, sub + 1);
          }
          if (flag == 1) break;
          i++;
      }
    if (!flag) return -1;
    strcpy(str, path);
    return 0;
}

int main() {
    int i = 0;
    char str[512] = "ls";
    int num = get_env_path(str);
    printf("%s\n", str);
    printf("num: %d\n", num);
    return 0;
}
