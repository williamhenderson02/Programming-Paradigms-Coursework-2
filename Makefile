CC = gcc
CFLAGS = -Wall
LDFLAGS = -lncurses
OBJFILES = langton.o visualiser.o
TARGET = ant

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) main.c $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~