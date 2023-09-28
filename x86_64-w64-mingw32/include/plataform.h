#ifndef _PLATAFORM_H_
#define _PLATAFORM_H_

#include "sprite.h"

class Graphics;

class Plataform
{
    public:
        Plataform(Graphics &graphics, float x, float y, float speed, const char *filePath);
        void draw(Graphics &graphics);

        float GetPosX();
        float GetPosY();
        float GetSpeed();
        float GetAngle();

    private:
        Sprite _sprite;
        float _posX, _posY, _speed, _angle;
};

#endif