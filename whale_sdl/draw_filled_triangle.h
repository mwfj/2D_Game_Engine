#include<iostream>
#include<SDL2/SDL.h>
#include "vector2f.h"

class Draw_filled_Triangle{
private:
    SDL_Renderer* renderer;
    Vector2f a;
    Vector2f b;
    Vector2f c;
    float in_triangle(Vector2f, float) const;
    float wedge(Vector2f, Vector2f) const;
    int smallest(int, int, int) const;
    int larggest(int, int, int) const;
public:
    Draw_filled_Triangle(
        SDL_Renderer*, 
        const Vector2f&, 
        const Vector2f&, 
        const Vector2f&);
    void draw_trianle();
};