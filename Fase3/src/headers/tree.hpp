#ifndef CG_PROJECT_TREE_HPP
#define CG_PROJECT_TREE_HPP

#include <stdlib.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif


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
    GLuint vertices;
    int verticesCount;


    Figure(const char * name); 

};


class CatmullRom
{
    public:
    float time;
    vector<Point> points;
    bool isRotate;
    Point point;

    CatmullRom ();
    CatmullRom(float nTime, std::vector<Point> nPoints, bool isRotate, Point myPoint);
};


class Transform
{
    public:
    bool hasRotate, hasTranslate, hasScale, isCatmullRom;
    Coordinate rotate, translate, scale;
    CatmullRom catmullRom;

    Transform();
    Transform(Coordinate myTranslate, Coordinate myRotate, Coordinate myScale, CatmullRom catmullRom);
};

class Models
{
    public:
    vector<Figure> figures;

    Models();
    Models(vector<Figure> figures);
 
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
