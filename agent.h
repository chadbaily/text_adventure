#ifndef AGENT_H
#define AGENT_H
#include "thing.h"
#include <string>
class Agent : public Thing{

    protected:
        Agent(string name, string desc, int size);
        bool walk(string exit);
    
    public:
        virtual bool act() = 0;
};
#endif
