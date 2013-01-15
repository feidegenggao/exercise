/*
 * =====================================================================================
 *
 *       Filename:  client.cpp
 *
 *    Description:  client of echo using udp
 *
 *        Version:  1.0
 *        Created:  07/25/12 00:45:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *        Company:  NDSL
 *
 * =====================================================================================
 */

#include    "my.h"
const int SEND_SIZE = 50;

    void
dg_cli(int sockfd, const SA* pservaddr, socklen_t servlen)
{
    int n;
    char sendline[MAXLINE], recvline[MAXLINE + 1];
    memcpy(sendline, "Hello Kitty!", 50);
    bzero(recvline, sizeof(recvline));
    int i = 0;

    while(1)
    {
        n = sendto(sockfd, sendline, SEND_SIZE, 0, pservaddr, servlen);
        cout<<"send sum:"<<i++<<endl;
        /*
        n = recvfrom(sockfd, recvline, MAXLINE, 0, NULL, NULL);
        recvline[n] = 0; 
        cout<<"RECV:"<<recvline<<endl;
        bzero(recvline, sizeof(recvline));
        */
    } 
}

int
main(int argc, char** argv)
{
    int         sockfd;
    struct sockaddr_in servaddr;

    if (argc != 3)
    {
        cerr<<"USAGE:./client serverip serverport"<<endl;
        return -1;
    }

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    dg_cli(sockfd, (SA*) &servaddr, sizeof(servaddr));

    return 0;
}
