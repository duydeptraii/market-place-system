#How to run Makefile:
#1."make" -> "make run" -> "make clean" (in terminal)

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Iinclude

# Output program name
TARGET = marketplace

# Source files
SRC = src/main.c src/logic.c src/file.c

# Default rule
all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Run program
run:
	./$(TARGET)

# Clean compiled file
clean:
	rm -f $(TARGET)