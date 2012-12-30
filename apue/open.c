/*
 * ============================================================================
 *
 *       Filename:  open.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/30/12 13:37:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <fcntl.h>
#include    <stdio.h>

int main(void)
{
    char* filename = "a.txt";
    int openfd = open(filename, O_RDWR | O_CREAT | O_TRUNC | O_APPEND, S_IRUSR | S_IWUSR);
    if (-1 == openfd)
    {
        fprintf(stderr, "open %s failed\n", filename);
        return -1;
    }
    return 0;
}
