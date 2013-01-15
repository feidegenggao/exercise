/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/04/2012 02:34:48 PM
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

class Man
{
    public:
        Man(){}
        ~Man(){}

    private:
        /* 
        class a
        {

        };

        class b
        {

        };
        */
};

class widget
{
    public:
        int a() const { return a_;}
        int b() const { return b_;}
    private:
        int a_;
        int b_;
};

int main()
{
    Man man;
    cout<<"sizeof Man:"<<sizeof(man)<<endl;
    widget w;
    cout<<"sizeof widget:"<<sizeof(w)<<endl;
}
