/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/28/2012 05:48:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <iostream>
using namespace std;

void* fun(void)
{
    cout<<"fun"<<endl;
}

void* foo(void)
{
    cout<<"foo"<<endl;
}

typedef void* testfun(void);
void call(void* a , void* b)
{
    cout<<"call"<<endl;
}

int main()
{
    call(fun(), foo());
}
