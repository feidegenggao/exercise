/*
 * ============================================================================
 *
 *       Filename:  test.c
 *
 *    Description: 测试，以及练习gprof的用法 
 *
 *        Version:  1.0
 *        Created:  2012年10月10日 10时41分50秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include "stdio.h"
#include "stdlib.h"
#include "signal.h"

void ctrlhandler( int a )  
{  
     printf("you have press ctrl+c \n");  
      /*  close 相关操作*/  
     exit(0);  
}  

void a()
{
    int i = 0;
    int j = 0;
    while(i < 10000000)
    {
        while(j < 1000000)
        {
            printf("\t\t+---call a() function\n");
            j++;
        }
        i++;
    }
}

void c()
{
    printf("\t\t+---call c() function\n");
}

int b()
{
    printf("\t+--- call b() function\n");
    a();
    c();
    return 0;
}

int main()
{
    signal(SIGINT,ctrlhandler);
    printf(" main() function()\n");
    b();
}
