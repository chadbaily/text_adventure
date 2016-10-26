#ifndef MONSTER_H
#define MONSTER_H
#include "agent.h"
#include "room.h"
#include "thing.h"
using namespace std;
class Container;

class Monster : public Agent {

    public:
        Monster(string name);
        bool act();
};
#endif
