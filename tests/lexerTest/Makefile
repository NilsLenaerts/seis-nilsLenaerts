.DEFAULT_GOAL := all

CC=g++

compile:
	$(CC) -g main.cpp ../../src/bytestream.cpp ../../src/lexer.cpp -o main.out

execute:
	./main.out

all: compile execute