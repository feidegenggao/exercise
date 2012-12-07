/*
 * ============================================================================
 *
 *       Filename:  insert.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/05/2012 03:44:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <iostream>
#include    <map>
using namespace std;

//map can't insert the value which has same key

void insertEle(map<int, int>& temp, int ele1, int ele2)
{
    pair<map<int, int>::iterator, bool> rt;

    rt = temp.insert(map<int, int>::value_type(ele1, ele2));

    cout<<"map.size():"<<temp.size()<<"\tmap.begin:"<<temp.begin()->first<<"\t"\
        <<temp.begin()->second<<endl;

    if (rt.second)
    {
        cout<<"insert successful"<<endl;
    }
    else
    {
        cout<<"insert failed"<<endl;
    }
}

int eraseEle(map<int, int>& temp, int key)
{
    int rt = temp.erase(key);
    if (rt == 1)
    {
        cout<<"erase success"<<endl;
    }
    else if (rt == 0)
    {
        cout<<"erase failed"<<endl;
    }
    return rt;
}

int eraseEleCom(map<int, int>& temp, int first, int second)
{
    int rt = temp.erase(first, second);
    if (rt == 1)
    {
        cout<<"erase success"<<endl;
    }
    else if (rt == 0)
    {
        cout<<"erase failed"<<endl;
    }
    return rt;
}

int main()
{
    map<int, int> temp;

    insertEle(temp, 1, 2);
    insertEle(temp, 1, 3);

    eraseEleCom(temp, 1, 2);
    eraseEleCom(temp, 1, 2);

    return 0;
}
