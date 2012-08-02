#include 	<iostream>
using namespace std;
using std::cout;
using std::endl;
using std::cerr;
using std::cin;

void printhello()
{
	int a;
	a = 3;
	int b;
	b = 2;
	if (a == b)
	{
		cout<<"a=b"<<endl;
	}
	cout<<"Hello world!"<<endl;
}

int
main(void)
{
	printhello();
	return 0;
}
