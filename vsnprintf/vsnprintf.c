/*
 * ============================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/27/2012 08:00:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <stdio.h>
#include    <stdarg.h>
#define     LOG_BUFFER_SIZE 1000

char logbuf[LOG_BUFFER_SIZE];

int vspf(char* fmt, ...)
{
    va_list argptr;
    int cnt;
    va_start(argptr, fmt);
    cnt = vsnprintf(logbuf, LOG_BUFFER_SIZE, fmt, argptr);
    va_end(argptr);
    return cnt;
}

int main()
{
    char* pwords = "Hello World!";
    int n = 0;

    vspf("n:%d\t, words:%s", n, pwords);
    printf("LOG:%s\n", logbuf);
}
