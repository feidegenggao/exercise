# -*- coding: utf-8 -*-  
import sys
from session import *
from commond import *
import xml.etree.ElementTree as et  
 
#读取xml文件，  
def load_xml_file(fileName):  
    root = et.parse(fileName).getroot()  
  
   #获取所有list节点  
    clients = root.findall('client')  
    #遍历list节点的子元素  
    for client in clients:  
        addr = client.find('addr').text
        passwd = client.find('passwd').text
        username = client.find('usr').text
        print addr,username,passwd
        #session是谢鹏师兄写的一个脚本，用于测试。
        s = session(addr, username, passwd)
        #执行命令，这是另外一个脚本，用于保存要执行的命令。
        exe_cmd(s)

if __name__ == '__main__':  
    #host.xml文件中存放的要测试的主机的地址用户名密码
    load_xml_file('host.xml')  
