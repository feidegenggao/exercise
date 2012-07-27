/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/22/12 21:34:11
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

class A;
class B
{
    friend class A;
    public:
        explicit B(int b_arg):m_B(b_arg){ cout<<"new B"<<endl;}
    private:
    int m_B;
};

class A
{
    public:
        int display()
        {
            B b(2);
            cout<<"B:m_B"<<b.m_B<<endl;
        }
};

int main(void)
{
    A a;
    a.display();
}
