#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "sprite.h"
#include "graphics.h"

Sprite::Sprite() {}

Sprite::Sprite(Graphics &graphics, const char *filePath, int frameX, float time)
{
    this->_texture = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage((char *)filePath));

    if (this->_texture == NULL)
    {
        printf("Error to load texture!\n");
    }
    else
    {
        this->_totalFrames = frameX;
        this->_time = time;
        this->_currentFrame = 0;
        this->_frame = 0;

        SDL_QueryTexture(this->_texture, NULL, NULL, &this->_width, &this->_height);
    }

}

void Sprite::draw(Graphics &graphics, float x, float y, float scaleX, float scaleY, bool play)
{
    SDL_Rect src =  {0, 0, (this->_width / this->_totalFrames), this->_height};
    SDL_Rect dest = {x, y, (this->_width / this->_totalFrames) * scaleX, this->_height * scaleY};
    SDL_Point center = {(this->_width / this->_totalFrames) / 2, (this->_height / 2)};

    SDL_RendererFlip flip = SDL_FLIP_NONE;

    SDL_RenderCopyEx(graphics.getRenderer(), this->_texture, &src, &dest, 0.0, &center, flip);
}