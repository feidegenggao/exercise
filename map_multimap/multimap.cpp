/*
 * =====================================================================================
 *
 *       Filename:  multimap.cpp
 *
 *    Description:  usage of multimap
 *
 *        Version:  1.0
 *        Created:  03/30/12 03:15:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (lxf), 
 *        Company:  
 *
 * =====================================================================================
 */
#include    <iostream>
#include    <map>
using namespace std;

typedef multimap<int, string, int>::value_type  valType_complex;
typedef multimap<int, string>::value_type  valType;
int main(void)
{
    multimap<int , string, int> file_location_complex;
    multimap<int , string> file_location;

    file_location.insert(valType(1, string("1")));
    file_location_complex.insert(valType_complex(1, string("2"), 1));
    
}
