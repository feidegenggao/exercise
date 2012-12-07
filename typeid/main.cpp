/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/29/2012 09:30:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <iostream>
#include    <typeinfo>

class ABCDEFGHIJKLMN
{

};

int main()
{
    int a;
    float f;
    double df;
    ABCDEFGHIJKLMN ca;

    std::cout<<"typeid(a).name():"<<typeid(a).name()<<std::endl;
    std::cout<<"typeid(f).name():"<<typeid(f).name()<<std::endl;
    std::cout<<"typeid(df).name():"<<typeid(df).name()<<std::endl;
    std::cout<<"typeid(ca).name():"<<typeid(ca).name()<<std::endl;
    /*
       Live-88:~/lxf/exercise/typeid #./a.out 
       typeid(a).name():i
       typeid(f).name():f
       typeid(df).name():d
       typeid(ca).name():14ABCDEFGHIJKLMN
       14代表后面的名字的长度。
     */
    return 0;
}
