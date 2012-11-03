
/*
 *       Filename:  second.cpp
 *    Description:  
 *         Author:  jumbal
 *          Email:  the.jumbal@gmail.com
 *        Created:  10/22/2012 04:38:56 PM
 */

#include    <iostream>
#include    <boost/filesystem/operations.hpp>

namespace bfs=boost::filesystem;
int main()
{
    bfs::path p("second.cpp");
    if(bfs::exists(p))
        std::cout<<p.leaf()<<std::endl;
}
