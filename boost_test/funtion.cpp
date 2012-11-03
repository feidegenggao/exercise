
/*
 *       Filename:  funtion.cpp
 *    Description:  
 *         Author:  jumbal
 *          Email:  the.jumbal@gmail.com
 *        Created:  10/22/2012 04:49:24 PM
 */

#include    <iostream>
using namespace std;
#include    <boost/function.hpp>

bool func(int i, double d)
{
    return i > d;
}

int main()
{
    boost::function<bool (int, double)> f;
    f = &func;

    if (f(10, 1.1))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }

    return 0;
}
