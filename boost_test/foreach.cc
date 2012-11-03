/*
 * ============================================================================
 *
 *       Filename:  foreach.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/23/12 10:12:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    "../my.h"
#include    <boost/bind.hpp>
#include    <vector>
#include    <algorithm>
#include    <functional>

class add
: public std::binary_function<int, int, void>
{
    public:
        void operator()(int i, int j) const
        {
            std::cout<<i + j<<std::endl;
        }
};

void add_func(int i, int j)
{
    std::cout<<i + j<<std::endl;
}

//这个为什么必须用引用而不能用std::ostream os
void add_func_useost(int i, int j, std::ostream& os)
{
    os<<i + j<<std::endl;
}

void print(int i)
{
    cout<<" "<<i<<endl;
}

int main()
{
    vector<int> myvector;

    myvector.push_back(1);
    myvector.push_back(2);
    myvector.push_back(3);

    std::for_each(myvector.begin(), myvector.end(), print);
    std::for_each(myvector.begin(), myvector.end(), std::bind1st(add(), 10));
    std::for_each(myvector.begin(), myvector.end(), 
            boost::bind(add_func, 10, _1));
    std::for_each(myvector.begin(), myvector.end(), 
            boost::bind(add_func_useost, 10, _1, boost::ref(std::cout)));

    //为什么下面的用法没错，而上面的函数如果用这种用法会错的。
    add_func_useost(10, 20, std::cout);

    return 0;
}
