class Thing {
    
    public:
        Thing(string name, string desc, int size);
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

}
