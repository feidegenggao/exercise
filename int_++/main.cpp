/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  int型数字不断++会变成负值吗？会。
 *    unsigned int呢？
 *
 *        Version:  1.0
 *        Created:  11/07/2012 12:08:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <iostream>

int main(void)
{
    //int i = 0;
    unsigned int i = 0;

    while(1)
    {
        std::cout<<"i:"<<i<<std::endl;
        i+=10000000;
    }
}
