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

using namespace std;
void printit(int& int_arg)
{
    cout<<"ele:"<<int_arg<<endl;
}

int main(void)
{
    list<int> list_test;

    list_test.push_back(1);
    list_test.push_back(2);
    list_test.push_front(3);
    list_test.push_front(4);

    if (list_test.empty())
    {
        cout<<"list_test empty()"<<endl;
    }

    else
    {
        for_each(list_test.begin(), list_test.end(), printit);
    }

    list<int>::iterator list_itor;
    for (list_itor = list_test.begin(); list_itor != list_test.end();)
    {
        cout<<"itor:"<<*list_itor<<endl;
        list_test.erase(list_itor++);
    }

    return 0;
}
