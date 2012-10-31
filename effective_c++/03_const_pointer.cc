/*
 * ============================================================================
 *
 *       Filename:  03_const_pointer.cc
 *
 *    Description:  The 3rd items is :
 *    Use const whenever possible
 *
 *        Version:  1.0
 *        Created:  10/20/12 23:10:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include "../my.h"
int main()
{
    char greeting[] = "Hello";
    char* p1 = greeting;
    const char* p2 = greeting;
    char* const p3 = greeting;
    const char* const p4 = greeting;

    greeting = "LiuXiaofei";
    cout<<"char* p1:"<<p1<<endl;
    cout<<"const char* p2:"<<p2<<endl;
    cout<<"char* const p3:"<<p3<<endl;
    cout<<"const char* const p4:"<<p4<<endl;
    return 0;
}
