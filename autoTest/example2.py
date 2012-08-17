#-*- coding: UTF-8 -*-
#!/usr/bin/python 
import re,sys,pxssh,pexpect,time,xml.dom.minidom
from session import *

session = session('192.168.9.64','root','uestc8020')
session.cmd('cd /usr')
session.cmd('ls -l','include')
session.cmd('mv non_exist_file new_name','','No such file')
session.close()
