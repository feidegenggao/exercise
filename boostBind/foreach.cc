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

    return 0;
}
