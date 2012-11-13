/*
 * =====================================================================================
 *
 *       Filename:  server.cpp
 *
 *    Description:  ECHO server's server
 *
 *        Version:  1.0
 *        Created:  04/06/12 10:38:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include    "my.h"
#include    <iostream>
using namespace std;

int main(int argc, char** argv)
{
    if (2 != argc)
    {
        cerr<<"USAG:./server"<<endl;
        return -1;
    }
    pthread_t pid;
    int serverport = 1;
    int sockFd; // client sockt fd

    for ( ; serverport < 65535; ++serverport)
    {
        struct  sockaddr_in  serveraddr;
        if (-1 == (sockFd = socket(AF_INET, SOCK_STREAM, 0)))
        {
            cerr<<"socket error in generate sockFd for client"<<endl;
            return -1;
        }
        bzero(&serveraddr, sizeof(serveraddr));
        serveraddr.sin_family = AF_INET;
        serveraddr.sin_port   = htons(serverport);
        inet_pton(AF_INET, argv[1], &serveraddr.sin_addr);
        if (0 == connect(sockFd, (SA *) &serveraddr, sizeof(serveraddr)))
        {
            printf("port:%d is opening...\n", serverport);
        }
        else
        {
            //printf("port:%d is closed...\n", serverport);
        }
        close(sockFd);
    }
    return 0;
}
