#include "point.hpp"
#include "math.h"
#include <cmath>
#include <sstream>

#define _USE_MATH_DEFINES



Point::Point(float a, float b, float c) {
    x = a;
    y = b;
    z = c;
}

void Point::addVector(Vector v) {
    x += v.getX();
    y += v.getY();
    z += v.getZ();
}


void Point::setX(float a) { x = a;  }

void Point::setY(float b){  y = b;  }

void Point::setZ(float c){  z = c;  }


float Point::getX() const { return x;   }
float Point::getY() const { return y;   }
float Point::getZ() const { return z;   }