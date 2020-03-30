#!/bin/bash

tool.a:utils.o
	ar -rcs libtool.a utils.o
	mv  libtool.a ../lib/libtool.a
	rm *.o
utils.o:utils.c 
	gcc -c utils.c -lunp
