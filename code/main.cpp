#include <iostream>

#include "../headers/game.h"
#include "../headers/config.h"

int main()
{   
    srand(time(0));
    Game game;

    float accumulator = Config::OFFSET;
    float dt = 1.f / Config::FPS;
    float time = 0.f;

    while (game.window.isOpen())
    {      
        sf::Event event;
        while (game.window.pollEvent(event))
        {   
            game.handleEvents(event);
        }
        
        float frame_t = game.getEllapsedTime();
        accumulator += frame_t;
        while(accumulator >= dt){
            game.update(dt);
            accumulator -= dt;
        }

        game.draw();
    }
}