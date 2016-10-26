#ifndef GAME_H
#define GAME_H
#include <string>
#include "agent.h"
#include <cstdlib>
#include "game.h"
#include <vector>

class Agent;

class Game {

    public:
        Game();
        void addAgent(Agent* agent);
        bool step();

    private:
        vector<Agent*> agents;

};
#endif
