#ifndef ROOM_H
#define ROOM_H
#include "thing.h"
#include "monster.h"
#include "player.h"
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Thing;

class Room {

    public:
        Room(string _name, string _desc, int size);
        string getName();
        string getDesc();
        void link(Room* _room, string _exit);
        vector<string> getExits();
        set<Thing*>  getThings();
        bool add(Thing* thing);
        void remove(Thing* thing);
        void printExits();
        void printThings(Thing* ignore);
        Room* getRoom(string _exit);

    private:
        string name;
        string desc;
        int size;
        set<Thing*> things;
        map<string, Room*> exits;
};
#endif
