/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/20/2012 12:00:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    "./lxf.h"
#include    "../lyh/lxf.h"

using namespace lxf::base;
//定义命名空间时，不需要在命名空间末尾加分号。
//本示例在这方面做错了。要记得改正。
int main(void)
{
//    lxf::widget* a = new lxf::widget();
 //   a->printInfo();
    widget* a = new widget();
    a->printInfo();
    lyh::widget b;
    b.printInfo();

    return 0;
}
