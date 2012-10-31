/*
 * ============================================================================
 *
 *       Filename:  07_virtual_dstruct_for_base.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/31/12 16:42:50
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

class base
{
    public:
        base()
        {
            cout<<"base new"<<endl;
        }
        ~base(){
            cout<<"base destructor "<<endl;
        }
};

class drived : public base
{
    public:
        drived()
        {
            cout<<"drived new"<<endl;
        }

        ~drived()
        {
            cout<<"drived destructor"<<endl;
        }
};

int main()
{
    drived* pdri = new drived();
    delete pdri;
}
