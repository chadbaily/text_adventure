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

    Room *stream = new Room("Stream",
                              "A quiet small stream in a field...", 100);
    Room *field = new Room("Field",
                             "A beautiful wheat field, where you can feel the wind blowing...", 300);
    Room *house = new Room("House",
                              "A small cabin in a field...", 200);
	Room *bedroom = new Room("Bedroom",
                              "A large room with lots of space...", 75);
    Room *kitchen = new Room("Kitchen",
                             "A small kitchen, with only a toaster...", 50);
    Room *hallway = new Room("Hallway",
                              "A long hallway with suspiciously loose boards ...", 50);
	Room *living_room = new Room("Living Room",
                              "A small living room...", 75);
    Room *cellar = new Room("Cellar",
                             "A stairway under the hallway...", 20);
    Room *patio = new Room("Patio",
                              "A nice cobblestone paito...", 100);
	Room *backyard = new Room("Backyard",
                              "An expansive, but fenced in backyard...", 200);
    Room *swingset = new Room("Swingset",
                             "A swing set for children to play on...", 50);
    Room *pool = new Room("Pool",
                              "A deep pool...", 50);
	Room *sky = new Room("Sky",
                              "Well how did you get here?!...", 500);
							  
							  

    stream->link(field, "north");
	
    field->link(stream, "south");
    field->link(house, "north");
	
    house->link(bedroom, "west");
	house->link(kitchen, "east");
	house->link(hallway, "north");
	house->link(field, "south");
	
	bedroom->link(house, "east");
	
	kitchen->link(house, "west");
	
	hallway->link(patio, "north");
	hallway->link(cellar, "east");
	hallway->link(house, "south");
	hallway->link(living_room, "west");
	
	living_room->link(hallway, "east");
	
	cellar->link(hallway, "west");
	
	patio->link(backyard, "north");
	patio->link(hallway, "south");
	
	backyard->link(pool, "north");
	backyard->link(swingset, "west");
	
	swingset->link(backyard, "east");
	
	pool->link(backyard, "south");
	
	field -> link(sky, "up");
	

    Player *josh = new Player("Josh", "A prince", 50);
    Player *tracy = new Player("Tracy", "A princess", 40);
    josh->moveTo(field);
    tracy->moveTo(field);
    game.addAgent(josh);
    game.addAgent(tracy);

    Monster *napolean = new Monster("Napolean");
    Monster *kafka = new Monster("Kafka");
    napolean->moveTo(hallway);
    kafka->moveTo(backyard);
    game.addAgent(napolean);
    game.addAgent(kafka);

    Thing *liberty = new Thing("Statue of Liberty",
                               "A miniature Statue of Liberty", 5);
    Thing *hoop = new Thing("Hoop", "A basketball hoop", 30);
	
	Thing *shovel = new Thing("Shovel", "A shovel...", 10);
	Thing *book = new Thing("Book", "A book...", 10);
	Thing *towel = new Thing("Towel", "A towel...", 10);
	Thing *kid = new Thing("Kid", "A kid... wait what?", 10);
	Thing *rubber_duck = new Thing("Rubber Duck", "A rubber duckie...", 10);
	
	
    liberty->moveTo(bedroom);
    hoop->moveTo(patio);
	
	shovel->moveTo(field);
	
	book->moveTo(backyard);
	towel->moveTo(bedroom);
	kid->moveTo(swingset);
	rubber_duck->moveTo(pool);

    cout << "Welcome!" << endl;

    while(game.step());

    return 0;
}

