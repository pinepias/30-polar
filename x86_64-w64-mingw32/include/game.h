#ifndef _GAME_H_
#define _GAME_H_

#include <vector>

#include "plataform.h"

class Graphics;

namespace
{
    const int FPS = 60;
    const int DELAY_TIME = 1000 / FPS;
    bool running = true;
};

class Game
{
    public:
        Game();
        void gameLoop();
        void clear(Graphics &graphics);
        void flip(Graphics &graphics);

    private:
        float _timePlataform, _timeCountPlataform; 
        /*
        o primeiro e o tempo exemplo (100) 
        e o outro e o contador começa no (0)
        */

        std::vector<Plataform> _plataforms; //todas as plataformas de gelo
        bool _previousHaveMorsa;
};


#endif