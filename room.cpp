#include<iostream>
#include<string>
#include "thing.h"
#define NULL 0
using namespace std;

Room::Room(string _name, string _desc, int size){
    name = _name;
    desc = _desc;
    size = _size;
    things = NULL;
    exits = NULL;
}

string Room::getName(){
    return name;
}

string Room::getDesc(){
    return desc;
}

void Room::link(Room* _room, string _exit){
    

}

vector<string> Room::getExits(){
    //return an ititarator that goes through the exits map

}

bool Room::add(Thing* thing){
    things.insert(thing);
    return true;
}

void Room::remove(Thing* thing){
    things.erase(thing);
}

void Room::printExits(){
    //itterate through the exits and print them
}

void Room::printThings(Thing* ignore){
    //Itterate through the set, if it == ignore, then dont print, otherwise
    //print it
}
