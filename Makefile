all: textadventure

textadventure: main.cpp agent.cpp thing.cpp room.cpp player.cpp monster.cpp game.cpp
	g++ -Wall -g  -std=c++11 -o textadventure main.cpp container.cpp agent.cpp thing.cpp room.cpp player.cpp monster.cpp game.cpp

clean:
	rm -rf textadventure
