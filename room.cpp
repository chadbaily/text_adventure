#include<iostream>
#include<string>
#include "thing.h"
#include "room.h"
using namespace std;

Room::Room(string _name, string _desc, int _size){
    name = _name;
    desc = _desc;
    size = _size;
}

string Room::getName(){
    return name;
}

string Room::getDesc(){
    return desc;
}

void Room::link(Room* _room, string _exit){
    exits[_exit] = _room;
}

vector<string> Room::getExits(){
//return an ititarator that goes through the exits map
   vector<string> v;
   for(map<string, Room*>::iterator it = exits.begin(); it != exits.end(); ++it)
   {
        v.push_back(it->first);
   }
    return v;
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
    for(map<string, Room*>::iterator it = exits.begin(); it!= exits.end(); ++it)
    {
        cout << "Your exits are: " <<it->first << " " <<  endl;
    }
}

void Room::printThings(Thing* ignore){
    //Itterate through the set, if it == ignore, then dont print, otherwise
    //print it
   for(set<Thing*>::iterator it = things.begin(); it!= things.end(); ++it)
    {
        cout << "The Things in the room are: " << *it  << " " <<  endl;
    }
}
