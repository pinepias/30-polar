#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <math.h>

#include "plataform.h"
#include "graphics.h"
#include "sprite.h"

Plataform::Plataform(Graphics &graphics, float x, float y, float speed, const char *filePath)
{
    this->_sprite =  Sprite(graphics, filePath, 1, 0);
    this->_posX = x;
    this->_posY = y;
    this->_speed = speed;
}

void Plataform::draw(Graphics &graphics)
{
    this->_angle += 0.3;
    float _realAngle = (int)this->_angle;



    this->_posX = (this->_posX + this->_speed);
    this->_posY += sin(_realAngle);


    this->_sprite.draw(graphics, this->_posX, this->_posY, 0.5, 0.5, false);
}

float Plataform::GetPosX()
{
    return this->_posX;
}

float Plataform::GetPosY()
{
    return this->_posY;
}

float Plataform::GetSpeed()
{
    return this->_speed;
}

float Plataform::GetAngle()
{
    return this->_angle;
}