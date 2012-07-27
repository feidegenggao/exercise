/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  overload override and hide
 *
 *        Version:  1.0
 *        Created:  04/07/12 13:53:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *        Company:  NDSL
 *
 * =====================================================================================
 */
#include    "../my.h"

typedef void(*fun)(void);
const int POINTER_LEN = sizeof(int*)/sizeof(int);

int main(void)
{
    Derived d;
    Base *p_base = &d;
    Derived *p_derived = &d;

    fun p_fun = NULL;
    p_fun = (fun)*((int*)*(int*)(&d));
    if (p_fun)  p_fun(); else return 0;
    p_fun = (fun)*((int*)*(int*)(&d)+1*POINTER_LEN);
    if (p_fun)  p_fun(); else return 1;
    p_fun = (fun)*((int*)*(int*)(&d)+2*POINTER_LEN);
    if (p_fun)  p_fun(); else return 2;
    p_fun = (fun)*((int*)*(int*)(&d)+3*POINTER_LEN);
    if (p_fun)  p_fun(); else return 3;


    cout<<"TEST EOF"<<endl;
    //Good:behavior depends solely on type of the object
    p_base->f(3.1f);
    p_derived->f(3.1f);

    //Bad:behavior depends on type of the pointer
    p_base->g(3.1f);
    p_derived->g(3.1f);

    //Bad:behavior depends on type of the pointer
    p_base->h(3.1f);
    p_derived->h(3.1f);


    p_base->i(3.1f);
    p_derived->i(3.1f);

    /*output:
     *
     * Derived::f(float):3.1
     * Derived::f(float):3.1
     * Base::g(float):3.1
     * Derived::g(float):3
     * Base::h(float):3.1
     * Derived::h(float):3.1
     * Base::i(float):3.1
     * Base::i(int):3
     *
     * */
}
