/*
 * =====================================================================================
 *
 *       Filename:  client.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/01/12 19:49:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include    "my.h"

int main(int argc, char** argv){
    if (3 != argc){
        fprintf(stderr, "Usage:./cleint server_addr server_port\n");
        return -1;
    }
    int sockfd;
    char buf[MAXLINE];
    struct sockaddr_in serveraddr;

    sockfd = 0;
    bzero(buf, sizeof(buf));
    bzero(&serveraddr, sizeof(struct sockaddr_in));

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port   = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &serveraddr.sin_addr);

    if (-1 == connect(sockfd, (SA*)&serveraddr, sizeof(struct sockaddr_in)))
    {
        fprintf(stderr, "connect error:%s\n", strerror(errno));
        return -1;
    }

    //int f_fd = open("tcpdump", O_WRONLY | O_CREAT | O_TRUNC);
    int f_fd = open("tcpdump", O_RDONLY);
    if (-1 == f_fd)
    {
        cerr<<"open file error(errno:"<<errno<<"):"<<strerror(errno)<<endl;
        return -1;
    }
    else
    {

        if (-1 == setnonblocking(sockfd))
        //if (0)
        {
            cerr<<"setnonblocking sockfd error:"<<strerror(errno)<<endl;
            return -1;
        }

        int nwrited = 0;
        int nreaded = 0;
        int write_number = 0;
        for( ; ; )
        {
            lseek(f_fd, 10, SEEK_SET);
            if (-1 == (nreaded = read( f_fd, &buf, MAXLINE)))
            {
                cerr<<"read file error(errno:"<<errno<<"):"<<strerror(errno)<<endl;
            }
            else if (0 < nreaded)
            {
                if (-1 == (nwrited = write( sockfd, buf, nreaded)))
                {
                    if (EWOULDBLOCK == errno )
                    {
                        cerr<<"EWOULDBLOCK..."<<endl;
                    }
                    if (EAGAIN == errno)
                    {
                        cerr<<"EAGAIN..."<<endl;
                    }
                    cerr<<"write sockfd error(errno:"<<errno<<"):"<<strerror(errno)<<endl;
                    sleep(5);
                }
                else
                {
                    ++write_number;
                    cout<<"N:"<<write_number<<"\twrited "<<nwrited<<" Bytes\tnreaded:"<<nreaded<<endl;
                }
            }
        }
    }
    return 0;
}
