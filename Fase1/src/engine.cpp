#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <cstdio>
#include <vector>
#include <string>
#include "headers/point.hpp"
#include "headers/tinyxml2.hpp"
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;
char *modelFileName;

int angle = 0;
float tx = 0.1;
float ty = 0.1;
float tz = 0.1;
float scalex = 1.0;
float scaley = 1.0;
float scalez = 1.0;

float positionX;
float positionY;
float positionZ;
float upX;
float upY;
float upZ;
float lookAtX;
float lookAtY;
float lookAtZ;
float fov;
float near;
float far;
vector<string> readModels;

float alpha;
float betha;
float radius;

GLenum mode = GL_FILL;

void readFile(char *filename)
{

    std::vector<string> modelsName; // vector com o nome das figuras

    std::vector<string> figurasToLoad; // vector com os nomes das figuras presentes no ficheiro XML
    string generated_path = "../../vertices/";

    tinyxml2::XMLDocument doc;
    doc.LoadFile(filename);
    if (doc.ErrorID())
    {
        printf("%s\n", doc.ErrorStr());
        exit(0);
    } // abre ficheiro XML
    printf("%s\n", filename);

    tinyxml2::XMLNode *pRoot = doc.FirstChildElement("world");
    if (pRoot == nullptr)
        exit(0);

    tinyxml2::XMLElement *position = pRoot->FirstChildElement("camera")->FirstChildElement("position");
    tinyxml2::XMLElement *lookAt = pRoot->FirstChildElement("camera")->FirstChildElement("lookAt");
    tinyxml2::XMLElement *up = pRoot->FirstChildElement("camera")->FirstChildElement("up");
    tinyxml2::XMLElement *projection = pRoot->FirstChildElement("camera")->FirstChildElement("projection");

    positionX = stof(position->Attribute("x"));
    positionY = stof(position->Attribute("y"));
    positionZ = stof(position->Attribute("z"));
    lookAtX = stof(lookAt->Attribute("x"));
    lookAtY = stof(lookAt->Attribute("y"));
    lookAtZ = stof(lookAt->Attribute("z"));
    upX = stof(up->Attribute("x"));
    upY = stof(up->Attribute("y"));
    upZ = stof(up->Attribute("z"));
    fov = stof(projection->Attribute("fov"));
    near = stof(projection->Attribute("near"));
    far = stof(projection->Attribute("far"));

    radius = sqrt(positionX * positionX + positionY * positionY + positionZ * positionZ);
    betha = atan2(positionY, positionX);
    alpha = acos(positionZ / radius);

        tinyxml2::XMLElement *scenefiguras = pRoot->FirstChildElement("group")->FirstChildElement("models")->FirstChildElement("model");
    for (; scenefiguras != nullptr; scenefiguras = scenefiguras->NextSiblingElement("model"))
    {
        string newfigura = generated_path + scenefiguras->Attribute("file");
        readModels.push_back(newfigura);
    }
}

// FIXME nao esquecer tirar os print
vector<Point>
readPoints(string fileName)
{
    float x, y, z;
    vector<Point> points;
    ifstream file(fileName);
    // printf("fileName: %s", fileName.c_str());
    while (file >> x >> y >> z)
    {
        points.push_back(Point(x, y, z));

        // printf("floats: %4.2f %4.2f %4.2f \n", x, y, z);
    }

    return points;
}

void drawTriangle(Point p1, Point p2, Point p3)
{
    glColor3f((float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX);
    glBegin(GL_TRIANGLES);
    glVertex3f(p1.getX(), p1.getY(), p1.getZ());
    glVertex3f(p2.getX(), p2.getY(), p2.getZ());
    glVertex3f(p3.getX(), p3.getY(), p3.getZ());
    glEnd();
}

void draw_model(vector<string> filesRead)
{
    for (int i = 0; i < filesRead.size(); ++i)
    {
        // printf("readFile: %s", filesRead[0].c_str());
        vector<Point> points = readPoints(filesRead[i]);

        for (int i = 0; i < points.size(); i += 3)
            drawTriangle(points[i], points[i + 1], points[i + 2]);
    }
}

void draw_axis()
{
    glBegin(GL_LINES);
    // X axis in red
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(100.0f, 0.0f, 0.0f);
    // Y Axis in Green
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 100.0f, 0.0f);
    // Z Axis in Blue
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 100.0f);
    glEnd();
}

void changeSize(int w, int h)
{

    // Prevent a divide by zero, when window is too short
    // (you cant make a window with zero width).
    if (h == 0)
        h = 1;

    // compute window's aspect ratio
    float ratio = w * 1.0 / h;

    // Set the projection matrix as current
    glMatrixMode(GL_PROJECTION);
    // Load Identity Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set perspective
    gluPerspective(fov, ratio, near, far);

    // return to the model view matrix mode
    glMatrixMode(GL_MODELVIEW);
}

void renderScene(void)
{
    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set the camera
    glLoadIdentity();

    // radius * cos(betha) * sin(alpha), radius * sin(betha), radius * cos(betha) * cos(alpha)
    // positionX, positionY, positionZ,

    gluLookAt(radius * cos(betha) * sin(alpha), radius * sin(betha), radius * cos(betha) * cos(alpha),
              lookAtX, lookAtY, lookAtZ,
              upX, upY, upZ);
    glPolygonMode(GL_FRONT_AND_BACK, mode);

    // draw xyz
    draw_axis();

    // put the geometric transformations here
    glTranslated(tx, 0.0, tz);
    glRotated(angle, 0.0, 1.0, 0.0);
    glScalef(scalex, scaley, scalez);

    // draw model
    draw_model(readModels);

    // End of frame
    glutSwapBuffers();
}

// write function to process keyboard events
void reactKey(unsigned char key, int x, int y)
{
    switch (key)
    {
    case '1':
        mode = GL_FILL;
        break;
    case '2':
        mode = GL_LINE;
        break;
    case '3':
        mode = GL_POINT;
        break;
    case 'h':
        angle += 2;
        break;

    case 'l':
        angle -= 2;
        break;

    case 'w':
        tz += 0.1;
        break;

    case 's':
        tz -= 0.1;
        break;

    case 'd':
        tx += 0.1;
        break;

    case 'a':
        tx -= 0.1;
        break;

    case 'k':
        scaley += 0.1;
        break;

    case 'j':
        scaley -= 0.1;
        break;

    case 'q': // voltar ao ponto inicial
        angle = 0;
        tz = 0.1;
        tx = 0.1;
        scaley = 1.0;
        mode = GL_FILL;
        break;
    }

    glutPostRedisplay();
}

void onKeyboard(int key_code, int x, int y)
{
    if (key_code == GLUT_KEY_RIGHT)
    {
        alpha += M_PI / 16;
        glutPostRedisplay();
    }
    else if (key_code == GLUT_KEY_LEFT)
    {
        alpha -= M_PI / 16;
        glutPostRedisplay();
    }
    else if (key_code == GLUT_KEY_UP)
    {

        betha += M_PI / 16;
        glutPostRedisplay();
    }
    else if (key_code == GLUT_KEY_DOWN)
    {
        betha -= M_PI / 16;
        glutPostRedisplay();
    }

    if (alpha < 0)
        alpha += M_PI * 2;

    else if (alpha > M_PI * 2)
        alpha -= M_PI * 2;

    if (betha < -M_PI)
        betha += M_PI * 2;

    else if (betha > M_PI)
        betha -= M_PI * 2;
}

int main(int argc, char **argv)
{

    modelFileName = argv[1];

    readFile(modelFileName);
    // printf("x = %f  y = %f   z = %f\n", stof(lookAtX.c_str()),stof(lookAtY.c_str()),stof(lookAtZ.c_str()));
    // printf("x = %f   y = %f   z = %f\n", stof(upX.c_str()),stof(upY.c_str()),stof(upZ.c_str()));
    // printf("position x = %f  y = %f   z = %f\n",positionX,positionY,positionZ);
    // printf("look x = %f  y = %f   z = %f\n",lookAtX,lookAtY,lookAtZ);
    // printf("up x = %f   y = %f   z = %f\n", upX,upY,upZ);
    // printf("fov = %f near = %f far = %f \n",fov,near,far);

    // init GLUT and the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("CG@DI-UM");

    // Required callback registry
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);

    // put here the registration of the keyboard callbacks
    glutKeyboardFunc(reactKey);
    glutSpecialFunc(onKeyboard);

    //  OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    // enter GLUT's main cycle
    glutMainLoop();

    return 1;
}
