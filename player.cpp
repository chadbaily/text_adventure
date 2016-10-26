#include <iostream>
#include<string>
#include "player.h"
#include "agent.h"
#include <sstream>
#include <algorithm>
#include <cctype>
#include <iterator>

using namespace std;

Player::Player(string _name, string _desc, int _size)
   :Agent(_name, _desc, _size)
 {}

bool Player::act(){
    string command;
    cout << "What would you like to do "<< this->getName() << " ?"  << endl;
    getline(cin, command);
    transform(command.begin(), command.end(), command.begin(), ::tolower);
    istringstream iss(command);
    string blank;
    vector<string> token;
    copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(token));
    vector<string> exits = cur_room->getExits();
    set<Thing*> things = cur_room->getThings();

    if(token[0] == "go")
    { 
     if(token[1] == "north" && (find(exits.begin(), exits.end(), "north") != exits.end()))
     {
        this->moveTo(cur_room->getRoom("north"));
        cout << "You are now in: " << cur_room ->getName() << endl;
     }

    if(token[1] == "south" && (find(exits.begin(), exits.end(), "south") != exits.end()))
     {
        this->moveTo(cur_room->getRoom("south"));
        cout << "you are now in: " << cur_room ->getName() << endl;
     }

    if(token[1] == "east" && (find(exits.begin(), exits.end(), "east") != exits.end()))
     {
        this->moveTo(cur_room->getRoom("east"));
        cout << "you are now in: " << cur_room ->getName() << endl;
     }

    if(token[1] == "west" && (find(exits.begin(), exits.end(), "west") != exits.end()))
     {
        this->moveTo(cur_room->getRoom("west"));
        cout << "you are now in: " << cur_room ->getName() << endl;
     }
    }

    if(token[0] == "quit")
    {
        return false;
    }

    if(token[0] == "get")
    {
       // if((find(things.begin(), things.end(), token[1]) != things.end()))
       // {
            //add to inventory
       // }
    }
    
    if(token[0] == "look")
    {
        cur_room->printThings(this);
        cur_room->printExits();
    }


    cout << "\n" << endl;
    return true;
}
