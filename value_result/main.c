/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/01/2012 11:02:48 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <stdio.h>

void fun(char** a)
{
    *a = "Hello lyh";
}

int main()
{
    char* a = "Hello lxf";
    printf("a:%s\n", a);
    fun(&a);
    printf("a:%s\n", a);
}
