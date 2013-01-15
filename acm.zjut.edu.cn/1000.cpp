/*
 * ============================================================================
 *
 *       Filename:  1000.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/04/13 20:08:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <iostream>
using namespace std;

int main()
{
    int a, b;
    do{
        cin>>a;
        cin>>b;
        if (a == 0 and b == 0)
        {
            break;
        }
        cout<<a + b<<endl;
    }while(true);

    return 0;
}
