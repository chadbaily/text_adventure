#ifndef THING_H
#define THING_H
#include <string>
using namespace std;

//Forward decleration
class Room;

class Thing {
    
    public:
        Thing(string _name, string _desc, int _size);
        bool moveTo(Room* room);
        string getName();
        string getDesc();
        int getSize();
    
    private:
        string name;
        string desc;
        int size;

    protected:
        Room* cur_room;

};

#endif
