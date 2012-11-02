/*
 * ============================================================================
 *
 *       Filename:  first.cpp
 *
 *    Description:  test boost 
 *
 *        Version:  1.0
 *        Created:  10/22/12 16:26:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <iostream>
#include    <boost/any.hpp>

int main()
{
    boost::any a(5);
    a = 7.67;
    std::cout<<boost::any_cast<double>(a)<<std::endl;
}
