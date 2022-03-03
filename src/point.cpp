#include <cmath>
#include <sstream>
#include "point.hpp"



Point::Point(float a, float b, float c) {
    x = a;
    y = b;
    z = c;
}




void Point::setX(float a) { x = a;  }

void Point::setY(float b){  y = b;  }

void Point::setZ(float c){  z = c;  }


float Point::getX() const { return x;   }
float Point::getY() const { return y;   }
float Point::getZ() const { return z;   }