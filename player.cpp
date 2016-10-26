#include <iostream>
#include <string>
#include "player.h"
#include "agent.h"
#include <sstream>
#include <algorithm>
#include <cctype>
#include <iterator>
#include "room.h"

using namespace std;

Player::Player(string _name, string _desc, int _size)
   :Agent(_name, _desc, _size), Container()
 {}

bool Player::act(){
    string command;
	Room *cur_room = (Room*)cur_container;
    cout << "What would you like to do "<< this->getName() << " ?"  << endl;
    getline(cin, command);
    transform(command.begin(), command.end(), command.begin(), ::tolower);
    istringstream iss(command);
    string blank;
    vector<string> token;
    copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(token));
    

    vector<string> exits = cur_room->getExits();
    
    if(token[0] == "go")
    { 
     if(token[1] == "north" && (find(exits.begin(), exits.end(), "north") != exits.end()))
     {
        //this->moveTo(cur_room->getRoom("north"));
		this->walk("north");
        cout << "You are now in: " << cur_room->getRoom("north") ->getName() << "\n"  << endl;
        return true;
     }

    if(token[1] == "south" && (find(exits.begin(), exits.end(), "south") != exits.end()))
     {
       // this->moveTo(cur_room->getRoom("south"));
		this->walk("south");
        cout << "you are now in: " << cur_room->getRoom("south") ->getName() << "\n"  << endl;
        return true;
     }

    if(token[1] == "east" && (find(exits.begin(), exits.end(), "east") != exits.end()))
     {
        //this->moveTo(cur_room->getRoom("east"));
		this->walk("east");
        cout << "you are now in: " << cur_room->getRoom("east") ->getName() << "\n"  << endl;
        return true;
     }

    if(token[1] == "west" && (find(exits.begin(), exits.end(), "west") != exits.end()))
     {
        //this->moveTo(cur_room->getRoom("west"));
		this->walk("west");
        cout << "you are now in: " << cur_room->getRoom("west") ->getName() << "\n" << endl;
        return true;
     }
     return true;
    }

    if(token[0] == "quit")
    {
        return false;
    }

    if(token[0] == "get")
    { 
        set<Thing*> things = cur_room->getThings();
        auto search = things.find(cur_room->getThing(token[1]));
        if(search != things.end())
        {
           cout << "you found the thing" << endl;
           cur_room->remove((*search));
           add((*search));
           printThings(this);
        }
    }
    
    if(token[0] == "look")
    {
        cur_room->printThings(this);
        cur_room->printExits();
        cout << cur_room->getDesc() << endl;
		cout << "\n" << endl;
    }


    
    return true;
}
