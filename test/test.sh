#!/bin/bash
HOME="/root/alwaysay"
read -p "请输入要测试的文件：" file
read -p "请输入要测试的文件：" file2
read -p "请输入test文件：" testone
TESTFILE=${HOME}/${file}

gcc ${HOME}/${file} ${HOME}/${file2} ${testone} -o test -L../lib/ -ltool -lcjson -lunp  -L/usr/lib/x86_64-linux-gnu -lmysqlclient -lpthread -lz -lm -lrt -latomic -lssl -lcrypto -ldl