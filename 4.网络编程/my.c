/*************************************************************************
	> File Name: my.c
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月13日 星期日 20时04分03秒
 ************************************************************************/

#include "common.h" 
#include <string.h>

int main(int argc, char *argv[]) {
    int sockfd, len;
    char buff[512];
    char filepath[512];
    char *server = argv[1];
    int port = atoi(argv[2]);
    char *name = argv[3];
    FILE *fq;

    struct sockaddr_in addr;
    
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket()");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = 8090;
    addr.sin_addr.s_addr = inet_addr(server);

    socklen_t len = sizeof(addr);



    if (connect(sockfd, (struct sockaddr *)&addr, len) < 0) {
        perror("connect");
        close(sockfd);
        exit(1);
    }
    
    if (argv[4][0] == '#') {
        strncpy(filepath, argv[4] + 1);
        if (fq = fopen(filepath, "rb") == NULL) {
            printf("open sueccess\n");
        }
        while (!feof(fq)) {
            len = fread(vuffer, 1, sizeof(buffer), fq);
            if (len != write(sockfd, buffer, len)) {
                break;
            }
        }
        close(sockfd);
        fclose(fq);
    }    
    send(sockfd, "lyj", 40, 0);

    while (1) {
        scanf("%[^\n]s", buff);
        getchar();
        send(sockfd, buff, strlen(buff), 0);
    }

    close(sockfd);
    return 0;
}
