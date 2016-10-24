#ifndef MONSTER_H
#define MONSTER_H
#include "agent.h"
public class Monster : public Agent {

    public:
        Monster(string name);
        bool act();
}
#endif
