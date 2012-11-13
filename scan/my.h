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
#include    <sys/wait.h>
#include    <sys/socket.h>
#include    <arpa/inet.h>
#include    <netinet/in.h>
#include    <stdlib.h>
#include    <string.h>
#include    <errno.h>
#include    <unistd.h>
#include    <fcntl.h>
#include    <poll.h>

#define     SA  struct      sockaddr
#define     MAXLINE     4096    /*  max text line length */
#define     LISTENQ     1024    /*  2nd argument to listen() */
#define     SERV_PORT   9999    /* THE server port for echo service */
