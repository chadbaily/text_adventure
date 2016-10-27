#ifndef AGENT_H
#define AGENT_H
#include "thing.h"
#include <string>
using namespace std;
class Agent : public Thing{

    protected:
        Agent(string _name, string _desc, int _size);
        bool walk(string exit);
        virtual ~Agent() = default;

    public:
        virtual bool act() = 0;
};
#endif
