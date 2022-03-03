// ver para que serve o #define e o #ifndef e o #endif

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
        float getX() const;
        float getY() const;
        float getZ() const;

        void setX(float a);
        void setY(float b);
        void setZ(float c);
};