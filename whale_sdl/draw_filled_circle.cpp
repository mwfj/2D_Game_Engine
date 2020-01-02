#include "draw_filled_circle.h"
#include<SDL2/SDL.h>
#include<iostream>

Draw_filled_circle::Draw_filled_circle(
    SDL_Point& center,
    SDL_Renderer* renderer,
    const int radius,
    SDL_Color color
):center(center),renderer(renderer), radius(radius), color(color){

}

void Draw_filled_circle::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a){
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
}


void Draw_filled_circle::draw_circle(){
    // std::cout<<"Center: "<<"["<<center.x<<","<<center.y<<"]"<<std::endl;
    // std::cout<<"Color: "<<"{"<<color.r<<","<<color.g<<","<<color.b<<","<<color.a<<"}"<<std::endl;
    SDL_SetRenderDrawColor(renderer, color.a, color.g, color.b, color.a);
    for(int w = 0; w < radius*2; w++){
        for(int h = 0; h < radius*2; h++)
        {
            int dx = radius - w; //horizontal offset
            int dy = radius - h; //vertical offset
            if ((dx*dx + dy*dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, center.x+dx, center.y+dy );
            }
            
        }
        
    }
    

}