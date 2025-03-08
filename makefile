GCC=g++
FLAGS=-g -c
OPTION=-lsfml-graphics -lsfml-window -lsfml-system
COMPILE=$(GCC)
OBJ=obj/player.o obj/ball.o obj/gamescore.o

all: pong

pong: main.cpp $(OBJ)
	$(GCC) main.cpp $(OBJ) -g -o pong $(OPTION)

obj/player.o: player.cpp player.h
	$(GCC) $(FLAGS) player.cpp -o obj/player.o

obj/ball.o: ball.cpp ball.h
	$(GCC) $(FLAGS) ball.cpp -o obj/ball.o

obj/gamescore.o: gamescore.cpp gamescore.h
	$(GCC) $(FLAGS) gamescore.cpp -o obj/gamescore.o

clean:
	rm -rf *.o
