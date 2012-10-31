/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年10月24日 10时41分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    "../my.h"

class lock
{
    public:
        explicit lock(int nu):ele(nu) {cout<<"new lock"<<endl;}
        ~lock(){cout<<"destruct lock"<<endl;}

        void print(void) { cout<<"ele:"<<ele<<endl;}

    private:
        int ele;
};

int main()
{
    lock* plock = new lock(2);

    plock->print();

    delete plock;

}
