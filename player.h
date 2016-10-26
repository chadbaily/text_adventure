#ifndef PLAYER_H
#define PLAYER_H
#include "agent.h"
#include "room.h"
#include "thing.h"
#include <string>
using namespace std;
class Player : public Agent {

    public:
        Player(string _name, string _desc, int _size);
        bool act();


    private:
        Room* inventory;
};
#endif
