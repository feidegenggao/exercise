/*
 * ============================================================================
 *
 *       Filename:  newString.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/07/2012 03:08:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <iostream>
#include    <string>
using namespace std;

string& fun()
{
    string* temp = new string("Hello World");
    return (*temp);
}

int main()
{
    string a = fun();
    cout<<"a:"<<a<<endl;

    return 0;
}
