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

void Room::printExits(string ignore){
    //itterate through the exits and print them
    for(map<string, Room*>::iterator it = exits.begin(); it!= exits.end(); ++it)
    {
        if(it->first == "up")
        {
        }
        if(it->second->getName() == ignore)
        {
        }
        else
        cout << "Your exits are: " <<it->first << " " <<  endl;
    }
}

Room* Room::getRoom(string _exit){
    return exits.find(_exit)->second;
}
