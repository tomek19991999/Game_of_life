#include <iostream>
#include "Game.h"

int main()
{
    //init srand
    std::srand(static_cast<unsigned>(time(NULL)));

    //Initialisation game engine
    Game game;
        //game.start();

    //Game loop
    while (!game.getEndGame() == false) {



        //Update
        game.update();
        //Render
        game.render();
    }
}

