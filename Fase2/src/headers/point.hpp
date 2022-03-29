#ifndef CG_PROJECT_POINT_H
#define CG_PROJECT_POINT_H
#include <string>
#include <iostream>
#include "vector.hpp"
#include <sstream>

using namespace std;

class Point
{
private:
    float x;
    float y;
    float z;

    // colocar aqui os métodos publicos
public:
    Point();
    Point(float, float, float);
    void addVector(Vector);
    float getX() const;
    float getY() const;
    float getZ() const;
    void setX(float);
    void setY(float);
    void setZ(float);
    string toString();
};

#endif