#include "fase.h"
#include <stdlib.h>

Fase::Fase()
{
    init();
}

void Fase::run()
{
    char input;
    while(true)
    {
        draw();
        show();
        std:: cin >> input;
        heli_fuel -= 2;
        if(!heli_fuel)
        {
            std::cout << "No fuel, GAME OVER" << std::endl;
            return;
        }
        if(input == 'p')
        {
            std::cout << "pause" << std::endl;
            std:: cin >> input;
            while(input != 'p')
                std:: cin >> input;
        }
        switch(input)
        {
            case 'a':
                objs[0]->move_to(objs[0]->get_x() - 4, objs[0]->get_y()); 
                break;
            case 'd':
                objs[0]->move_to(objs[0]->get_x() + 4, objs[0]->get_y()); 
                break;
            case 'w':
                objs[0]->move_to(objs[0]->get_x(), objs[0]->get_y() - 2); 
                break;
            case 's':
                objs[0]->move_to(objs[0]->get_x(), objs[0]->get_y() + 2); 
                break;
            case 'x':
                for(auto p : objs)
                {
                    if(p->get_type() == 'p')
                    {
                        if(objs[0]->colide(*p) && heli_charge > 0)
                        {
                            p->active_toggle(false);
                            heli_charge--;
                        }
                    }
                    else if(p->get_type() == 'b') 
                    {
                        if(objs[0]->colide(*p))
                        {
                            heli_charge = 1;
                            peoples--;
                        }
                    }
                }
                break;
            case 'q':
                return;
        }
        update();
        if(!peoples)
        {
            std::cout << "Nice Game" << std::endl;
            return;
        }

    }
}

void Fase::show()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    for(int i = 0; i < 40; i++)
    {
        for(int j = 0; j < 170; j++)
            std::cout << buffer[current_buffer][i][j];
        std::cout << std::endl;
    }

}

void Fase::init()
{
    background = new Sprite_animado("sprites/background");
    background->init();

    objs.push_back(new Helicopter());
    objs.push_back(new Person());
    objs.push_back(new Person());
    objs.push_back(new Rescue_base());

    objs[0]->move_to(30, 7);
    objs[1]->move_to(64, 36);
    objs[2]->move_to(160, 36);
    objs[3]->move_to(13, 34);

    for(auto o: objs)
        o->init();

    clear_buffer();

}

void Fase::update()
{
    for(auto o: objs)
        o->update();
    background->update();
}

void Fase::draw() 
{
    for(auto o : objs)
    {
        Sprite_base const* sprite = o->get_sprite();
        if(!o->get_active())
            continue;
        for(int i = 0; i < o->get_size_y(); i++)
            for(int j = 0; j < o->get_size_x(); j++)
            {
                buffer[cont_buffer][i + o->get_y()][j + o->get_x()] = sprite->get_sprite()[i][j]; 
            }
    }

    for(int i = 0; i < 40; i++)
    {
        for(int j = 0; j < 170; j++)
            if(buffer[cont_buffer][i][j] == ' ')
                buffer[cont_buffer][i][j] = background->get_sprite()[i][j]; 
    }

    std::stringstream ss;
    ss << "Carga: " << heli_charge << "          | " << "Combustivel: " << heli_fuel;
    for(int i = 0; i < ss.str().size(); i++)
        buffer[cont_buffer][3][i + 2] = ss.str()[i];
    // usos futuros
    swap_buffer();
    clear_buffer();
}

void Fase::clear_buffer()
{
    
    for(int i = 0; i < 40; i++)
    {
        for(int j = 0; j < 170; j++)
            buffer[cont_buffer][i][j] = ' ';
    }

}

void Fase::swap_buffer()
{
    if(cont_buffer)
    {
        cont_buffer = 0;
        current_buffer = 1;
    }
    else
    {
        cont_buffer = 1;
        current_buffer = 0;
    }
}
