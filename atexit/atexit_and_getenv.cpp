/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  example of atexit
 *
 *        Version:  1.0
 *        Created:  12/10/2012 10:04:06 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <stdlib.h>
#include    <iostream>
using namespace std;

static void my_exit1(void);
static void my_exit2(void);

extern char** environ;

int main(void)
{
    cout<<"environ:"<<*environ<<endl;
    cout<<"getenv(\"COLUMNS\"):"<<getenv("PWD")<<endl;
    if (atexit(my_exit1) != 0)
    {
        cerr<<"atexit error. exit"<<endl;
        exit(-1);
    }

    if (atexit(my_exit2) != 0)
    {
        cerr<<"atexit error. exit"<<endl;
        exit(-1);
    }

    cout<<"Hello World!"<<endl;
    return (0);
}

static void my_exit1(void)
{
    cout<<"my_exit1"<<endl;
}

static void my_exit2(void)
{
    cout<<"my_exit2"<<endl;
}
