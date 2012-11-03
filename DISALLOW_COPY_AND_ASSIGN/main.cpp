/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  DISALLOW_COPY_AND_ASSIGN
 *    从Google C++ Style 看到的用法。
 *    这个宏方便一些禁止拷贝，赋值构造的类。用法，来，看个例子。
 *
 *        Version:  1.0
 *        Created:  11/02/2012 05:28:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#define DISALLOW_COPY_AND_ASSIGN(TypeName)\
    TypeName(const TypeName&);\
void operator = (const TypeName&)

class widget{
    public:
        widget(){}
        ~widget(){}

    private:
        DISALLOW_COPY_AND_ASSIGN(widget);
};
//好了，这样的话，widget就无法执行拷贝构造和赋值构造函数了。
//这个宏，仅仅是个TIPs而已，最好是继承noncopyable类。
