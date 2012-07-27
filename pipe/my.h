/*
 * =====================================================================================
 *
 *       Filename:  my.h
 *
 *    Description:  my header file
 *        Version:  1.0
 *        Created:  
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (),
 *        Company:  NDSL UESTC
 *
 * =====================================================================================
 */

#include    <signal.h>
#include    <sys/types.h>
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
#include    <semaphore.h>
#include    <map>

using namespace std;
using std::cout;
using std::cerr;
using std::endl;
using std::map;

#define     SA  struct      sockaddr
#define     EPOLLMAX  4096

#ifndef     HEADER_MESSAGE_TYPE
#define     HEADER_MESSAGE_TYPE
const int   MAXLINE = 4096;    /*  max text line length */
const int   LISTENQ = 1024;    /*  2nd argument to listen() */

const int   READ_FLAG = 1;
const int   WRITE_FLAG = 2;

const int   READ_HEAD = 1;
const int   READ_DATA = 2;

const int   FILE_DIR_LEN = 50;
const int   FILE_NAME_LEN = 20;

const int   C_LOGIN = 1;
const int   C_FILE= 4;
const int   C_EOF = 5;
const int   S_FILE = 6;
const int   S_EOF = 7;

typedef enum
{
    START,
    CONNECTED,
    END,
}statusstruct;
/* types of message */
struct headstruct
{
    int cmd;
    int length;
    int para1;
    int para2;
    int para3;
};
class clientagent;
typedef struct
{
    clientagent* clientpointer;
    int rw_fd;
    int rw_flag; 
    char *databuf;
    int nwrite;
    int offset;
}threadargu;

const int   HEADSIZE = sizeof(headstruct);

inline int setnonblock(int set_fd)
{
    int flag = 0;
    if ( 0 > fcntl(set_fd, F_GETFL, 0))
    {
        cerr<<"fcntl F_GETFL error:"<<strerror(errno)<<endl;
        return -1;
    }
    flag |= O_NONBLOCK;
    if ( 0 > fcntl(set_fd, F_SETFL, flag))
    {
        cerr<<"fcntl F_SETFL error:"<<strerror(errno)<<endl;
        return -1;
    }

    return 0;
}
#endif
