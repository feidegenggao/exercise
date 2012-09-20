#!/usr/bin/sh
while read -r line
do
    echo $line
    #调用autologin脚本，执行相应的命令。
    ./autologin.exp $line
done < $1
