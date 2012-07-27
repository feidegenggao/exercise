/*
 * =====================================================================================
 *
 *       Filename:  hide.cpp
 *
 *    Description:  exmples of hide rule in c++
 *
 *        Version:  1.0
 *        Created:  04/07/12 18:44:40
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
typedef void(*fun)(void);
const int POINTER_LEN = sizeof(int*)/sizeof(int);

class Base
{
    public:
        virtual void f(int x) { cout<<"Base:"<<x<<endl;}
};

class Derived:public Base
{
    public:
        void f(char* str) { cout<<"Derived:"<<str<<endl;}
        void f(int x) { Base::f(x);}
};

int main()
{
    Derived* p_Derived = new Derived;
    p_Derived->f(10);

    fun p_fun = NULL;
    p_fun = (fun)*((int*)*(int*)(&p_Derived));
    if (p_fun)  p_fun(); else return 0;

    return 0;
}
