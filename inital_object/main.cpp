/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/07/12 19:48:13
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
        //Base():m_int(222) { cout<<"Base:inital"<<endl;}
        Base(int a):m_int(a) { cout<<"Base:inital"<<endl;}
        void print() { cout<<"m_int:"<<m_int<<"\tm_int2:"<<m_int2<<endl;}
    protected:
        int m_int;
        int m_int2;
};

class Sub:public Base
{
    public:
        Sub():Base(2) { cout<<"Sub:inital"<<endl;}
        void print() { Base::print(); cout<<"m_int3:"<<m_int3<<endl;}
    private:
        int m_int3;

};

int main()
{
    Base a(2);
    a.print();

    Sub s;
    s.print();

    return 0;
}
