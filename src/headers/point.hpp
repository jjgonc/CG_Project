#ifndef POINT_H
#define POINT_H
#include <string>
#include <iostream>
#include <sstream>


class Point {
    private:
        float x;
        float y;
        float z;

    //colocar aqui os métodos publicos
    public:
        Point(float, float, float);
        void addVector(Vector v);
        float getX() const;
        float getY() const;
        float getZ() const;

        void setX(float a);
        void setY(float b);
        void setZ(float c);
};

#endif