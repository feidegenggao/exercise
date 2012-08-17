#-*- coding: UTF-8 -*-
#!/usr/bin/python 
import re,sys,pxssh,pexpect,time,xml.dom.minidom
from session import *

session = session('192.168.1.13','root','uestc8020')
session.cmd('mysql -puestc8020','','','mysql>')
session.cmd('use mysql','Database changed','Unknown database','mysql>')
session.cmd('select host,user from user;','sec','ERROR','mysql>')
session.cmd('exit','','','')
session.close()




