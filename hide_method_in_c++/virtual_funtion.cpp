/*
 * =====================================================================================
 *
 *       Filename:  virtual_funtion.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/07/12 19:00:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *        Company:  NDSL
 *
 * =====================================================================================
 */
#include    <iostream>
using namespace std;
class Base
{
    public:
        virtual void fn() { cout<<"Base:fn()"<<endl;}
};
class Sub:public Base
{
    public:
        virtual void fn() { cout<<"Sub:fn()"<<endl;}
};

void test(Base& b)
{
    b.fn();
}

void test_foo(Base b)
{
    b.fn();
}

int main()
{
    Base b;
    Sub  c;
    test(b);
    test(c);
    test_foo(b);
    test_foo(c);

    return 0;
}
