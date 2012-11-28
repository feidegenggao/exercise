/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  派生类的析构函数和基类的析构函数之间的执行关系
 *
 *        Version:  1.0
 *        Created:  2012年09月25日 09时50分58秒
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

class Base{
    public:
        Base() { std::cout<<"new Base()"<<std::endl;}
        virtual ~Base() { std::cout<<"~Base()"<<std::endl; this->recyler();}

        virtual void recyler() { std::cout<<"~Base() recyler()"<<std::endl;}
        virtual int fun() { std::cout<<"Base::fun()"<<std::endl;}
    private:
        int b;
};

class Sub : public Base{
    public:
        Sub() { std::cout<<"new Sub()"<<std::endl;}
        virtual ~Sub() { std::cout<<"~Sub()" <<std::endl; recyler();}

        virtual void recyler() { std::cout<<"~Sub() recyler()"<<std::endl;}
        int fun(){ Base::fun(); std::cout<<"Sub::fun()"<<std::endl;}
    private:
        int s;
};

int main(void)
{
    Sub* p_sub = new Sub();
    p_sub->fun();
    //p_sub->recyler();
    delete p_sub;
    /*
     *    先执行基类的构造函数，之后调用派生类的构造函数，
     *    析构的时候，先调用派生类的析构函数，之后调用基类的析构函数。
     */

    return 0;
}
