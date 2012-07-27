/*
 * =====================================================================================
 *
 *       Filename:  delete.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/02/12 11:15:39
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

typedef struct trans_header
{
    int cmd;
    int length;
    char *data;
}header;

int main(int argc, char** argv)
{
    int *int_pointer = new int [100];
    header *head_pointer = new header[100];

    delete [] int_pointer;
    delete head_pointer;
    return 0;
}
