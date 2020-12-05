CC = gcc
FLAGS = -Wall
LD_FLAGS="-Wl,-R."
.PHONY: clean all

all:main

main:main.o myBank.o
	$(CC) $(FLAGS) -o $@ $^

main.o:main.c
	$(CC) $(FLAGS) -c $<

myBank.o:myBank.c myBank.h
	$(CC) $(FLAGS) -c $<
	
clean:
	rm *.o main