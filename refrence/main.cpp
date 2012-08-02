#include    "../my.h"

int main(void)
{
    int a = 2;
    int &b = a;
    cout<<"a:"<<a<<"\tb:"<<b<<endl;

    b = 3;
    cout<<"a:"<<a<<"\tb:"<<b<<endl;

    int c = 4;
    b = c;
    cout<<"a:"<<a<<"\tb:"<<b<<"\tc:"<<c<<endl;

    c = 5;
    cout<<"a:"<<a<<"\tb:"<<b<<"\tc:"<<c<<endl;

    return 0;

}
