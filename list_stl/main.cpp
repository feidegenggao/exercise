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
void printit(int& int_arg)
{
    cout<<"ele:"<<int_arg<<endl;
}

class syncbuffer{
    public:
        syncbuffer(){}
        ~syncbuffer(){}
        /*
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
        */

        int insert_element(int temp)
        {
            cout<<"insert_element"<<endl;
            //从后往前插入
            list<int>::iterator it;
            it = element_list.end();

            int listsize = element_list.size();
            if (listsize > 0)
            {
                it--;
                for(int i = 0; i < listsize; it--, i++)
                {
                    if ((*it) < temp)
                    {
                        element_list.insert(++it, temp);
                        return 0;
                    }
                }
                element_list.push_front(temp);
                return 0;
            }

            element_list.push_back(temp);
            
            return 0;
        }



        void print_ele()
        {
            list<int>::iterator it;
            if (element_list.size() > 0)
                for(it = element_list.begin(); it != element_list.end(); it++)
                {
                    cout<<"buffer_ele:"<<(*it)<<endl;
                }
        }

        list<int> element_list;
};

struct _header_{
    int a;
    int b;
};
typedef struct _header_ MsgHeader;

int main(void)
{
    list<int> list_test;
    list<int>::iterator list_itor;
    list_itor = list_test.begin();
    if (list_itor == list_test.end())
        cout<<"begin == end if list is empty"<<endl;
    else
        cout<<"begin != end when list is empty"<<endl;
    list<MsgHeader*> headerlist;


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


    //list，如果list是空的，则list.begin()访问元素是否是错误的？
    //MsgHeader* header_temp;
    //header_temp->a = 1;
    //header_temp->b = 2;
    //headerlist.push_back(header_temp);
    //cout<<"headerlist->begin()->a:"<<(*headerlist.begin())->a<<endl;

    
    return 0;
}
