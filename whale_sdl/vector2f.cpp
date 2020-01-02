#include<iostream>
#include<cmath>
#include "vector2f.h"
#include <string>

Vector2f::Vector2f(float x, float y){
    v_2d[0] = x;
    v_2d[1] = y;
}

float &Vector2f::operator[](int index){
    return v_2d[index];
}

float Vector2f::operator[](int index) const{
    return v_2d[index];
}

// Assignment
Vector2f& Vector2f::operator=(const Vector2f &rhs)
{
    if (this != &rhs)
    {
        v_2d[0] = rhs.v_2d[0];
        v_2d[1] = rhs.v_2d[1];
    }
    return *this;
}

// Add
Vector2f Vector2f::operator+(const Vector2f &b) const{
    return(Vector2f(v_2d[0]+b.v_2d[0], v_2d[1]+b.v_2d[1]));
}

const Vector2f &Vector2f::operator+=(const Vector2f &b){
    v_2d[0]+= b.v_2d[0];
    v_2d[1]+= b.v_2d[1];
    return *this;
}
// Substract
Vector2f Vector2f::operator-(const Vector2f &b) const{
    return Vector2f(v_2d[0]-b.v_2d[0], v_2d[1]-b.v_2d[1]);
}
const Vector2f &Vector2f::operator-=(const Vector2f &b){
    v_2d[0]-=b.v_2d[0];
    v_2d[1]-=b.v_2d[1];
    return *this;
}

// Multiply
Vector2f Vector2f::operator*(float scale) const{
    return Vector2f(v_2d[0]*scale, v_2d[1]*scale);
}

Vector2f operator*(float scale, const Vector2f &v){
    return v * scale;
}

const Vector2f &Vector2f::operator*=(float scale){
    v_2d[0] *= scale;
    v_2d[1] *= scale;
    return *this;
}
// Divide
Vector2f Vector2f::operator/(float scale) const{
    return(Vector2f(v_2d[0]/scale, v_2d[1]/scale));
}

const Vector2f &Vector2f::operator/=(float scale){
    if (scale<0.001 && scale > -0.001) {
        throw std::string("Scale too small to caculate in '/=' ");
    }
    v_2d[0]/=scale;
    v_2d[1]/=scale;
    return *this;
}
// Minus
Vector2f Vector2f::operator-() const{
   return Vector2f(-v_2d[0], -v_2d[1]); 
}

std::ostream &operator<<(std::ostream &output, const Vector2f &v){
    output<< '('<< v[0] << ',' << v[1] << ')';
    return output;
}