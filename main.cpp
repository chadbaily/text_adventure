#include <iostream>
#include "room.h"
#include "thing.h"
#include "player.h"
#include "monster.h"
#include "game.h"
using namespace std;

int main()
{

    Game game;

    Room *entrance = new Room("Entrance",
                                  "A wide open entrance...", 100);
    Room *hallway = new Room("Hallway",
                                   "A long hallway...", 50);
    Room *ballroom = new Room("Ballroom",                                                                                       "A huge ballroom...", 200);
    entrance->link(hallway, "north");
    hallway->link(entrance, "south");
    hallway->link(ballroom, "east");
    ballroom->link(hallway, "west");
    
    Player* josh = new Player("Josh", "My Brother", 50);

    Player* ryan = new Player("Ryan", "Joshes Brother", 40);
    
    Monster* jack = new Monster("jack");

    josh->moveTo(entrance);
    ryan->moveTo(entrance);
    jack->moveTo(entrance);
    
    game.addAgent(josh);
    game.addAgent(ryan);
    game.addAgent(jack);


    while(game.step());

    delete entrance;

return 0;
}

