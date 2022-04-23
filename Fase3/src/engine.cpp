#include <math.h>
#include <cstdio>
#include <vector>
#include <string>
#include "headers/point.hpp"
#include "headers/tinyxml2.hpp"
#include "headers/tree.hpp"
#include "headers/engine.hpp"
#include <fstream>
#include <iostream>


using namespace std;
char *modelFileName;

int angle = 0;
float tx = 0.1;
float ty = 0.1;
float tz = 0.1;


vector<string> readModels;

Tree tree;

float radius;
float betha;  
float alpha; 
float lookAtX;
float lookAtY;
float lookAtZ; 
float upX;
float upY; 
float upZ;
 
float scalex = 1.0;
float scaley = 1.0;
float scalez = 1.0;

GLenum mode = GL_FILL;



bool navigationPosition = false;



void moveCamera(Point p){
    
   
    float positionX = radius * cos(betha) * sin(alpha);
    float positionY = radius * sin(betha);
    float positionZ = radius * cos(betha) * cos(alpha);
    
    positionX = positionX + p.getX();
    positionY = positionY + p.getY();
    positionZ = positionZ + p.getZ();     

    radius = sqrt(positionX * positionX + positionY * positionY + positionZ * positionZ);
    betha = atan2(positionY, positionX);
    alpha = acos(positionZ / radius);
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

void draw_model(Figure fig)
{


    glBindBuffer(GL_ARRAY_BUFFER, fig.vertices);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, fig.verticesCount);
        
}


void drawModels(Group group){
    
    float tx = group.transform.translate.x;
    float ty = group.transform.translate.y;
    float tz = group.transform.translate.z;


    float angle = group.transform.rotate.angle;
    float rx = group.transform.rotate.x;
    float ry = group.transform.rotate.y;
    float rz = group.transform.rotate.z;
 

    float sx = group.transform.scale.x;
    float sy = group.transform.scale.y;
    float sz = group.transform.scale.z;

    if(group.transform.hasRotate) glRotatef(angle,rx,ry,rz);
    if(group.transform.hasTranslate) glTranslatef(tx,ty,tz);
    if(group.transform.hasScale) glScalef(sx,sy,sz);


    for(int i = 0; i < group.models.figures.size();i++) {
        draw_model(group.models.figures[i]);
    }

    for(Group gs: group.groups){
        glPushMatrix();
        drawModels(gs);
        glPopMatrix();
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
    

    gluPerspective(tree.camera.fov, ratio, tree.camera.near, tree.camera.far);

    // return to the model view matrix mode
    glMatrixMode(GL_MODELVIEW);
}

void renderScene(void)
{
    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set the camera
    glLoadIdentity();


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
    glEnableClientState(GL_VERTEX_ARRAY);
    drawModels(tree.group);

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
        tz += 10;
        break;

    case 's':
        tz -= 10;
        break;

    case 'd':
        tx += 10;
        break;

    case 'a':
        tx -= 10;
        break;

    case 'r':
        radius += 10;
        break;

     case 'f':
     if(radius - 10 > 0){
         radius -= 10;
     }
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

    char xml_generated_path[40] = "../../xmlFiles/";
    strcat(xml_generated_path, modelFileName);
    

    

    // init GLUT and the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("CG@DI-UM");
    
    // Required callback registry
    glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	
	glEnableClientState(GL_VERTEX_ARRAY);
    
     // put here the registration of the keyboard callbacks
    glutKeyboardFunc(reactKey);
    glutSpecialFunc(onKeyboard);
    
    //  OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

#ifndef __APPLE__
    glewInit();
#endif

    
    
    tree = readFile(xml_generated_path);

    radius = tree.camera.radius;
    betha = tree.camera.beta;
    alpha = tree.camera.alpha;
    lookAtX = tree.camera.lookAt.getX();
    lookAtY = tree.camera.lookAt.getY();
    lookAtZ = tree.camera.lookAt.getZ();
    upX = tree.camera.up.getX();
    upY = tree.camera.up.getY();
    upZ = tree.camera.up.getZ();
    
    // enter GLUT's main cycle
    glutMainLoop();

    return 1;
}
