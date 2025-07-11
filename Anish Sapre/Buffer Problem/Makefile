# Makefile for Buffer Problem

CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = test_with_file_ops
SRC = test_with_file_ops.c
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) output.txt

.PHONY: all clean
