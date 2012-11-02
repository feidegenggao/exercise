/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年10月24日 10时41分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    "../my.h"

class lock
{
    public:
        explicit lock(int nu):ele(nu) {cout<<"new lock"<<endl;}
        lock(const lock& ) { cout<<"copy constructor"<<endl;}
        ~lock(){cout<<"destruct lock"<<endl;}

        void print(void) const { cout<<"ele:"<<ele<<endl;}

    private:
        int ele;
};

void fun(const lock& a)
{
    cout<<"fun"<<endl;
    a.print();
    cout<<"fun end"<<endl;
}

int main()
{
    lock plock(2);
    fun(plock);
    //如果lock的构造函数，没有explicit限制符的话，下面的函数是可以通过编译的。
    //这就是c++中的隐式转换
    //如果有explicit限制符的话，编译时通不过的。
    fun(2);
}
