#include <math.h>

#include "enemy.h"
#include "graphics.h"
#include "plataform.h"

Enemy::Enemy(Graphics &graphics, float x, float y, float rotation, float speed, const char *filePathIdle, const char *filePathWalk)
{
    this->_idle = Sprite(graphics, filePathIdle, 1, 0.0);
    this->_walk = Sprite(graphics, filePathWalk, 1, 0.0);

    this->_state = &this->_idle;
    this->_speed = speed;

    this->_posX = x;
    this->_posY = y;

    this->_rotation = rotation;
}
Enemy::~Enemy() {}

void Enemy::draw(Graphics &graphics)
{
    this->_posX += this->_speed;

    if (this->_plataform != NULL)
    {
        this->_angle += 0.3;
        this->_posY = this->_posY + sin(this->_angle);
    }

    this->_state->draw(graphics, this->_posX, this->_posY, 0, 0.5, 0.5, false);
}

Sprite *Enemy::getIdle()
{
    return &this->_idle;
}

Sprite *Enemy::getWalk()
{
    return &this->_walk;
}

Sprite *Enemy::getState()
{
    return this->_state;
}

void Enemy::setState(Sprite *sprite)
{
    this->_state = sprite;
}

float Enemy::getPosX()
{
    return this->_posX;
}

float Enemy::getPosY()
{
    return this->_posY;
}

void Enemy::setPlataform(bool have)
{
    this->_plataform = have;
}