/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/27/12 17:57:48
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

class Test
{
    public:
        Test(int a_arg):a(a_arg) { cout<<"new o"<<endl;}
        ~Test() { cout<<"~ o"<<endl;}
        int fun(void) 
        { 
            cout<<"this.a:"<<this->a<<endl;
            cout<<"this:"<<this<<endl;
        }
    private:
        int a;
};

int main(void)
{
    Test t1(2);
    t1.fun();

    return 0;
}
