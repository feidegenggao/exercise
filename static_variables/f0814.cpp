//=====================================
// f0814.cpp
// static member function
//=====================================
#include<iostream>
using namespace std;
//-------------------------------------
class Student{
  static int number;
  string name;
public:
  void set(string str){
    name = str;
    ++number;
  }
  static void printNumber(){ cout<<number<<" total numbers\n"; }
  void print(){ cout<<name<<" -> students are "<<number<<" numbers\n"; }
};//-----------------------------------
int Student::number = 0;  //静态数据成员在类外分配空间和初始化
//-------------------------------------
void fn(){
  Student s1;
  s1.set("Jenny");
  Student s2;
  s2.set("Randy");
  s1.printNumber();
}//------------------------------------
int main(){
  Student s;
  s.set("Smith");
  fn();
  Student::printNumber();
  //cout<<"number:"<<Student::number<<endl;
}//====================================

 
