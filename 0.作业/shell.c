/*************************************************************************
	> File Name: for.c
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月12日 星期六 09时38分58秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <string.h>
#include <unistd.h>
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
        
        scanf("%s", command);
        if (!strcmp(command, "cd")) {
            strcpy(path, getcwd(NULL, 100));
            cd(path);
            continue;
        }

        //sleep(10);
    }
    return 0;
}
