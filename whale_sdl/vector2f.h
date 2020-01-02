#ifndef VECTOR2F_H
#define VECTOR2F_H

#include <iostream>

class Vector2f
{
  private:
    float v_2d[2]; // v_2d[0] for storing x axis, v_2d[1] for storing y axis

  public:
    explicit Vector2f(float x = 0, float y =0);
    
    float &operator[](int index);
    float operator[](int index) const;

    bool operator==(const Vector2f &b) const{
        return ((v_2d[0] == b.v_2d[0]) && (v_2d[1] == b.v_2d[1]));
    }

    bool operator!=(const Vector2f &b) const{
        return ((v_2d[0] != b.v_2d[0])&&(v_2d[1] != b.v_2d[1]));
    }

    Vector2f operator*(float scale) const;
    Vector2f operator/(float scale) const;
    Vector2f operator+(const Vector2f &b) const;
    Vector2f operator-(const Vector2f &b) const;
    Vector2f operator-() const;

    const Vector2f &operator*=(float scale);
    const Vector2f &operator/=(float scale);
    const Vector2f &operator+=(const Vector2f &b);
    const Vector2f &operator-=(const Vector2f &b);
    Vector2f &operator=(const Vector2f &);
};

Vector2f operator*(float scale, const Vector2f &v);
std::ostream &operator<<(std::ostream &output, const Vector2f &v);

#endif