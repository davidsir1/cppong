GCC=g++
OPTION=-lsfml-graphics -lsfml-window -lsfml-system
COMPILE=$(GCC)

all: pong

pong: main.cpp player.o
	$(GCC) main.cpp player.o -o pong $(OPTION)

player.o: player.cpp player.h
	$(GCC) -c player.cpp -o player.o
