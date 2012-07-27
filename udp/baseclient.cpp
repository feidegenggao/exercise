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
int SEND_SIZE = 50;

    void
dg_cli(int sockfd, const SA* pservaddr, socklen_t servlen)
{
    int n;
    char sendline[MAXLINE], recvline[MAXLINE + 1];
    struct MsgHeader sendmesg;
    sendmesg.cmd = 1;
    sendmesg.length = 3;
    sendmesg.para1 = 0;
    sendmesg.para2 = 0;
    sendmesg.para3 = 0;

    bzero(sendline, sizeof(sendline));
    memcpy(sendline, &sendmesg, HEADER_SIZE);
    memcpy(sendline + HEADER_SIZE, "hhh", 3);

    SEND_SIZE = HEADER_SIZE + 3;

    while(1)
    {
        sendto(sockfd, sendline, SEND_SIZE, 0, pservaddr, servlen);
        cout<<"SEND:"<<sendline + HEADER_SIZE <<endl;
        n = recvfrom(sockfd, recvline, MAXLINE, 0, NULL, NULL);
        recvline[n] = 0; 
        cout<<"RECV:"<<recvline+HEADER_SIZE<<endl;
        bzero(recvline, sizeof(recvline));
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
