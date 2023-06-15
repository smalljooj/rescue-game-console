#include "sprite.h"
#include <iostream>

Sprite::Sprite(std::string const& name): name(name){ }

void Sprite::init()
{

    std::ifstream arquive (name);
    std::string line;
    if(arquive.is_open())
    {
        while(getline(arquive, line))
        {
           sprite.push_back(line); 
        }
    }
    else
        std::cout << "erro" << std::endl;

}

void Sprite::update()
{

}

void Sprite::draw() 
{

}
