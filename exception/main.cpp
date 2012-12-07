/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/30/2012 02:42:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <iostream>
using namespace std;

class CRException
{
    public:
        CRException(int nu) : nu_(nu) {}

        int nu() const { return nu_;}
    private:
        int nu_;

};

void foo()
{
    cout<<"foo()"<<endl;
    throw CRException(2);
}

void fun()
{
    cout<<"fun()"<<endl;
    foo();
}

int main()
{
    int a = 0;
    try
    {
        switch (a)
            {
                case 0:
                    {
                        fun();
                        break;
                    }
                case 1:
                    {
                        break;
                    }
                default:
                    {
                        break;
                    }
            }
    }
    catch(CRException ex)
    {
        cout<<"Exception's nu:"<<ex.nu()<<endl;
    }
}
