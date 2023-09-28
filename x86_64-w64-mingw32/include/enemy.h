#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "sprite.h"

class Graphics;
class Plataform;

class Enemy
{
    public:
        Enemy(Graphics &graphics, float x, float y, float rotation, float speed, const char *filePathIdle, const char *filePathWalk);
        ~Enemy();

        void draw(Graphics &grpahics);
        void setPlataform(bool have);

        Sprite *getState();
        Sprite *getIdle();
        Sprite *getWalk();


        float getPosX();
        float getPosY();
        void setState(Sprite *sprite);


    private:
        Sprite _walk, _idle;
        Sprite *_state;

        bool _plataform;

        float _posX, _posY, _angle, _speed, _rotation;
};


#endif