#include <cstdlib>
#include "game.h"
#include "agent.h"

Game::Game(){
    srand(time(NULL));
}

void Game::addAgent(Agent* agent){
    agents.push_back(agent);
}

bool Game::step(){
    for(unsigned int i = 0; i < agents.size(); i++)
    {
        if(!agents[i]->act()) return false;
    }
    return true;
}
