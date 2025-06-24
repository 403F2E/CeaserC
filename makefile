
CC = gcc
CFLAGS = -Wall -g -I./headers

SRC_DIR = ./src

BUILD_DIR = ./build

SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*c)

TEST_FILE = ./app.rzc

EXEC = czr

RUN = run

all: $(RUN)

$(RUN): $(SRCS)
	@$(CC) $(SRCS) $(CFLAGS) -o $(BUILD_DIR)/$(EXEC)
	$(BUILD_DIR)/$(EXEC) $(TEST_FILE)

clean: $(BUILD_DIR)/$(EXEC)
	@clear
	@rm $(BUILD_DIR)/$(EXEC)
