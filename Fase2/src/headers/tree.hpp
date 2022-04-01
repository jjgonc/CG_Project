#ifndef CG_PROJECT_TREE_HPP
#define CG_PROJECT_TREE_HPP

#include <vector>
#include "point.hpp"
#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

class Coordinate
{
    public:
    float x, y, z, angle;

    Coordinate();
    Coordinate(float x1, float y2, float z2, float myAngle);
    Coordinate(float x1, float y2, float z2);
};

class Figure
{
    public:
    vector<Point>* points;

    Figure(const char * name); 
    Figure(vector<Point>* points); 
    void printPoints();

};

class Transform
{
    public:
    Coordinate rotate, translate, scale;

    Transform();
    Transform(Coordinate myTranslate, Coordinate myRotate, Coordinate myScale);
};

class Models
{
    public:
    vector<Figure>* figures;

    Models();
    Models(vector<Figure> *figures);
    void printFigures();
};

class Camera
{
    public:
    float alpha;
    float beta;
    float radius;
    Point up;
    Point lookAt;
    float fov;
    float near;
    float far;
    Point scale;

    Camera();
    Camera(float alpha, float beta, float radius, Point up, Point lookAt, float fov, float near, float far);
};

class Group
{
    public:
    vector<Group> groups;
    Models models;
    Transform transform;

    Group();
    Group(vector<Group> myGroups, Models models, Transform transform);
    void printModels();
    Models getModels();
};


class Tree{
    public:
        Group group;
        Camera camera;
        Tree();
        Tree(Group g, Camera cam);
        void printGroup();
};

Tree readFile(char *filename);


#endif // CG_PROJECT_TREE_HPP
