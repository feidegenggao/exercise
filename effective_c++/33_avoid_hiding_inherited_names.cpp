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
        void mf3(void) const { mf2(); }
};

int main(void)
{
    Derived d1 = Derived();
    //d1.mf1();

    //d1.mf3();
    return 0;
}
