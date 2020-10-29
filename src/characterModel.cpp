class Personagem{
    private:
        int x, y, health;
        float teta;
    public:
        Personagem();
        int get_x();
        void set_x();
        int get_y();
        void set_y();
        int get_health();
        void set_health();
};

int Personagem::get_x(){
    return x;
}

