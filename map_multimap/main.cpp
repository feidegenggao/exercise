/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  map的用法
 *
 *        Version:  1.0
 *        Created:  2012年09月26日 15时58分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include <iostream>
#include <map>
#include <strings.h>
#include <string.h>
using namespace std;

map<char,int> mymap;

void erase_ele()
{
  map<char,int>::iterator it;
  for (it = mymap.begin(); it != mymap.end(); it++)
  {
      if (it->second == 200)
          mymap.erase(it);
  }
}

int main ()
{
  //map<char,int> mymap;
  map<char,int>::iterator it;

  mymap['a']=50;
  mymap['b']=100;
  mymap['c']=150;
  mymap['d']=200;


  for (it = mymap.begin(); it != mymap.end(); it++)
  {
      cout<<"it->first:"<<it->first<<endl;
      if (it->second == 200)
          erase_ele();
  }

  it=mymap.find('b');
  mymap.erase (it);
  mymap.erase (mymap.find('d'));

  // print content:
  cout << "elements in mymap:" << endl;
  cout << "a => " << mymap.find('a')->second << endl;
  cout << "c => " << mymap.find('c')->second << endl;
  it=mymap.find('d');
  if (it == mymap.end())
  {
      cout<<"mymap doesn't exit d"<<endl;
  }

  return 0;
  /*
  map<string, int> blacklist;
  map<string, int>::iterator itlist;
  blacklist["192.168.1.12"] = 100;
  char* ipaddr = new char[20];
  bzero(ipaddr, 20);
  memcpy(ipaddr, "192.168.1.12", 12);
  //下面三行代码有什么不一样呢？
  //string构造函数有两个，                                                               
  //string(char*);构造char*指向的内存区域，以\0为结束符                                  
  //string(char*, n);构造char*指向的区域，大小是n                                        
  //如果你提前把char*指向的区域有\0结尾，那么，就不要用                                  
  //第二个构造函数（这纯属画蛇添足)     
  string ipstring(ipaddr, 20);
  //下面这两个是一样的。
  string ipstring(ipaddr, 12);
  string ipstring(ipaddr);

  itlist = blacklist.find(ipstring);
  if (itlist == blacklist.end())
  {
      cout<<"blacklist doesn't exit 192.168.1.13"<<endl;
  }
  else
  {
      cout<<"blacklist exit 192.168.1.13"<<endl;
  }
  return 0;
  */
}
