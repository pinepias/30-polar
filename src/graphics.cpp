#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "graphics.h"

Graphics::Graphics()
{
    SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "30 Polar");
}

Graphics::~Graphics()
{
    SDL_DestroyWindow(this->_window);
}

SDL_Renderer *Graphics::getRenderer()
{
    return this->_renderer;
}

SDL_Surface *Graphics::loadImage(const char *filePath)
{
    if (this->_textures.count(filePath) == 0)
    {
        this->_textures[filePath] = IMG_Load(filePath);
    }

    return this->_textures[filePath];
}