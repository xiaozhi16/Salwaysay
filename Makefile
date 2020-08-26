#!/bin/bash
HOME=/root/alwaysay
LIBDIR=${HOME}/lib/
install:
	@echo ==========开始编译安装============
	gcc server.c -o server -L ${LIBDIR} -ltool -lunp
	mv server ${HOME}/build/debug/server
	@echo ==========结束编译安装============
clean:
	rm -i ${HOME}/build/debug/server
compiler:

client: client.c
	@echo =========开始编译客户端=============
	gcc client.c -o client -L${LIBDIR} -ltool -lunp
	mv client ${HOME}/build/debug/client
	@echo =========结束编译客户端=============
	
