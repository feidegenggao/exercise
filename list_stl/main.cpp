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
#include <sys/time.h>

using namespace std;
void printit(int& int_arg)
{
    cout<<"ele:"<<int_arg<<endl;
}

class syncbuffer{
    public:
        syncbuffer(){}
        ~syncbuffer(){}
        int insert_element(int temp)
        {
            list<int>::iterator it;
            for(it = element_list.begin(); it != element_list.end(); it++)
            {
                if ((*it) > temp)
                {
                    element_list.insert(it, temp);
                    break;
                }
            }
            if (element_list.end() == it)
                element_list.push_back(temp);
        }

        void print_ele()
        {
            list<int>::iterator it;
            for(it = element_list.begin(); it != element_list.end(); it++)
            {
                cout<<"buffer_ele:"<<(*it)<<endl;
            }
        }

        list<int> element_list;
};

int main(void)
{
    list<int> list_test;

    for (int i = 0; i < 5; i++)
    {
        if (i != 4000)
            list_test.push_back(i);
    }

    int i;
    struct timeval timenow1;
    struct timeval timenow2;
    gettimeofday(&timenow1, NULL);

    int listsize = list_test.size();                                             
    //list_test.push_back(10000);
    //i = 50;


    list<int>::iterator  it = list_test.end(); 
    it--;                                                                      
    for (int i = 0; i < listsize; it--, i++)                                   
    {                                                                          
        if ((*it) < 4000)
        {
            list_test.insert(++it, 4000);
            break;
        }
    }

    gettimeofday(&timenow2, NULL);
    cout<<"ms1:"<<timenow1.tv_usec<<endl;
    cout<<"ms2:"<<timenow2.tv_usec<<endl;
    return 0;






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
        std::for_each(list_test.begin(), list_test.end(), printit);
    }

    list<int>::iterator list_itor;
    list_itor = list_test.begin();
    //cout<<"list的迭代器："<<list_itor<<endl;
    list_itor++;
    list_test.erase(list_test.begin());
    if (list_test.begin() == list_itor)
        cout<<"删除过后，list的begin和list_itor是一样的了"<<endl;
    list_itor++;
    cout<<"itor:"<<*list_itor<<endl;
    cout<<"list.back():"<<list_test.back()<<endl;

    for (list_itor = list_test.begin(); list_itor != list_test.end();)
    {
        cout<<"itor:"<<*list_itor<<endl;
        list_test.erase(list_itor++);
    }

    list_test.clear();

    list_test.push_back(1);
    list_test.push_back(3);
    list_test.push_back(4);

    std::for_each(list_test.begin(), list_test.end(), printit);

    std::cout<<"After Insert()"<<std::endl;
    list_itor = list_test.end();
    list_test.insert(list_itor, list_test.begin(), list_test.end());

    list_test.insert(--list_itor, 5);
    std::for_each(list_test.begin(), list_test.end(), printit);

    //下面进行插入的操作，每次插入找到合适的位置，合适的位置是指按大小顺序排列元素位置。
    syncbuffer buffer;
    buffer.insert_element(4);
    buffer.insert_element(5);
    buffer.insert_element(1);
    buffer.insert_element(2);
    buffer.print_ele();

    return 0;
}
