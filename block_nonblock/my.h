/*
 * =====================================================================================
 *
 *       Filename:  my.h
 *
 *    Description:  我自己加的一些常用的头文件、宏定义之类的。
 *
 *        Version:  1.0
 *        Created:  2011年08月03日 14时30分48秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (),
 *        Company:  NDSL UESTC
 *
 * =====================================================================================
 */
#include    <stdio.h>
#include    <signal.h>
#include    <sys/types.h>
#include    <sys/stat.h>
#include    <sys/wait.h>
#include    <sys/socket.h>
#include    <sys/epoll.h>
#include    <arpa/inet.h>
#include    <netinet/in.h>
#include    <stdlib.h>
#include    <string.h>
#include    <errno.h>
#include    <unistd.h>
#include    <fcntl.h>
#include    <poll.h>
#include    <time.h>
#include    <iostream>

using namespace std;
using std::cout;
using std::endl;
using std::cerr;

#define     SA  struct      sockaddr
#define     MAXLINE     4096    /*  max text line length */
#define     EPOLLMAX    4096
#define     LISTENQ     1024    /*  2nd argument to listen() */
#define     SERVPORT   7777    /* THE server port for echo service */
#define     FILENAMELENGTH  50
struct Header{
    int type;
    off_t file_length;
};

/* -----------------------------MAX&&MIN--------------------------------- */
#define     max(a,b)    ( (a) > (b) ? (a) : (b) )
#define     min(a,b)    ( (a) < (b) ? (a) : (b) )
/* ----------------------------MAX && MIN END------------------------------ */
int setnonblocking(int fd){
    int flag = 0;
    if( (flag = fcntl(fd, F_GETFL, 0))< 0){
        printf("F_GETFL error:%s\n", strerror(errno));
        return -1;
    }
    flag |= O_NONBLOCK;
    if( fcntl(fd, F_SETFL, flag)< 0){
        printf("F_SETFL error:%s\n", strerror(errno));
        return -1;
    }
}
