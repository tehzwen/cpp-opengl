CC=g++
CFLAGS=-Wall -g -Wno-unused-variable -pthread
LDFLAGS=-lglfw -framework OpenGL

all: engine

engine: src/*.cpp src/geometry/*.cpp
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

debug:
	$(shell lldb --file ./engine)

clean:
	$(RM) engine
	$(RM) *.o
