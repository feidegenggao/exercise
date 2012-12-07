/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/30/2012 02:17:57 PM
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

class A
{
    public:
        A():id_(2), name_("lxf")
    {

    }
        ~A()
        {

        }

        int id() const { return id_;}
        string name() const { return name_;}

    private:
        int id_;
        string name_;
};

int main()
{
    A a;
    cout<<"sizeof(a):"<<sizeof(a)<<endl;
}
