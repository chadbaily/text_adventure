#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include "thing.h"
#include "container.h"
using namespace std;

Container::Container(){

}

set<Thing*> Container::getThings(){
   return things;
}
bool Container::add(Thing* thing){
    things.insert(thing);
    return true;
}

void Container::remove(Thing* thing){
    things.erase(thing);
}

void Container::printThings(Thing* ignore){
    for(set<Thing*>::iterator it = things.begin(); it != things.end(); ++it)
    {
        if(*it == ignore)
        {
        }
        else
            cout << "The things in the room are: " << (*it)->getName() << " " << endl;
    }
}

Thing* Container::getThing(string thing){
    for(set<Thing*>::iterator it = things.begin(); it != things.end(); ++it)
    {
        string obj = (*it)->getName();
        transform(obj.begin(), obj.end(), obj.begin(), ::tolower);
        if(obj == thing)
        {   
            return *it;
        }
    }
return 0;
}
