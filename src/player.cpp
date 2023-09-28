#include "player.h"
#include "sprite.h"

Player::Player(Graphics &graphics)
{
    walk = Sprite(graphics, "../res/gfx/urso_parado.png", 1, 0.0);
    jump = Sprite(graphics, "../res/gfx/urso_pulo.png", 1, 0.0);
    fall = Sprite(graphics, "../res/gfx/urso_caindo.png", 1, 0.0);
    dead = Sprite(graphics, "../res/gfx/urso_caido.png", 1, 0.0);

    this->_state = &walk;
}

Sprite *Player::getState()
{
    return this->_state;
}