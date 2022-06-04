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
    float x, y, z, value;

    Coordinate();
    Coordinate(float x1, float y2, float z2, float myAngle);
    Coordinate(float x1, float y2, float z2);
};

class Figure
{
    public:
    GLuint buffers[3];
    int verticesCount;
    GLuint texture;


    Figure(const char * model, const char * texture); 

};


class CatmullRom
{
    public:
    vector<Point> points;
    float time;
    bool align;

    CatmullRom ();
    CatmullRom(std::vector<Point> nPoints, float myTime, bool myAlign);
};


class Transform
{
    public:
    bool hasRotate, hasTranslate, hasScale, isCatmullRom, hasTime;
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



class Light{
    public:
        bool isPoint, isDirectional, isSpotlight;
        float posX, posY, posZ; bool hasPosX, hasPosY, hasPosZ;
        float dirX, dirY, dirZ; bool hasDirX, hasDirY, hasDirZ;
        float cutoff; bool hasCutoff;

        Light(bool my_isPoint, bool my_isDirectional, bool my_isSpotlight, float my_posX, float my_posY, float my_posZ, bool my_hasPosX, bool my_hasPosY, bool my_hasPosZ, float my_dirX, float my_dirY, float my_dirZ, bool my_hasDirX, bool my_hasDirY, bool my_hasDirZ, float my_cutoff, bool my_hasCutoff);
};


class Lights{
    public:
        vector<Light> lights;

        Lights();
        Lights(vector<Light> lightsVector);
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
        Lights lights;
        Camera camera;
        Tree();
        Tree(Group g, Camera cam);
        void printGroup();
};

Tree readFile(char *filename);


#endif // CG_PROJECT_TREE_HPP
