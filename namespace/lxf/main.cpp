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

int main(void)
{
    lxf::widget* a = new lxf::widget();
    a->printInfo();
    lyh::widget b;
    b.printInfo();

    return 0;
}
