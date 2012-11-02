#ifndef     _MY_HEADER
#define     _MY_HEADER
#include    <iostream>
#include    <string.h>
using namespace std;
using std::cin;
using std::cerr;
using std::cout;
using std::endl;
class Base
{
    public:
        Base()
        {
            cout<<"new Base()"<<endl;
        }

        Base(const Base& basetemp)
        {
            //拷贝构造函数参数类型为什么是引用类型？为什么？你不用引用类型试试。
            //编译器不会放过你的。
            //我说一下，为什么必须是引用类型。有一篇博客解释的很清楚：
            //http://blog.csdn.net/tunsanty/article/details/4264738
            //我用自己的话总结一下：假设，函数void func(Base b); Base a; fun(a);
            //这会发生什么呢？func第一次调用会调用Base的拷贝构造函数，构造参数b
            //调用拷贝构造函数Base(const Base basetemp1);
            //这个函数中要重新调用拷贝构造函数Base(const Base basetemp2);构造
            //basetemp1，为了basetemp1要调用拷贝构造函数Base(cont Base base3);
            //构造basetemp2，这样一直无穷无尽的调用。会把内存耗尽的。
            cout<<"copy Base()"<<endl;
        }
        Base& operator = (const Base& basetemp)
        {
            //赋值构造函数，返回值类型不是必须是Base&类型，你可以指定类型，
            //比如：int void, 只是没这个必要。
            //Effective C++中讲到，最好是在赋值构造函数中，返回：reference to *this
            //这样可以实现连锁赋值：
            //a = b = c = 15;
            //标准库中很多类型都是这样实现的，所以，你还是从了吧。
           
            cout<<"assignment Base()"<<endl;
            return* this;
        }
        virtual ~Base()
        {
            cout<<"destruct Base()"<<endl;
        }

        virtual void fun() const
        {
            cout<<"Base::fun()"<<endl;
        }

};

class Drived : public Base
{
    public:
        Drived()
        {
            cout<<"new Drived()"<<endl;
        }
        virtual ~Drived()
        {
            cout<<"destruct Drived()"<<endl;
        }

        virtual void fun() const
        {
            cout<<"Drived::fun()"<<endl;
        }
};
#endif
