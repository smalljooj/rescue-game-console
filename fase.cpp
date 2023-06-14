#include "fase.h"


Fase::Fase()
{
    init();
}

void Fase::run()
{
    show();
    char input;
    std:: cin >> input;
    switch(input)
    {
        case 'a':
            objs[0]->move_to(objs[0]->get_x() - 1, objs[0]->get_y()); 
            break;
        case 'd':
            objs[0]->move_to(objs[0]->get_x() + objs[0]->get_size_x() + 1, objs[0]->get_y()); 
            break;
        case 'w':
            objs[0]->move_to(objs[0]->get_x(), objs[0]->get_y() - 1); 
            break;
        case 's':
            objs[0]->move_to(objs[0]->get_x(), objs[0]->get_y() + objs[0]->get_size_y() + 1); 
            break;
    }
    update();
}

void Fase::show()
{
    for(auto s: background->get_sprite())
        std::cout << s << std::endl;

}

void Fase::init()
{
    background = new Sprite_animado("sprites/background");
    background->init();

    objs.push_back(new Helicopter());
    objs.push_back(new Person());
    objs.push_back(new Person());

    objs[1]->move_to(67, 37);
    objs[2]->move_to(148, 37);

}

void Fase::update()
{
    for(auto o: objs)
        o->update();
}

void Fase::draw() { }
