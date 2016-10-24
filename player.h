#ifndef PLAYER_H
#define PLAYER_H
#include  "agent.h"
class Player : public Agent {

    public:
        Player(string name, string desc, int size);
        bool act();
}
#endif
