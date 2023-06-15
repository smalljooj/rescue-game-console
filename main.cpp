#include <iostream>
#include "fase.h"
#include "sprite.h"

int main(int argc, char** argv)
{
    Sprite s("sprites/menu_hel.txt");
    s.init();
    Fase fs;
    std::string input;

    while(true)
    {
        for(auto o: s.get_sprite())
            std::cout << o << std::endl;
        std::cin >> input;
        fs.run();
    }

    return 0;
}
