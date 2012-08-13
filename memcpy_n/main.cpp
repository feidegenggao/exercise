#include    "../my.h"

int
main()
{
    char *a = new char[10];
    cout<<"sizeof(a):"<<sizeof(a)<<endl;
    cout<<"strlen(a):"<<strlen(a)<<endl;
    bzero(a, 10); 
    const char *b = "abc";

    memcpy(a, b, 5);
    cout<<"a:"<<a<<endl;
    cout<<"strlen(a):"<<strlen(a)<<endl;
    return 0;
}
