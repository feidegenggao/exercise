/*
 * =====================================================================================
 *
 *       Filename:  static_local_variables.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/02/12 09:42:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Heaven (), zhanwenhan@163.com
 *        Company:  NDSL
 *
 * =====================================================================================
 */
#include    <stdio.h>

int main(int argc, char** argv)
{
    int fun(int n);

    int i;

    for (i = 1; i < 4; ++i)
    {
        printf("%d! = %d\n", i, fun(i));
    }

    printf("static_local_variables result:%d\n", result);

    return 0;
}

int fun(int n)
{
    static int result = 1;

    result *= n;

    return result;
}
