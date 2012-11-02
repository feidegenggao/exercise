/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/29/12 16:52:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <stdio.h>
#include    <strings.h>
#include    <string.h>
#pragma pack(1)
struct rtp_sync
{
    char syncchar;
    char channle;
    unsigned short int len;
};
#pragma pack()

int main()
{
    char tempbuf[5];

    snprintf(tempbuf, 5,
            "%c%c%u", '$', '0', (short int)(1328));
    printf("tempbuf:%s\n", tempbuf);
    char intbuf[4];
    snprintf(intbuf,4,
            "%u", 1328);
    printf("intbuf:%s\n", intbuf);

    printf("sizeof(int):%d\n", sizeof(unsigned short int));


    rtp_sync temprtp;
    bzero(&temprtp, sizeof(temprtp));
    printf("sizeof temprtp:%d\n", sizeof temprtp);

    temprtp.syncchar = '$';
    temprtp.len = 1328;

    printf("%s\n", &temprtp);
    printf("%d\n", temprtp.len);

    unsigned short int len = 0;
    memcpy(&len, &temprtp + 2, 2);
    printf("length:%d\n", len);
  

    char rtpbuf[4];

    memcpy(rtpbuf, &temprtp, sizeof(temprtp));
    printf("tempbuf:%s\n", rtpbuf);


    return 0;
}
