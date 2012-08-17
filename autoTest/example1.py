#-*- coding: UTF-8 -*-
#!/usr/bin/python 
import sys
from session import *

s = session('192.168.9.64','root','uestc8020')
s.cmd('cd /root')
s.cmd('mkdir hahaha')
s.cmd('ls -l')
s.close()
