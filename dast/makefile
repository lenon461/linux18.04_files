CC = gcc
OBJS = dast.o stack.h node.h
TARGET = ads.out
 
all: $(TARGET)
 
clean:
    rm -f *.o
    rm -f $(TARGET)
 
$(TARGET): $(OBJS)
	$(CC) -o $@ $^
