#!/bin/sh
#host_addr变量是指存放主机地址的文件。
hosts="host_addr"
while read -r line
do
    echo $line
    #调用autologin脚本，执行相应的命令。
    ./make_p2plive.exp $line
done < $hosts
