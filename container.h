#ifndef CONTAINER_H
#define CONTAINER_H
#include "thing.h"
#include <set>
#include <vector>
#include <string>
using namespace std;

class Thing;

class Container {

    public:
        Container();
        bool add(Thing* thing);
        void remove(Thing* thing);
        void printThings(Thing* ignore);
        set <Thing*> getThings();
        Thing* getThing(string thing);

    protected:
        set<Thing*> things;
};
#endif

