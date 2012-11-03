
/*
 *       Filename:  functionAtoi.cc
 *    Description:  
 *         Author:  jumbal
 *          Email:  the.jumbal@gmail.com
 *        Created:  10/23/2012 10:50:35 AM
 */

#include    <boost/function.hpp>
#include    <iostream>
#include    <cstdlib>
#include    <cstring>

struct world{
    void hello(std::ostream& os)
    {
        os<<"Hello World!"<<std::endl;
    }

};

int main()
{
    boost::function<int (const char*)> f = std::atoi;
    std::cout<<f("1609")<<std::endl;
    f = std::strlen;
    std::cout<<f("1609")<<std::endl;

    boost::function<void (world*, std::ostream&)> g = &world::hello;
    world w;
    g(&w, boost::ref(std::cout));
}

