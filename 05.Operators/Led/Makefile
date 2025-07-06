#Target
TARGET := LED 

#Complier 
GCC    := gcc

#FLAGS
CFLAGS := -Wall 

#Includes
INC    := Inc
INCS   := -I$(INC)

#Source
SRC_DIR  := Src 
SRCS     := main.c Src/Led_Driver.c

#OBJS
OBJS     := $(SRCS:.c=.o)

#RULes 
$(TARGET) : $(OBJS)
	$(GCC) $(CFLAGS) $(INCS) -o $@ $^

#Build objects
%.o: %.c
	$(GCC) $(CFLAGS) $(INCS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
