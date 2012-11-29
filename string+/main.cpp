/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/19/12 14:11:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *        Company:  NDSL
 *
 * =====================================================================================
 */
#include    <iostream>
using namespace std;

int main()
{
    string a("Hello");
    string b(" world!");
    string c = a + b;

    cout<<"c:"<<c<<endl;

    //This is wrong , reason:invalid conversion from ‘int’ to ‘const char*’
    //string d (2);
    //cout<<"d:"<<d<<endl;


    //Is Ok ?
    //no, reason:  expected primary-expression before ‘e’
    // expected ‘;’ before ‘e’
    //c = string e("Hello lyh");
    //Oh, int z; z = int c = 2; This is the same
    int z = 0, y;
    z = y = 2;
    cout<<"z:"<<z<<"\ty:"<<y<<endl;
    //cout<<"c:"<<c<<endl;
    return 0;
}
