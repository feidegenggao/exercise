/*
 * ============================================================================
 *
 *       Filename:  helloworld.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/28/13 17:32:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <sys/un.h>
#include    <sys/types.h>
#include    <sys/socket.h>
#include    <stdio.h>

int main(int argc, char** argv)
{
    int sockfd;
    socklen_t len;
    struct sockaddr_un addr1, addr2;

    if (argc != 2)
    {
        printf("usage: %s <pathname>", argv[0]);
        return 0;
    }

    sockfd = socket(AF_LOCAL, SOCK_STREAM, 0);
    unlink(argv[1]);
    bzero(&addr1, sizeof(addr1));
    addr1.sun_family = AF_LOCAL;
    strncpy( addr1.sun_path, argv[1], sizeof(addr1.sun_path) -1);
    bind(sockfd, (struct sockaddr*) &addr1, SUN_LEN(&addr1));

    len = sizeof(addr2);
    getsockname(sockfd, (struct sockaddr*) &addr2, &len);
    printf("bound name = %s, returned len = %d\n", addr2.sun_path, len);
    return 0;
}
