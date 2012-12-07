/*
 * ============================================================================
 *
 *       Filename:  mapSize.cpp
 *
 *    Description:  结果是：map的size()操作和map内元素数量无关。
 *                  而list却是相关的（这是我在别的地方测的的）。
 *
 *        Version:  1.0
 *        Created:  12/03/2012 02:38:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <iostream>
#include    <map>
#include    <sys/time.h>
#include    <stdlib.h>

using namespace std;

int main(int argc, char** argv)
{
    map<int, string> a;
    for (int i = 0; i < atoi(argv[1]); ++i)
    {
        a.insert(map<int, string>::value_type(i, "Hello!"));
    }

    struct timeval oldTime;
    gettimeofday(&oldTime, NULL);

    cout<<"a.size():"<<a.size()<<endl;
    struct timeval newTime;
    gettimeofday(&newTime, NULL);

    cout<<"SubTime:"<<newTime.tv_sec - oldTime.tv_sec<<"s\t"<<\
        newTime.tv_usec - oldTime.tv_usec<<"us"<<endl;
}
