/*
 * =====================================================================================
 *
 *       Filename:  my.h 
 *
 *    Description:  header file of udp 
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
#include    <sys/socket.h>
#include    <sys/types.h>
#include    <string.h>
#include    <strings.h>
#include    <arpa/inet.h>
#include    <stdlib.h>
#include    <iostream>
typedef struct sockaddr SA;
using namespace std;
using std::cerr;
using std::endl;
using std::cout;

const int MAXLINE = 4096;

const unsigned int HEADER_SIZE = sizeof(unsigned int) * 5;
struct MsgHeader
{
    unsigned int cmd;// 消息类型
    unsigned int length; //数据消息长度
    unsigned int para1;
    unsigned int para2;
    unsigned int para3;
};
