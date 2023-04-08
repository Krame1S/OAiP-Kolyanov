CC=gcc
CFILES=main.c output.c conversion.c
OBJECTS=main.o output.o conversion.o

BINARY=bin

all: $(BINARY)

$(BINARY): $(OBJECTS)
		$(CC) -o $@ $^

%.o:%c
		$(CC) -c -o $@ $^

clean:
		rm -rf $(BINARY) $(OBJECTS)