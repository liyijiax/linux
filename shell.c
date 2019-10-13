/*************************************************************************
	> File Name: shell.c
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月12日 星期六 09时38分58秒
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

int get_user(char *user) {
    if (user == NULL) return -1;
    struct passwd *pwd = getpwuid(getuid());
    strcpy(user, pwd->pw_name);
    return 0;
}
 
int get_machine(char *machine) {
    char mach[20];
    if (machine == NULL) return -1;
    gethostname(mach, 20);
    strcpy(machine, mach);
    return 0;
}

void cd(char *path) {
    chdir(path);
}

int get_env_path(char *str) {
      int i = 0, flag = 0;
    char tmp[512] = {0};
    char path[512] = {0};
      while (__environ[i] != NULL) {
            char *sub = strstr(__environ[i], "=");
          strncpy(tmp, __environ[i], sub - __environ[i]);
          if (strncmp(__environ[i], "PATH", 4)) {
            i++;
            strcpy(tmp, sub + 1);
            continue;
          }

          DIR *dir;
          struct dirent *rent;
          while (sub != NULL) {
            sub = strstr(tmp, ":");
            strncpy(path, tmp, sub - tmp);
            dir = opendir(path);
            while (rent = readdir(dir)) {
                if (!strcmp(rent->d_name, str)) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) break;
            strcpy(tmp, sub + 1);
          }
      }
    if (!flag) return -1;
    strcpy(str, path);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Invaild Input\n");
        return 1;
    }
    char path[512];
    char command[512];
    char user_name[512];
    char machine_name[512];
    unsigned char i = 0;
    strcpy(path, argv[1]);
    for ( ; i < max_n; i++ ) {
        get_user(user_name);
        get_machine(machine_name);
        printf("%s@%s: %s$ ", user_name, machine_name, path);
        fflush(stdout);
        pid_t pid;
        
        scanf("%s", command);
        if (!strcmp(command, "cd")) {
            strcpy(path, getcwd(NULL, 100));
            cd(path);
            continue;
        } else if (!strcmp(command, "ls")) {
            printf("ls\n");
            char str[512] = "ls";
            int num;
            if ((num = get_env_path(str)) >= 0) {
                printf("success get\n");
                sprintf(path, "%s/ls", str);
                printf("%s\n", path);

                pid = fork();
                if (pid == 0) {
                    execlp(path, "ls", NULL);
                    exit(2);
                }
                wait(NULL);
            }
            printf("num: %d\n", num);

        }
    }
    return 0;
}
