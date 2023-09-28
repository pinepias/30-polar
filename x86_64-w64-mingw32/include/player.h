#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "sprite.h"

class Graphics;

namespace
{
    Sprite walk;
    Sprite jump;
    Sprite fall;
    Sprite dead;
}


class Player
{
    public:
        Player(Graphics &graphics);
        Sprite *getState();
    private:
        Sprite *_state;
};


#endif