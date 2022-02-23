# Makefile
# Lucas Eifert
# COSC 3750 Spring 22
# Homework 4
# Modified 2/19/21
#
# Makefile to compile wycat.c program
CC=cc
CFLAGS=-Wall -g
RM=/bin/rm -f

.PHONY: clean

wycat: wycat.c 
	${CC} ${CFLAGS} wycat.c -o wycat

clean: 
	${RM} wycat
