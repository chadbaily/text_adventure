#include<iostream>
#include<string>
#include "room.h"
#include "thing.h"
#define NULL 0
using namespace std;

Thing::Thing(sting _name, string _desc, int _size){
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
