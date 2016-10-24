#ifndef AGENT_H
#define AGENT_H
#include "thing.h"

class Agent : public Thing{

    protected:
        Agent(string name, string desc, int size);
        bool walk(string exit);
    public:
        vitrual bool act() = 0;
}
#endif
