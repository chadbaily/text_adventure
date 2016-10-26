#ifndef THING_H
#define THING_H
#include <string>
using namespace std;

//Forward decleration
class Container;

class Thing {
    
    public:
        Thing(string _name, string _desc, int _size);
        bool moveTo(Container* container);
        string getName();
        string getDesc();
        int getSize();
    
    private:
        string name;
        string desc;
        int size;

    protected:
        Container* cur_container;
        void setName(string _name);
        void setDesc(string _desc);
        void setSize(int size);

};

#endif
