#include<iostream>
#include<string>
#include "room.h"
#include "container.h"
#include "thing.h"
using namespace std;

Thing::Thing(string _name, string _desc, int _size)
    :name(_name), desc(_desc), size(_size), cur_container(NULL)
{}

bool Thing::moveTo(Container* container){
    if(container->add(this))
    {
        if(cur_container != NULL)
            cur_container->remove(this);
        cur_container = container;
        return true;
    }
    return false;
}

string Thing::getName(){
    return name;
}

string Thing::getDesc(){
    return desc;
}

int Thing::getSize(){
    return size;
}

void Thing::setName(string _name){
    name = _name;
}

void Thing::setDesc(string _desc){
    desc = _desc;
}

void Thing::setSize(int _size){
    size = _size;
}
