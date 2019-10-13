/*************************************************************************
	> File Name: my.c
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月13日 星期日 20时04分03秒
 ************************************************************************/

#include "common.h" 

int main(int argc, char *argv[]) {
    int sockfd, port;

    
    struct sockedaddr_in addr;
    addr.sin_family = AF_INET;
    addr->sin_port = 8090;
    addr.sin_addr.s_addr = inet_addr(server);

    socklen_t len = sizeof(addr);



    if (connect(sockfd, (struct sockaddr *)&addr, len) < 0) {
        perror("connect");
        close(sockfd);
        exit(1);
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
