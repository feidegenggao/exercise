#include    "../my.h"

class A
{
    public:
        A(){}
        virtual ~A(){}
        virtual int test() { cout<<"A->test()"<<endl;}
};

class B:public A
{
    public:
        B(){}
        ~B(){}
        virtual int test() { cout<<"B->test()"<<endl;}
};
        
int main()
{
    A* pb = new B();

    pb->test();

    return 0;
}
