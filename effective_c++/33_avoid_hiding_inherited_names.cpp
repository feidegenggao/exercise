/*
 * ============================================================================
 *
 *       Filename:  33_avoid_hiding_inherited_names.cpp
 *
 *    Description:  尽量避免遮掩继承而来的名字。
 *
 *        Version:  1.0
 *        Created:  11/03/12 11:20:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <iostream>
class Base{
    public:
        Base() { std::cout<<"new Base()"<<std::endl; }
        ~Base() { std::cout<<"destruct Base()"<<std::endl; }

        void mf1(void) const { std::cout<<"Base::fm1(void)"<<std::endl; }

    private:
        void mf2(void) const { std::cout<<"Base::fm2(void)"<<std::endl; }
};

class Derived : public Base{
    public:
        Derived() : mf1(1) { std::cout<<"new Derived()"<<std::endl; }
        ~Derived() { std::cout<<"destruct Derived()"<<std::endl; }
        int mf1;
        //public继承后，派生类依然看不到基类的private成员。
        //private的意思就是只有我自己可以看到，别人（包括我的派生类）
        //都是看不到的。所以下面的调用基类的mf2( )会报错的。编译通不过。
        void mf3(void) const { mf2(); }
};

int main(void)
{
    Derived d1 = Derived();
    //派生类中mf1是一个整型，而基类中同名的为一个函数。
    //但是名称遮掩说的是名称，而非别的什么。所以在派生类中是看不到基类的
    //mf1函数的。所以，下面的调用是不合法的。因为派生类中只有一个mf1整型
    //可供调用，而这个整型是不能当作函数调用的。
    //d1.mf1();

    //d1.mf3();
    return 0;
}
