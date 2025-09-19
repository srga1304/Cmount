CC = clang
CFLAGS = -Wall -g
TARGET = myprogram

all: $(TARGET)

myprogram: main.o 
	$(CC) $(CFLAGS) -o $(TARGET) main.o

main.o: main.c 
	$(CC) $(CFLAGS) -c main.c


clean:
	rm -f *.o $(TARGET)

run: $(TARGET)
	./$(TARGET)
