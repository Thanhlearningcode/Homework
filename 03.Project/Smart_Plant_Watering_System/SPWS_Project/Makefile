# TARGET
TARGET := SPWS

#COMPLIER 
CC     := gcc

#BUILD_DIR 
BUILD_DIR = build
#FLAGS
CFLAGS := -Wall -IInc

#SOURCES
SRC    := Src
SRCS   := main.c \
		  $(wildcard $(SRC)/*.c)

#OBJS
OBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))

#LINKER
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

#RULE
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean