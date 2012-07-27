/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  sizeof
 *
 *        Version:  1.0
 *        Created:  04/02/12 15:11:34
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

int fun(int* array1,int* array2)
{
    cout<<"in fun..."<<endl;
    cout<<"sizeof(array1 = new int[10]):"<<sizeof(array1)<<endl;
    cout<<"sizeof(array2 (int array2[10])"<<sizeof(array2)<<endl;

    return 0;
}

int main(int argc, char** argv)
{
    int *array1 = new int[10];
    int array2[10];
    int *int_pointer;
    int a;

    cout<<"sizeof(array1 = new int[10]):"<<sizeof(array1)<<endl;
    cout<<"sizeof(array2 (int array2[10])"<<sizeof(array2)<<endl;
    cout<<"sizeof(int_pointer(int *int_pointer)"<<sizeof(int_pointer)<<endl;
    cout<<"sizeof(a (int a))"<<sizeof(a)<<endl;

    fun(array1, array2);

    /* 
     * The result of this program on 192.168.1.64:
     *
       sizeof(array1 = new int[10]):8
       sizeof(array2 (int array2[10])40
       sizeof(int_pointer(int *int_pointer)8
       sizeof(a (int a))4
       in fun...
       sizeof(array1 = new int[10]):8
       sizeof(array2 (int array2[10])8

    */
    return 0;
}
