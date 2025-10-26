CC=gcc
CFLAGS=-Wall -Wextra -Werror -g -O0
SOURCE_FILE=scalc.c
OUT_FILE=scalc

all:
	$(CC) ./src/$(SOURCE_FILE) -o ./build-debug/$(OUT_FILE) $(CFLAGS)
