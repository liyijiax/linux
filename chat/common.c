/*************************************************************************
	> File Name: common.c
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月13日 星期日 19时24分30秒
 ************************************************************************/
#include "common.h"

int socket_create(int port) {
    int socketfd;
    struct sockaddr_in sock_addr;

    if ((socketfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }
    
    // 绑定
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(port);
    sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(socketfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0) {
        perror("bind");
        close(socketfd);
        return -1;
    }

    if (listen(socketfd, 20) < 0) {
        perror("listen");
        close(socketfd);
        return -1;
    }

    return socketfd;
}
// 所有人连船长，然后发信息，写客户端
