CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -O2 -fopenmp
LDFLAGS=-fopenmp
LIBS_MATH=-lm

BIN=lab01_hello lab02_private1 lab03_private2 lab04_threads sum_sin

all: $(BIN)

lab01_hello: lab01_hello.c
	$(CC) $(CFLAGS) $< -o $@

lab02_private1: lab02_private1.c
	$(CC) $(CFLAGS) $< -o $@

lab03_private2: lab03_private2.c
	$(CC) $(CFLAGS) $< -o $@

lab04_threads: lab04_threads.c
	$(CC) $(CFLAGS) $< -o $@

sum_sin: sum_sin.c
	$(CC) $(CFLAGS) $< -o $@ $(LIBS_MATH)

clean:
	rm -f $(BIN)

.PHONY: all clean
