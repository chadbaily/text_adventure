class Agent : public Thing{

    protected:
        Agent(string name, string desc, int size);
        bool walk(string exit);
    public:
        vitrual bool act();
}

