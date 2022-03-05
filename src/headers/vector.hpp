#ifndef CG_PROJECT_VECTOR_H
#define CG_PROJECT_VECTOR_H

#include <string>
#include <iostream>
#include <sstream>

class Vector{
private:
    float x, y, z;

public:
    Vector(float, float, float);
    void multiply(float);
    void divide(float);
    float getX() const;
    float getY() const;
    float getZ() const;
    void setX(float);
    void setY(float);
    void setZ(float);
};
#endif