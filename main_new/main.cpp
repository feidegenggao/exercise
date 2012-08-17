/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/13/12 17:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Higher (feidegenggao), liuxiaofei333@gmail.com
 *   Organization:  NDSL UESTC
 *
 * =====================================================================================
 */
#include   "../my.h"
#include    <stdio.h>

//can new class here?
//cout<<"cout comment before main() function"<<endl;
int aaa = printf("Hello world1");
class A{
    public:
        A() { cout<<"A->A()"<<endl;}
        ~A() { cout<<"A->~A()"<<endl;}

    private:
        int test;
        float teststt;
};

A *a = new A();

int
main()
{

    A *b = new A();
    cout<<"sizeof(a)"<<sizeof(*a)<<"sizeof(b)"<<sizeof(*b)<<endl;
    return 0;
}
