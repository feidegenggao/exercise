/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/19/12 16:32:59
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

int main()
{
    char* senddata = new char[50];
    int* p_data = (int*)senddata;

    *p_data = 2;
    p_data++;
    *p_data = 3;
    p_data++;

    std::cout<<"p_data - (int*)senddata)*sizeof(int):"<<((char*)p_data - senddata)*1<<"EOF"<<std::endl;
    return 0;
}
