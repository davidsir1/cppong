GCC=g++
OPTION=-lsfml-graphics -lsfml-window -lsfml-system
COMPILE=$(GCC)

all: pong

pong: main.cpp player.o ball.o
	$(GCC) main.cpp player.o ball.o -g -o pong $(OPTION)

player.o: player.cpp player.h
	$(GCC) -c player.cpp -g -o player.o

ball.o: ball.cpp ball.h
	$(GCC) -c ball.cpp -g -o ball.o
