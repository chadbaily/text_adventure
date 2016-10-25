#include "thing.h"
#include "game.h"
#include "agent.h"
using namespace std;

Agent::Agent(string _name, string _desc, int _size){
    name = _name;
    desc = _desc;
    size = _size;
}
bool Agent::walk(string exit){
    cur_room->moveTo(exit); 
    return cur_room->moveTo(exit);
}

virtual bool Agent::act(){
    return true;
}
