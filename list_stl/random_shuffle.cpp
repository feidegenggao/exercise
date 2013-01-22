/*
 * ============================================================================
 *
 *       Filename:  random_shuffle.cpp
 *
 *    Description:  only support vector, can't use for list 
 *
 *        Version:  1.0
 *        Created:  01/22/13 14:51:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <iostream>
#include    <vector>
#include    <algorithm>
#include    <vector>

using namespace std;

int main()
{
    vector<int> testList;
    for ( int i = 0; i < 10; i++)
        testList.push_back(i);

    random_shuffle(testList.begin(), testList.end());

    for (vector<int>::iterator it = testList.begin(); it != testList.end(); it++)
        cout<<"it:"<<*it<<endl;
}
