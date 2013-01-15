/*
 * =====================================================================================
 *
 *       Filename:  server.cpp
 *
 *    Description:  server of echo server using udp
 *
 *        Version:  1.0
 *        Created:  07/25/12 00:29:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *        Company:  NDSL
 *
 * =====================================================================================
 */
#include    "my.h"

void dg_echo(int sockfd, SA* pcliaddr, socklen_t clilen)
{
    int         n;
    socklen_t   len;
    char        mesg[MAXLINE];

    int i = 0;
    for ( ; ; )
    {
        len = clilen;
        n = recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len);
        cout<<"recv sum"<<i++<<endl;
        sleep(5);

        sendto(sockfd, mesg, n, 0, pcliaddr, len);
    }
}

int
main(int argc, char** argv)
{
    if (argc != 2)
    {
        cerr<<"USAGE:./server port"<<endl;
        return -1;
    }

    int                 sockfd;
    struct sockaddr_in  servaddr, cliaddr;
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port   = htons(atoi(argv[1]));

    bind(sockfd, (SA*)&servaddr, sizeof(servaddr));

    dg_echo(sockfd, (SA*)&cliaddr, sizeof(cliaddr));
}
