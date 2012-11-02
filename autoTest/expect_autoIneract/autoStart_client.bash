#!/bin/sh
#host_addr变量是指存放主机地址的文件。
hosts="host_addr"
while read -r line
do
    echo $line
    #调用autologin脚本，执行相应的命令。
    ./start_client.exp $line
done < $hosts
