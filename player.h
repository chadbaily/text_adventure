#ifndef PLAYER_H
#define PLAYER_H
#include  "agent.h"
#include "room.h"
class Room;

class Player : public Agent {

    public:
        Player(string name, string desc, int size);
        bool act();
}
#endif
