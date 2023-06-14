#ifndef FASE 
#define FASE

#include "objeto_jogo.h" 
#include "sprite_base.h"
#include "helicopter.h"
#include "person.h"

#include <vector>
#include <iostream>

class Fase : public Game_base
{
    Sprite_base* background;
    std::vector<Objeto_jogo *> objs;

    public:
    Fase();

    void run();
    void show();
    
    void init() override;
    void update() override;
    void draw() override;

};


#endif // FASE
