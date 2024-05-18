# Makefile for phone book programs

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -pedantic

# Executable names
ADD_EXEC = add2PB
FIND_EXEC = findPhone

# Source files
ADD_SRC = add2PB.c
FIND_SRC = findPhone.c

# Build targets
all: $(ADD_EXEC) $(FIND_EXEC)

$(ADD_EXEC): $(ADD_SRC)
	$(CC) $(CFLAGS) -o $(ADD_EXEC) $(ADD_SRC)

$(FIND_EXEC): $(FIND_SRC)
	$(CC) $(CFLAGS) -o $(FIND_EXEC) $(FIND_SRC)

# Clean up build files
clean:
	rm -f $(ADD_EXEC) $(FIND_EXEC)

.PHONY: all clean
