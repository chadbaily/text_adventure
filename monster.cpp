#include <string>
#include <iostream>
#include "thing.h"
#include "room.h"
#include <stdlib.h>
using namespace std;

Monster::Monster(string _name)
    : Agent(_name, " ", 0)
{}

bool Monster::act(){
    vector<string> exits = cur_room->getExits();
  int randNum = rand() % exits.size();
    
    this->moveTo(cur_room->getRoom(exits[randNum]));
    return true;
}
