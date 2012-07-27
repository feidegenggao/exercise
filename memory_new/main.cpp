/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/02/12 15:05:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Heaven (), zhanwenhan@163.com
 *        Company:  NDSL
 *
 * =====================================================================================
 */
#include    <iostream>

using namespace std;
struct header
{
    int cmd;
    int len;
    char *databuf;
};
int main(int argc, char** argv)
{
    struct header *h_pointer = new struct header;
    h_pointer = NULL;

    if ( h_pointer)
        cout<<"h_pointer's cmd is:"<<h_pointer->cmd<<endl;
    else
        cout<<"h_pointer is NULL"<<endl;

    return 0;
}
