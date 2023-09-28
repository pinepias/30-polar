#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include "game.h"
#include "graphics.h"
#include "sprite.h"
#include "player.h"
#include "plataform.h"

Game::Game()
{
    srand(time(0)); //random seed
    this->_timePlataform = ((rand() % 30) + 60 + 1);

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("Error to load SDL2\n");
        printf("Error: %s\n", SDL_GetError());
    }

    this->gameLoop();
}

void Game::gameLoop()
{
    Graphics graphics;
    SDL_Event event;

    //Background

    Sprite background(graphics, "../res/gfx/mar.png", 1, 0);
    int backPosX = 0;
    int seaSpeed = 5;

    //Player
    Player player(graphics);

    //Enemy

    //Plataform

    Plataform plataform(graphics, 1280, 350, -5, "../res/gfx/plataform.png");

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT: running = false; break;
            }
        }

        //Plataform code

        this->_timeCountPlataform = std::min(this->_timeCountPlataform + 1, this->_timePlataform);

        if (this->_timeCountPlataform >= this->_timePlataform)
        {
            Plataform _newPlataform(graphics, (640 + (256 / 2)), 350, -5, "../res/gfx/plataform.png");
            int _morsaChance = (rand() % 100);

            this->_plataforms.push_back(_newPlataform);

            this->_timePlataform = ((rand() % 30) + 60 + 1);
            this->_timeCountPlataform = 0;
        }

        backPosX = (backPosX + seaSpeed) % 640;

        this->clear(graphics);

        for (int i = 0; i < this->_plataforms.size(); ++i)
        {
            if (this->_plataforms[i].GetPosX() <= -256)
            {
                this->_plataforms.erase(this->_plataforms.begin() + i);
            }

            this->_plataforms[i].draw(graphics);
        }

        player.getState()->draw(graphics, 100, 100, 0.5, 0.5, false);
        background.draw(graphics, (backPosX - 640), 352, 1, 0.5, false);

        this->flip(graphics);

        SDL_Delay(DELAY_TIME);
    }
}

void Game::clear(Graphics &graphics)
{
    SDL_SetRenderDrawColor(graphics.getRenderer(), 210, 234, 239, 255);
    SDL_RenderClear(graphics.getRenderer());
}

void Game::flip(Graphics &graphics)
{
    SDL_RenderPresent(graphics.getRenderer());
}