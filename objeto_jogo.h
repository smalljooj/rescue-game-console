#ifndef OBJETO_JOGO
#define OBJETO_JOGO

#include "game_base.h"
#include "sprite_animado.h"
#include "sprite.h"

class Objeto_jogo : public Game_base
{
protected:
    Sprite_base * sprite;
    int x, y;
    int size_x;
    int size_y;
    bool active;
public:
    Objeto_jogo(std::string const&, int, int, int);
    ~Objeto_jogo();

    void move_to(int, int);
    void ative_toggle(bool);

    int get_x() const { return x; };
    int get_y() const { return y; };

    int get_size_x() const { return size_x; };
    int get_size_y() const { return size_y; };

    int get_active() const { return active; };

    bool colide(Objeto_jogo const&) const;


    void init() override;
    void update() override;
    void draw() override;

private:
    

};


#endif //OBJETO_JOGO
