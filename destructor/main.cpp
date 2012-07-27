/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/26/12 16:15:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include    <iostream>
using namespace std;

class Base
{
    public:
        Base(int a) { cout<<"Base constructor"<<endl;}
        virtual ~Base() { cout<<"Base destructor"<<endl;}
};

class Derived:public Base
{
    public:
        Derived():Base(2) { cout<<"Derived constructor"<<endl;}
        ~Derived() { cout<<"Derived destructor"<<endl;}
};

int main(void)
{
    Derived* d1 = new Derived();

    delete d1;
    return 0;
}
