/*
 * =====================================================================================
 *
 *       Filename:  hello.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/19/12 21:35:52
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

int main(int argc, char** argv)
{
    cout<<"Hello Wrold!"<<endl;
    for (int i = 0; i < argc; i++)
    {
        cout<<"argv["<<i<<"]:"<<argv[i]<<endl;
    }
    return 0;
}
