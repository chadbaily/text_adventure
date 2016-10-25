#include <iostream>
#include<string>
#include "player.h"
#include "agent.h"
using namespace std;

Player::Player(string _name, string _desc, int _size){
    name = _name;
    desc = _desc;
    size = _size;
}

bool Player::act(){
   // regex r("([A-z])\w+");
    cout << "What would you like to do?" << endl;
   // cin
    return true;
}
