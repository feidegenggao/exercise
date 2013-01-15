/*
 * ============================================================================
 *
 *       Filename:  memcmp.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/14/13 11:19:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <string.h>
#include    <stdio.h>

int main(void)
{
    int rt = memcmp("!ello World!", "Hello", strlen("Hello") - 1);
    printf("rt:%d\n", rt);
}
