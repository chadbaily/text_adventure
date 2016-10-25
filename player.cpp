#include <iostream>
#include<string>
#include "player.h"
#include "agent.h"
using namespace std;

Player::Player(string _name, string _desc, int _size)
   :Agent(_name, _desc, _size)
 {}

// this->setName(_name);
//this->setDesc(_desc);
   // this->setSize(_size);
   // cur_room = NULL;

bool Player::act(){
   // regex r("([A-z])\w+");
    cout << "What would you like to do?" << endl;
   // cin
    return true;
}
