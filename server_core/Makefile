#!/bin/bash

cc=gcc
mysqllibs=-L/usr/lib/x86_64-linux-gnu -lmysqlclient -lpthread -lz -lm -lrt -latomic -lssl -lcrypto -ldl
mylib=-L../lib/ -lunp

#隐晦规则
.SUFFIXES: .c
.c.o:
	$(cc) -c $< ${mylibs} ${mysqllibs}

tool.a : log.o tool.o

%.a:%.o
	ar -rcs libtool.a *.o
	mv  libtool.a ../lib/libtool.a
	rm *.o