/*
 * ============================================================================
 *
 *       Filename:  find_first_of.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/14/13 10:54:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <string>
#include    <iostream>
using namespace std;

int main(void)
{
    string str ("Replace the vowels in this sentence by asterisks.");
    size_t found;

    found=str.find_first_of("aeiou");
    while (found!=string::npos)
    {
        str[found]='*';
        cout<<"found:"<<found<<endl;
        found=str.find_first_of("aeiou",found+1);
    }

    cout << str << endl; 
    return 0;
}
