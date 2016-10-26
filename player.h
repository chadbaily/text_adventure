#ifndef PLAYER_H
#define PLAYER_H
#include "agent.h"
#include "thing.h"
#include <string>
#include "container.h"
using namespace std;

class Player : public Agent, public Container {

    public:
        Player(string _name, string _desc, int _size);
        bool act();


    private:
        Container* inventory;
};
#endif
