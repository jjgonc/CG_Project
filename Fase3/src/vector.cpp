#include "headers/vector.hpp"

Vector::Vector(float a, float b, float c)
{
    x = a;
    y = b;
    z = c;
}

void Vector::multiply(float m)
{
    x *= m;
    y *= m;
    z *= m;
}

void Vector::divide(float d)
{
    x /= d;
    y /= d;
    z /= d;
}

float Vector::getX() const { return x; }
float Vector::getY() const { return y; }
float Vector::getZ() const { return z; }

void Vector::setX(float a) { x = a; }
void Vector::setY(float b) { y = b; }
void Vector::setZ(float c) { z = c; }