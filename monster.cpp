#include <string>
#include <iostream>
#include "thing.h"
#include "room.h"
using namespace std;

Monster::Monster(string _name)
    :Agent(_name, NULL, NULL);
{}

bool Monster::act(){
    return true;
}
