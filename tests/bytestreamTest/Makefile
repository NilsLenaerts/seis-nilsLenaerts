.DEFAULT_GOAL := all

CC=g++

clean:
	rm main.out

compile:
	$(CC) -g main.cpp ../../src/bytestream.cpp -o main.out

execute:
	/bin/python3 hex_number_generator.py
	./main.out

all: clean compile execute