CC = gcc
CFLAGS = -Wall
LDFLAGS = -lncurses
OBJFILES =langton.o visualiser.o main.o
TARGET = ant
#DEPS = langton.h visualiser.h

#%.o: %.c $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS) $(LDFLAGS)

#$(TARGET): $(OBJFILES)
#	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

libant.so: $(OBJFILES)
	$(CC) -shared -o libant.so $(OBJFILES) $(LDFLAGS)


clean:
	rm -f $(OBJFILES) $(TARGET) *~