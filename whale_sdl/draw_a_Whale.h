#include <SDL2/SDL.h>
#include "vector2f.h"
#include "draw_filled_triangle.h"
#include "draw_filled_circle.h"

class Draw_a_Whale
{
private:
    SDL_Renderer* renderer;
public:
    Draw_a_Whale(SDL_Renderer* renderer):renderer(renderer){}
    void draw();
};

