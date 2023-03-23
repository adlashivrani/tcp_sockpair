#include "header.h"

int main()
{
	int fd;
    pid_t pid;
    int sockfd[2];
    char send_buf[SIZE];
    char recv_buf[SIZE];

   	fd = socketpair(AF_UNIX, SOCK_STREAM, 0, sockfd);
    if (fd == -1) {
    	printf("Error create socket\n");
    }

    pid = fork();

    if (pid == -1) {
    	printf("Error fork\n");
    } 
	if (pid == 0) {
    	close(sockfd[0]);
        read(sockfd[1], recv_buf, SIZE);
        printf("Child recv: %s", recv_buf);
    } else {
    		close(sockfd[1]);
            printf("Enter the msg: ");
            fgets(send_buf, SIZE, stdin);
            write(sockfd[0], send_buf, SIZE);
    }
    return 0;
}
