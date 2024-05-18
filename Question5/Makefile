# Compiler
CC = gcc

# Compiler flags, -pg flag used for profiling.
CFLAGS = -Wall -pg

# Target executable
TARGET = max_subarray_sum

# Source files
SRCS = max_subarray_sum.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean build files
clean:
	rm -f $(TARGET) $(OBJS) gmon.out analysis.txt

# Rule to run the program with different input sizes

run: all
	@SEED=$$(od -vAn -N4 -tu4 < /dev/urandom); \
	echo "Running with seed $$SEED and size 100"; \
	./$(TARGET) $$SEED 100; \
	SEED=$$(od -vAn -N4 -tu4 < /dev/urandom); \
	echo "Running with seed $$SEED and size 1000"; \
	./$(TARGET) $$SEED 1000; \
	SEED=$$(od -vAn -N4 -tu4 < /dev/urandom); \
	echo "Running with seed $$SEED and size 10000"; \
	./$(TARGET) $$SEED 10000;
	gprof max_subarray_sum gmon.out -> analysis.txt



