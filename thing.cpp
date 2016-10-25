#include<iostream>
#include<string>
#include "room.h"
#include "thing.h"
using namespace std;

Thing::Thing(string _name, string _desc, int _size){
    name = _name;
    desc = _desc;
    size = _size;
    cur_room = NULL;
}

bool Thing::moveTo(Room* room){
    cur_room = room;
    return true;
}

string Thing::getName(){
    return name;
}

string Thing::getDesc(){
    return desc;
}

int Thing::getSize(){
    return size;
}
