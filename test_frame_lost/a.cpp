/*
 * ============================================================================
 *
 *       Filename:  a.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年10月22日 10时09分48秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    "../my.h"
int fun(void)
{
    static int num = 0;
    cout<<"num:"<<num<<endl;
    num++;
    return 0;
}

int main(void)
{
    while(1)
        fun();
    return 0;
}
