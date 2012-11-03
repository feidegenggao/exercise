/*
 * ============================================================================
 *
 *       Filename:  03_const_pointer.cc
 *
 *    Description:  The 3rd items is :
 *    Use const whenever possible
 *
 *        Version:  1.0
 *        Created:  10/20/12 23:10:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include "../my.h"

int init_temp()
{
    return 100;
}
class widget{
    public:
        widget() {}
        ~widget() {}
        void const_fun() const{
            temp = 2;
        }

        void print_temp() const{
            cout<<"const print_temp, temp:"<<temp<<endl;
        }

        //这个函数是重载了上面的函数，const对象默认会调用上面的函数,
        //如果没有上面的函数，编译会通不过
        //非const对象会默认调用下面这个函数，如果没有下面这个函数，会调用上面的函数。
        //
        //
        //const对象必须调用const成员函数，
        //非const对象就不一定了。
        //不过，二者默认都是调用自己对应的成员函数。
        void print_temp() {
            cout<<"non-const print_temp(), temp:"<<temp<<endl;
        }

    private:
        static int init_temp() {
            return 1;
        }

        //静态数据成员，是不能在类的构造函数中初始化的。和定义的。
        //因为，静态成员如果在构造函数初始化的话，
        //每次构建新的对象，都会改变这个变量的值的。
        static int temp;
};
int widget::temp = ::init_temp();
//int a = widget::init_temp();

int main()
{
    char* greeting = new char[20];
    bzero(greeting, 20);
    memcpy(greeting, "Hello, World!", strlen("Hello, World!"));

    char* greeted = new char[20];
    bzero(greeted, 20);
    memcpy(greeted, "NDSL@UESTC", strlen("NDSL@UESTC"));

    char* const p2 = greeting;
    cout<<"char* const p2:"<<p2<<endl;

    //p2 = greeted;
    cout<<"char* const p2:"<<p2<<endl;

    const char* p3 = greeting;
    cout<<"const char* p3:"<<p3<<endl;
    bzero(greeting, strlen(greeting));
    memcpy(greeting, "NDSL@UESTC", strlen("NDSL@UESTC"));
    cout<<"const char* p3:"<<p3<<endl;

    //p3 和 greeting指向同一块内存。
    //p3是const char *类型。是不能修改p3指向的内容的。
    //但是greeting指向的内存是可以修改的。因为greeeting不是const char *
    //问题是，这样的话，p3的存在还有什么意义呢？
    //bzero(p3, strlen(p3));



    //下面讨论下，const对象，const成员函数的问题。
    //const成员函数不可以更改成员变量。前提是这些成员变量不是静态成员变量
    //const成员函数是可以修改静态成员变量的，因为静态成员变量不是任何对象的
    //组成部分。

    const widget w1;
    w1.print_temp();
    w1.const_fun();
    w1.print_temp();

 


    return 0;
}
