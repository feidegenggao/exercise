/*
 * ============================================================================
 *
 *       Filename:  a+++++b.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/03/2012 10:47:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <stdio.h>

int main()
{
    int a = 0;
    int b = 0;

    //a+++++b;
    //编译通不过：lvalue required as increment operand
    a+++++b;

    printf("a:%d\tb:%d\n", a, b);

    return 0;
}
