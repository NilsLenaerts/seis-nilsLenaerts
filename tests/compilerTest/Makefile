.DEFAULT_GOAL := all

CC=g++

compile:
	$(CC) -g main.cpp ../../src/lexer.cpp ../../src/bytestream.cpp  -o main.out

execute:
	./main.out

all: compile execute