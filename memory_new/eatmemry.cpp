/*
 * =====================================================================================
 *
 *       Filename:  eatmemry.cpp
 *
 *    Description:  test if a progrom can new memory ulimitly
 *
 *        Version:  1.0
 *        Created:  04/07/12 12:58:41
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

int main(int argc, char** argv)
{
    float *p = NULL;
    long int i = 0;
    while(1)
    {
        try
        {
            p = new float[1024*1024];
        }
        catch(bad_alloc)
        {
            cout<<"Bad allocation"<<endl;
            sleep(100);
            break;
        }
        cout<<"eat memory:"<<i*sizeof(float)<<endl;
        if (NULL == p)
        {
            cout<<"can't new memory"<<endl;
            break;
        }
        else
        {
            ++i;
        }
    }

    return 0;
}
