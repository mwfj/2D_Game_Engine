#include "draw_filled_triangle.h"
#include <iostream>
Draw_filled_Triangle::Draw_filled_Triangle(
    SDL_Renderer* renderer,
    const Vector2f& a,
    const Vector2f& b,
    const Vector2f& c
):renderer(renderer), a(a), b(b), c(c){

}

int Draw_filled_Triangle::smallest(int x, int y, int z) const{
    int temp = std::min(x,y);
    return std::min(temp, z);
}

int Draw_filled_Triangle::larggest(int x, int y, int z) const{
    int temp = std::max(x,y);
    return std::max(temp, z);
}

float Draw_filled_Triangle::wedge(Vector2f x, Vector2f y) const{
    return x[0]*y[1] - y[0]*x[1];
}

float Draw_filled_Triangle::in_triangle(Vector2f x, float fuzz) const{
    Vector2f e0 = b - a;
    Vector2f e1 = c - b;
    Vector2f e2 = a - c;
    float N = wedge(e1, -e0);
    if (N <= -0.00001)
    {
        N *= -1.0;
        e0 *= -1.0;
        e1 *= -1.0;
        e2 *= -1.0;
    }

    float b0 = wedge(e0, x - a);
    if (b0 <= -0.00001)
    {
        return 0.0;
    }
    float b1 = wedge(e1, x - b);
    if (b1 <= -0.00001)
    {
        return 0.0;
    }
    float b2 = wedge(e2, x - c);
    if (b2 <= -0.00001){
        return 0.0;
    }
    if (fuzz == 0.0){
        return 1.0;
    }
    return std::min(1.0, (pow(b0 * b1 * b2, 0.33) * 3.0 / N) / fuzz);
}

void Draw_filled_Triangle::draw_trianle(){
    
    float x = smallest(a[0],b[0],c[0]);
    float y = smallest(a[1],b[1],c[1]);
    Vector2f smallest_axis(x, y);
    //std::cout<< "Smallest Axis: " << smallest_axis << std::endl;

    x = larggest(a[0], b[0], c[0]);
    y = larggest(a[1], b[1], c[1]);
    Vector2f larggest_axis(x, y);
    //std::cout<< "Larggest Axis:" << larggest_axis <<std::endl;

    for(int i = smallest_axis[0]; i <= larggest_axis[0]; i++){ 
        //iterate all x coordinate
        for(int j = smallest_axis[1]; j<= larggest_axis[1]; j++ ){
            //iterate all y coordinate
            Vector2f p(i,j);
            if (in_triangle(p, 0.6))
            {
                SDL_RenderDrawPoint(renderer, i, j);
            }
            
        }
    }
    
}