#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <map>

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;

class Graphics
{
    public:
        Graphics();
        ~Graphics();

        SDL_Renderer *getRenderer();
        SDL_Surface *loadImage(const char *filePath);

    private:
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        std::map<const char *, SDL_Surface *> _textures;
};


#endif