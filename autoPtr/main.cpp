/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  智能指针
 *
 *        Version:  1.0
 *        Created:  2012年10月24日 09时48分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    "../my.h"
#include    <tr1/memory>

class Investment
{
    public:
        Investment():element(2){ cout<<"new Investment"<<endl;}
        ~Investment(){ cout<<"destruct Investment"<<endl;}

        void print(void) { cout<<"Investment print(void)"<<endl;}
        int element;

    private:
};

Investment* creatInvestment(void)
{
    Investment* pInv = new Investment();
    return pInv;
}

void f()
{
    std::auto_ptr<Investment> pInv(creatInvestment());
    pInv->print();
    std::auto_ptr<Investment> pInv2(pInv);
    //pInv2 = pInv;
    pInv->print();
    cout<<"pInv->element:"<<pInv->element<<endl;
    pInv2->print();

    std::tr1::shared_ptr<Investment> sharedPInv(creatInvestment());
    std::tr1::shared_ptr<Investment> sharedPInv2(sharedPInv);
    //creatInvestment();
}

int main()
{
    f();
    return 0;
}
