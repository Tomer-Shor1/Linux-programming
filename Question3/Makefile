# chatGPT helped only with making this makefile looking good!
# The we made the linking alone!


CC = gcc
CFLAGS = -Wall -fPIC -lm
LDFLAGS = -shared

# Library and application names
LIB_NAME = liblibrary.so
APP_NAME = main

# Source files
LIB_SRC = library.c
APP_SRC = main.c

# Object files
LIB_OBJ = $(LIB_SRC:.c=.o)
APP_OBJ = $(APP_SRC:.c=.o)

all: $(LIB_NAME) $(APP_NAME)
	export LD_LIBRARY_PATH=.


$(LIB_NAME): $(LIB_OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

$(APP_NAME): $(APP_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L. -llibrary

clean:
	rm -f $(LIB_OBJ) $(APP_OBJ) $(LIB_NAME) $(APP_NAME) *.so

# Phony targets
.PHONY: all clean
