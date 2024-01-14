CC=g++
CFLAGS=-g -O2 -std=gnu++17 -static -Wl,--whole-archive -lpthread -Wl,--no-whole-archive
LDFLAGS=-lrt

# Define object files
OBJFILES=exercise.o

.PHONY: all clean

all: exercise.exe

exercise.exe: $(OBJFILES)
    $(CC) $(CFLAGS) $(LDFLAGS) -o exercise.exe $(OBJFILES)

clean:
    rm -rf *.o *.exe
