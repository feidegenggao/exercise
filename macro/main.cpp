#include    "../my.h"
#include    <stdio.h>

#define     DEBUG
#define     TEST(EXP) #EXP
//TEST(hello) -->> "hello"
//add " before and behind EXP
#define     TOKEN(A, B) L##A##B
//TOKEN (a, b) -->> Lab
//connect L and a and b
#define     myprintf(fmt,...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define     mynoprintf(fmt,...) fprintf(stderr, fmt, __VA_ARGS__)
//This myprintf can't output :myprintf("Hello"); correctly
//You should add ## before __VA_ARGS__
#define     argprintf(fmt,arg...) fprintf(stderr, fmt, ##arg)
int main()
{
    #ifdef  DEBUG
    cout<<"define DEBUG"<<endl;
    #endif

    printf("words:%s\n", TEST(hello));
    //cout<<TOKEN(a,b)<<endl;
    myprintf("log:%d\n", 1);
    myprintf("log:hi\n");
    mynoprintf("log:hi\n");
    argprintf("log:%d\n", 1);
    argprintf("log:hi\n");
}
