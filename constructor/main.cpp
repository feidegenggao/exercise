/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/01/12 09:56:42
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

class foo
{
    public:
        foo() { cout<<"constructor"<<endl;}
        foo(const foo&) { cout<<"copy constructor"<<endl;}
        int operator = (const foo& ) { cout<<"operator = constructor"<<endl;}
        ~foo() { cout<<"destructor"<<endl;}
};

int main()
{
    foo a;
    foo b;
    b = a;
}
