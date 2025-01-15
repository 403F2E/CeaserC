
CC = gcc
CFLAGS = -Wall -g -I./headers

SRC_DIR = ./src

SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*c)

TEST_FILE = app.calc

EXEC = compy

RUN = run

all: $(RUN)

$(RUN): $(SRCS)
	@$(CC) $(SRCS) $(CFLAGS) -o $(EXEC)
	@.\$(EXEC) .\$(TEST_FILE)

clean: $(EXEC)
	@clear
	@rm .\$(EXEC)
