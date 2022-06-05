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
#include <array>

using namespace std;

class Coordinate
{
    public:
    float x, y, z, value;

    Coordinate();
    Coordinate(float x1, float y2, float z2, float myAngle);
    Coordinate(float x1, float y2, float z2);
};



class ModColor{
    public:
        array<float, 4> amb;
        array<float, 4> dif;
        array<float, 4> spec;
        array<float, 4> emi;
        bool hasAmb;
        bool hasDif;
        bool hasSpec;
        bool hasEmi;
        float shinnValue;

        ModColor();
        ModColor(array<float, 4> my_amb, array<float, 4> my_dif, array<float, 4> my_spec, array<float, 4> my_emi, float my_shinnValue, bool hasAmb, bool hasDif, bool hasSpec, bool hasEmi);
};


class Figure
{
    public:
    GLuint buffers[3];
    int verticesCount;
    GLuint texture;
    ModColor modelColor;


    Figure(const char * model, const char * texture, ModColor my_modelColor); 

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
        float posX, posY, posZ; 
        float dirX, dirY, dirZ;
        float cutoff; 

        Light(bool my_isPoint, bool my_isDirectional, bool my_isSpotlight, float my_posX, float my_posY, float my_posZ, float my_dirX, float my_dirY, float my_dirZ, float my_cutoff);
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
        Tree(Group g, Camera cam, Lights lights);
        void printGroup();
};

Tree readFile(char *filename);


#endif // CG_PROJECT_TREE_HPP
