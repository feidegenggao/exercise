/*
 * ============================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  进程Afork一个子进程B，Ctrl+C结束A后，B会被结束吗？
 *
 *        Version:  1.0
 *        Created:  09/06/12 16:43:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <unistd.h>
#include    <stdio.h>

int main()
{
    pid_t pid;
    if ((pid = fork()) < 0)
    {
        printf("fork error\n");
        return -1;
    }
    else if (0 == pid)
    {
        printf("in son progress\n");
        while(1);
        printf("end of son progress\n");
    }

    printf("in father progress , after fork\n");
    while(1);
    return 0;
}
