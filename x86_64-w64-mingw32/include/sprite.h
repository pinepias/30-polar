#ifndef _SPRITE_H_
#define _SPRITE_H_

class Graphics;
struct SDL_Texture;

class Sprite
{
    public:
        Sprite();
        Sprite(Graphics &graphics, const char *filePath, int frameX, float time);
        ~Sprite();

        SDL_Texture *getTexutre();

        void draw(Graphics &graphics, float x, float y, float rotation, float scaleX, float scaleY, bool play);

    private:
        SDL_Texture *_texture;

        int _width, _height;

        float _currentFrame;
        int _totalFrames;
        int _frame;
        int _time;
};

#endif