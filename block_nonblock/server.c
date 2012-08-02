/*
 * =====================================================================================
 *
 *       Filename:  server.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/01/12 20:00:47
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
    if (2 != argc){
        fprintf(stderr, "Usage:./server listenport\n");
        return -1;
    }
    int listenfd, connfd;
    int nreaded;
    socklen_t len;
    struct sockaddr_in serveraddr, clientaddr;
    char buf[MAXLINE];

    listenfd = 0;
    connfd   = 0;
    len = sizeof(struct sockaddr_in);
    bzero(&serveraddr, sizeof(struct sockaddr_in));
    bzero(&clientaddr, sizeof(struct sockaddr_in));
    bzero(buf, MAXLINE);


    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port   = htons(atoi(argv[1]));
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == bind(listenfd, (SA*)&serveraddr, sizeof(struct sockaddr_in)))
    {
        fprintf(stderr, "bind error:%s\n", strerror(errno));
        return -1;
    } 
    if (-1 == listen(listenfd, LISTENQ))
    {
        fprintf(stderr, "listen error:%s\n", strerror(errno));
        return  -1;
    }

    //setnonblocking(listenfd);
    cout<<"before accept"<<endl;
    if (-1 == (connfd = accept(listenfd, (SA*)&clientaddr, &len)))
    {
        fprintf(stderr, "accept error:%s\n", strerror(errno));
        if ( EWOULDBLOCK == errno || EAGAIN == errno)
        {
            fprintf(stdout, "errno is EWOULDBLOCK\n");
            //continue;
        }
        else
            return -1;
    }
    cout<<"after accept, connfd:"<<connfd<<endl;
    //if (-1 == setnonblocking(connfd))
    if (0)
    {
        cerr<<"setnonblocking error:"<<strerror(errno)<<endl;
        return -1;
    }

    do
    {
        cout<<"before read connfd, please press space key"<<endl;
        getchar();
        if (-1 == (nreaded = read(connfd, buf, 1024)))
        {
            if (EWOULDBLOCK == errno )
            {
                cerr<<"EWOULDBLOCK..."<<endl;
            }
            if (EAGAIN == errno)
            {
                cerr<<"EAGAIN..."<<endl;
            }
            cerr<<"errno:"<<errno<<endl;
            fprintf(stderr, "read from connfd error:%s\n", strerror(errno));
            sleep(15);
        }
        else if (0 == nreaded)
        {
            cout<<"client close the connection"<<endl;
            close(connfd);
            return 0;
        }
        else
        {
            cout<<"after read connfd:"<<"\tlength:"<<nreaded<<endl;
            bzero(buf, MAXLINE);
        }
    }while(1);

    return 0;
}
