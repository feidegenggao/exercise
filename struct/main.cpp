/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  usage of struct 
 *
 *        Version:  1.0
 *        Created:  08/12/12 20:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Higher (feidegenggao), liuxiaofei333@gmail.com
 *   Organization:  NDSL UESTC
 *
 * =====================================================================================
 */
#include    "../my.h"
struct pos
{
    int x;
    int y;
};

int
main()
{
    struct pos a;
    a.x = 1;
    a.y = 2;

    struct pos b;
    b = a;

    cout<<"b.x:"<<b.x<<endl;
    cout<<"b.y:"<<b.y<<endl;

    return 0;
}
