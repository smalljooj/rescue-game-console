#include "sprite.h"

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

}

void Sprite::update()
{

}

void Sprite::draw() 
{

}
