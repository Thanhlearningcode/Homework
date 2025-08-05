TARGET = system_monitor

# Compiler
CC = gcc

# CFLAGS
CFLAGS = -Wall -IInc -IInc/MVP -IInc/System -IInc/Logger

# Source files
SRCS = main.c \
       Src/MVP/Controller.c \
       Src/MVP/Model.c \
       Src/MVP/View.c  \
	   Src/Logger/Logger.c

# Object files
OBJS = $(SRCS:.c=.o)

# Rule build 
all: $(TARGET)

# Linker
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Complỉe
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule  AddressSanitizer
debug: CFLAGS += -g -fsanitize=address -fno-omit-frame-pointer
debug: LDFLAGS = -fsanitize=address
debug: clean
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

# Clean
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets 
.PHONY: all clean debug
