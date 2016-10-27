#include "thing.h"
#include "agent.h"
#include "room.h"
#include <string>
#include <map>
#include <vector>
using namespace std;

Agent::Agent(string _name, string _desc, int _size)
    : Thing(_name, _desc, _size)
{}
bool Agent::walk(string _exit){
 //see if it is a possible exit, and if it is then movie it ?
    Room* cur_room = (Room*)cur_container;
    vector<string> exits = cur_room->getExits();
    for(unsigned int i = 0; i < exits.size(); i++)
    {
        if(exits[i] == _exit)
        {
            this->moveTo(cur_room->getRoom(_exit));
            return true;
        }
    }
    return false;
}

bool Agent::act(){
    return true;
}

