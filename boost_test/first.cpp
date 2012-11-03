
/*
 *       Filename:  first.cpp
 *    Description:  
 *         Author:  jumbal
 *          Email:  the.jumbal@gmail.com
 *        Created:  10/22/2012 04:36:50 PM
 */

#include<iostream>
#include<boost/any.hpp>

int main()
{
    boost::any a(5);
    a = 7.67;
    std::cout<<boost::any_cast<double>(a)<<std::endl;
}
