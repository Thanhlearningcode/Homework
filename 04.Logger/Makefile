CC      := gcc
CFLAGS  := -Wall -Wextra -std=c11
TARGET  := logger.out
SRC     := main.c Logger.c
OBJS    := $(SRC:.c=.o)
LOG_DIR := Log
LOG_FILE := $(LOG_DIR)/log.txt

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	@mkdir -p $(LOG_DIR)
	@./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
	rm -rf $(LOG_DIR)
