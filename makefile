
CC = gcc
CFLAGS = -Wall -g -I./headers

SRC_DIR = ./src

SRCS = $(wildcard $(SRC_DIR)/*.c)

TEST_FILE = app.calc

EXEC = compy

all: $(EXEC)

$(EXEC): $(SRCS)
	$(CC) $(SRCS) $(CFLAGS) -o $(EXEC)
	.\$(EXEC) .\$(TEST_FILE)

clean:
	rm .\$(EXEC)
