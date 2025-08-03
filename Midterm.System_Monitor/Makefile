# Tên file thực thi
TARGET = system_monitor

# Compiler
CC = gcc

# CFLAGS: cảnh báo và bao gồm thư mục header
CFLAGS = -Wall -IInc -IInc/MVP -IInc/System 

# Source files
SRCS = main.c \
       Src/MVP/Controller.c \
       Src/MVP/Model.c \
       Src/MVP/View.c \

# Object files
OBJS = $(SRCS:.c=.o)

# Rule build mặc định
all: $(TARGET)

# Liên kết thành file thực thi
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Biên dịch từng file .c thành .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Dọn file biên dịch
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets để tránh trùng tên file
.PHONY: all clean
