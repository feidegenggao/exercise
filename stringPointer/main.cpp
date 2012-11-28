/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/28/2012 03:20:06 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <string>
#include    <iostream>
void fun(std::string* st)
{
    std::string temp = "Hello World";
    *st = &temp;
}

int main()
{
    std::string a;
    std::cout<<"a:"<<a<<std::endl;
    fun(&a);
    std::cout<<"a:"<<a<<std::endl;
}
