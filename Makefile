CC=gcc
CFLAGS=-Wall -Wextra -Werror -g -O0
SOURCE_FILE=scalc.c
OUT_FILE=scalc

all:
	$(CC) $(SOURCE_FILE) -o $(OUT_FILE) $(CFLAGS)
