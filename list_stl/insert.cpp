/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/27/12 17:07:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include    <iostream>
#include    <list>
#include    <algorithm>

using namespace std;
void printit(list<int> temp)
{
    for (list<int>::iterator it = temp.begin(); it != temp.end(); it++)
    {
        cout<<"ele:"<<*it<<endl;
    }
}

int main(void)
{
    list<int> tempa;
    tempa.push_back(1);
    tempa.push_back(2);
    tempa.push_back(3);

    list<int> tempend;
    tempend.push_back(11);
    tempend.push_back(13);


    tempend.insert(tempend.end(), tempa.begin(), tempa.end());

    printit(tempend);
   return 0;
}
