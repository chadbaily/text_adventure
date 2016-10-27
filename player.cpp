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
    cout << "What would you like to do " << this->getName() << " ?"  << endl;
    getline(cin, command);
    transform(command.begin(), command.end(), command.begin(), ::tolower);
    istringstream iss(command);
    string blank;
    vector<string> token;
    copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(token));
    vector<string> exits = cur_room->getExits();
    
    if(token.empty())
    {
        cout << "you didn't enter anything!!!" << endl;
        return true;
    }

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

    if(token[1] == "up" && (find(exits.begin(), exits.end(), "up") != exits.end()) && (cur_room->getName() == "Field"))
     {
        //this->moveTo(cur_room->getRoom("west"));
		this->walk("up"); //well its more of like flying...
        cout << "you are now in: " << cur_room->getRoom("up") ->getName() << "\n" << endl;
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
           cur_room->remove((*search));
           add((*search));
           cout << (*search)->getDesc();
        }
        cout << "\n" << endl;
    }
    
    if(token[0] == "look")
    {
        cur_room->printThings(this);
        
        if(cur_room->getName() == "Hallway")
        {
            set<Thing*> things = getThings();
            auto search = things.find(getThing("torch"));
            if(search != things.end())
            {
                cur_room->printExits("none");
            }
            
            else
            {
                cur_room->printExits("Cellar");
            }
        }
        cout << cur_room->getDesc() << endl;
		cout << "\n" << endl;
    }

    if(token[0] == "inventory")
    {
        for(set<Thing*>::iterator it = things.begin(); it != things.end(); ++it)
        {
            cout << "You currently have: " << (*it)->getName() << ", " << endl;
        }
        cout << "\n" << endl;
    }

    if(token[0] == "help")
    {
        cout << "You have asked for help. Here are some of the commands that you are able to perform." << "\n" << endl;
        cout << "Look -- this command allows you to see everything in a room. Including a monster!!!" << "\n" << endl;
        cout << "Go ____ -- Combine this command with: North, South, East, and West if available to move!" << "\n" << endl;
        cout << "Drop -- Allows you do drop an item in your inventory" << "\n" << endl;
        cout << "Inventory -- Allows you view what you currently have in your inventory, you may be suprised with what you can carry..." << "\n" <<  endl;
        cout << "Get -- Allows you get obejects that are in your current room" << "\n" << endl;
        cout << "Quit -- Quits the game, it ony takes one player!" << "\n" << endl;
    }

    if(token[0] == "drop")
    {
        set<Thing*> things = getThings();
        auto search = things.find(getThing(token[1]));
        if(search != things.end())
        {
           remove((*search));
           cur_room->add((*search));
        }
        cout << "\n" << endl;
    } 

    return true;
}
