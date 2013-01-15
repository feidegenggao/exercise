/*
 * ============================================================================
 *
 *       Filename:  defaultConstructor.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/12/13 10:28:05
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

class Foo 
{ 
    public:
        Foo(){ cout<<"new foo use default"<<endl;} 
        Foo(int) { cout<<"new foo with int"<<endl;}
};

class Bar
{
    public:
        Bar() { cout<<"new Bar use default"<<endl;}
        Bar(int) { cout<<"new Bar with int"<<endl;}
        Bar(int a = 0) { cout<<"new Bar with default parameter"<<endl;}
        Foo foo;
        char* str;
};

int main(void)
{
    Bar bar;
    return 0;
}
