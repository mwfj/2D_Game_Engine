#include<iostream>
#include<SDL2/SDL.h>

class Draw_filled_circle
{
private:
    SDL_Point& center;
    SDL_Renderer* renderer;
    const int radius;
    SDL_Color color;
public:
    Draw_filled_circle(
        SDL_Point&,
        SDL_Renderer*,
        int,
        SDL_Color
    );
    void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void setCenter(int x, int y);

    void draw_circle();
};
