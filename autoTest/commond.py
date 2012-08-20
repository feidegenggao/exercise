def exe_cmd(s):
    s.cmd('cd /root')
    s.cmd('rm hahaha -r')
    s.cmd('mkdir hahaha')
    #s.cmd('scp 192.168.13.89:/root/lxf ./')
    #use svn checkout http://.....
    s.cmd('ls -l')
    s.close()
