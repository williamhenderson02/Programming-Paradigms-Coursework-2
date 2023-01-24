CC = gcc
CFLAGS = -Wall
LDFLAGS = -lncurses
OBJFILES = main.o langton.o visualiser.o
TARGET = ant
DEPS = langton.h visualiser.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LDFLAGS)

$(TARGET): $(OBJFILES)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~