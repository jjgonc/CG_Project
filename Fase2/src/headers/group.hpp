#ifndef CG_PROJECT_GROUP_HPP
#define CG_PROJECT_GROUP_HPP

#include <vector>
#include "point.hpp"
#include <cmath>

using namespace std;

class Coordinate
{
private:
    float x, y, z, angle;

public:
    Coordinate();
    Coordinate(float x1, float y2, float z2, float myAngle);
    Coordinate(float x1, float y2, float z2);
};

class Figure
{
private:
    vector<Point> pontos;
    string name;

public:
    Figure(string name);    //construtor vazio

};

class Transform
{
private:
    Coordinate rotate, translate, scale;

public:
    Transform();
    Transform(Coordinate myTranslate, Coordinate myRotate, Coordinate myScale);
};

class Models
{
private:
    vector<Figure> figures;

public:
    Models();
    Models(vector<Figure> figures);
};

class Camera
{
private:
    Transform transform;
    float alpha;
    float beta;
    float radius;
    Point up;
    Point lookAt;
    float fov;
    float near;
    float far;
    Point scale;

public:
    Camera();
    Camera(float alpha, float beta, float radius, Point up, Point lookAt, float fov, float near, float far);
};

class Group
{
private:
    vector<Group> groups;
    Models models;

public:
    Group();
    Group(vector<Group> myGroups, Models models);
};

#endif // CG_PROJECT_GROUP_HPP
