/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  对象切割的意思是：
 *    void fun(Base a);
 *    Drived d;
 *    fun(d);
 *    在这样调用的时候，fun中调用Base的虚函数时调用的是Base的虚函数而非d的虚函数。
 *
 *
 *
 *        Version:  1.0
 *        Created:  10/31/12 14:52:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    "../my.h"

void fun(Base a)
{
    a.fun();
}
int main()
{
    Drived d;
    fun(d);
}
