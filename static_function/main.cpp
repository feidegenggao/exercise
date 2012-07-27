/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/15/12 18:28:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
//#include    "header.cpp"
#include    <iostream>
using namespace std;
int getfd(int);
int copy_getfd(int);

int main(void)
{
    int a = 0;
    int a_copy = 0;

    a = getfd(a);
    a_copy = copy_getfd(a_copy);

    cout<<"over"<<endl;
    return 0;
}
