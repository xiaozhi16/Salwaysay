#!/bin/bash
.a:.o
	ar -rcs libtool.a utils.o
	mv  libtool.a ../lib/libtool.a
	rm *.o

tool.a:utils.o
	ar -rcs libtool.a utils.o
	mv  libtool.a ../lib/libtool.a
	rm *.o
utils.o:utils.c log.c   
	@gcc -c utils.c  -L../lib/ -lunp -I/usr/include/mysql -L/usr/lib/lcrypto -ldl-gnu -lmysqlclient -lpthread -lz -lm -lrt -latomic -lssl -l