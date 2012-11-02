#include    "../my.h"

int main()
{
     const char* url = "p2p://192.168.1.85:1006/0000000010000000000000000000000000000000";
     cout<<"strlen(url):"<<strlen(url)<<endl;
     const char* a = "abc d\r\n";
     cout<<"strlen(abc d\r\n)"<<strlen(a)<<endl;
}
