#include <iostream>
#include "room.h"
#include "thing.h"
#include "player.h"
using namespace std;

int main()
{
    Room *entrance = new Room("Entrance",
                                  "A wide open entrance...", 100);
    Room *hallway = new Room("Hallway",
                                   "A long hallway...", 50);
    Room *ballroom = new Room("Ballroom",                                                                                       "A huge ballroom...", 200);
    entrance->link(hallway, "south");
    hallway->link(entrance, "north");
    hallway->link(ballroom, "east");
    ballroom->link(hallway, "west");
    
    Player* josh = new Player("Josh", "My Brother", 50);

    Player* ryan = new Player("Ryan", "Joshes Brother", 40);

    josh->moveTo(entrance);
    ryan->moveTo(entrance);

    hallway->printExits();
    
    

    delete entrance;

return 0;
}

