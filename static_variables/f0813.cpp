//=====================================
// f0813.cpp
// static data member
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
  void print(){ cout<<name<<" -> students are "<<number<<" numbers\n"; }
};//-----------------------------------
int Student::number = 0;  //静态数据成员在类外分配空间和初始化
//-------------------------------------
void fn(){
  Student s1;
  s1.set("Jenny");
  Student s2;
  s2.set("Randy");
  s1.print();
}//------------------------------------
int main(){
  Student s;
  s.set("Smith");
  fn();
  s.print();
  //cout<<"totoalnumber:"<<Student::number<<endl;
}//====================================

 
