/*************************************************************************
	> File Name: server.c
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月13日 星期日 19时36分35秒
 ************************************************************************/

#include "common.h"
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    int port, server_listen, sockfd;
    struct socketaddr_in client_addr;
    pid_t pid;
    socklen_t len = sizeof(client_addr);
    if (argc != 2) {
        printf("Usage: ./server port\n");
        exit(1);
    }
    port = atoi(argv[1]);

    if ((sockfd = socket_create(port)) < 0) {
        exit(2);
    }
    
    
    while (1) {
    if ((sockfd = accept(server_listen, (struct sockaddr *)&client_addr))
       < 0) {
           perror("accept");
           continue;
       }

        if ((pid = fork()) < 0) {
            perror("fork()");
            exit(1);
        }
        if (pid == 0) {
            close(server_listen);
            char name[50] = {0};
            char buff[512] = {0};
            recv(sockfd, name, 50, 0);
            printf("[Login] %s on %s:%d\n", name, 
                   inet_ntoa(client_addr.s_addr), client_addr.sin_port);
            while (1) {
                if (recv(sockfd, buff, 512, 0) <= 0) {
                    close(sockfd);
                    break;
                }
                printf("[info] %s : %s\n", name, buff);
            }
        } else {
            close(sockfd);
        }

    }


    return 0;
}
