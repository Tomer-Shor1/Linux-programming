CC = gcc
CFLAGS = -Wall -g

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
EXECS = $(SRCS:.c=)


all: $(EXECS)

$(EXECS): $(OBJS)
	$(CC) $(CFLAGS) $@.o -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXECS)

run: all
	-./dividedByZero
	-./StackOverflow
	-./WritingToUndeclaredAddr

