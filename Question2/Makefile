CC = gcc
FLAGS = -lm

.PHONY: all clean

all: Poisson

Poisson: Poisson.o
	$(CC) $(FLAGS) -o Poisson Poisson.o

Poisson.o: Poisson.c
	$(CC) $(FLAGS) -c Poisson.c

clean: 
	rm -f Poisson *.o 

run: all
	./Poisson 2 6