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


//catmull rom stuff
float prev_y[3] = {0,1,0};
int POINT_COUNT = 0;
float t = 0.000f;
float rot_angle = 0;

void buildRotMatrix(float *x, float *y, float *z, float *m) {

	m[0] = x[0]; m[1] = x[1]; m[2] = x[2]; m[3] = 0;
	m[4] = y[0]; m[5] = y[1]; m[6] = y[2]; m[7] = 0;
	m[8] = z[0]; m[9] = z[1]; m[10] = z[2]; m[11] = 0;
	m[12] = 0; m[13] = 0; m[14] = 0; m[15] = 1;
}




float length(float *v) {

	float res = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
	return res;

}


void multMatrixVector(float *m, float *v, float *res) {

	for (int j = 0; j < 4; ++j) {
		res[j] = 0;
		for (int k = 0; k < 4; ++k) {
			res[j] += v[k] * m[j * 4 + k];
		}
	}

}

void cross(Point *a, Point *b, Point * res) {

    res->setX(a->getY() * b->getZ() - a->getZ()*b->getY());
    res->setY(a->getZ() * b->getX() - a->getX()*b->getZ());
    res->setZ(a->getX() * b->getY() - a->getY()*b->getX());
}

void normalize(Point *a) {

	float l = sqrt(a->getX() * a -> getX() + a->getY() * a->getY() + a->getZ() * a->getZ());
    a->setX(a->getX()/l);
    a->setY(a->getY()/l);
    a->setZ(a->getZ()/l);
}




void getCatmullRomPoint(float t, Point p0, Point p1, Point p2, Point p3, Point *pos, Point *deriv) {

	// catmull-rom matrix
	float m[4][4] = {	{-0.5f,  1.5f, -1.5f,  0.5f},
						{ 1.0f, -2.5f,  2.0f, -0.5f},
						{-0.5f,  0.0f,  0.5f,  0.0f},
						{ 0.0f,  1.0f,  0.0f,  0.0f}};

    //point x
    float p[4], a[4];
    p[0] = p0.getX();
    p[1] = p1.getX();
    p[2] = p2.getX();
    p[3] = p3.getX();
    
    // Compute A = M * P
	multMatrixVector((float *)m, p, a);
	// Compute pos = T * A -> pos[i] = at?? + bt?? + ct + d
	pos->setX(powf(t,3.0) * a[0] + powf(t,2.0) * a[1] + t * a[2] + a[3]);
	// compute deriv = T' * A -> pos[i] = 3 at?? + 2bt + c
	deriv->setX(3 * powf(t, 2.0) * a[0] + 2 * t * a[1] + a[2]);

    //point y
    p[0] = p0.getY();
    p[1] = p1.getY();
    p[2] = p2.getY();
    p[3] = p3.getY();
    
    // Compute A = M * P
	multMatrixVector((float *)m, p, a);
	// Compute pos = T * A -> pos[i] = at?? + bt?? + ct + d
	pos->setY(powf(t,3.0) * a[0] + powf(t,2.0) * a[1] + t * a[2] + a[3]);
	// compute deriv = T' * A -> pos[i] = 3 at?? + 2bt + c
	deriv->setY(3 * powf(t, 2.0) * a[0] + 2 * t * a[1] + a[2]);

    //point z
    p[0] = p0.getZ();
    p[1] = p1.getZ();
    p[2] = p2.getZ();
    p[3] = p3.getZ();
       // Compute A = M * P
	multMatrixVector((float *)m, p, a);
	// Compute pos = T * A -> pos[i] = at?? + bt?? + ct + d
	pos->setZ(powf(t,3.0) * a[0] + powf(t,2.0) * a[1] + t * a[2] + a[3]);
	// compute deriv = T' * A -> pos[i] = 3 at?? + 2bt + c
	deriv->setZ(3 * powf(t, 2.0) * a[0] + 2 * t * a[1] + a[2]);
	
	
	// Compute A = M * P
	multMatrixVector((float *)m, p, a);
	// Compute pos = T * A -> pos[i] = at?? + bt?? + ct + d
	pos->setZ(powf(t,3.0) * a[0] + powf(t,2.0) * a[1] + t * a[2] + a[3]);
	
	// compute deriv = T' * A -> pos[i] = 3 at?? + 2bt + c
	deriv->setZ(3 * powf(t, 2.0) * a[0] + 2 * t * a[1] + a[2]);
}



// given  global t, returns the point in the curve
void getGlobalCatmullRomPoint(float gt, Point *pos, Point *deriv, CatmullRom catR) {
    int POINT_COUNT = catR.points.size();
	float t = gt * POINT_COUNT; // this is the real global t
	int index = floor(t);  // which segment
	t = t - index; // where within  the segment

	// indices store the points
	int indices[4]; 
	indices[0] = (index + POINT_COUNT-1)%POINT_COUNT;	
	indices[1] = (indices[0]+1)%POINT_COUNT;
	indices[2] = (indices[1]+1)%POINT_COUNT; 
	indices[3] = (indices[2]+1)%POINT_COUNT;

	getCatmullRomPoint(t, catR.points[indices[0]], catR.points[indices[1]], catR.points[indices[2]], catR.points[indices[3]], pos, deriv);
}


void renderCatmullRomCurve(CatmullRom catR) {
	// draw curve using line segments with GL_LINE_LOOP

    Point* pos = new Point();
    Point* deriv = new Point();
    glBegin(GL_LINE_LOOP);
    for (float gt = 0; gt <= 1; gt += 0.001) {
        getGlobalCatmullRomPoint(gt, pos, deriv, catR);
        glColor3f(0.8,0,0.15);
        glVertex3f(pos->getX(), pos->getY(), pos->getZ());
    }
    glEnd();

}


void renderRotate(Coordinate rotate){
    float time = glutGet(GLUT_ELAPSED_TIME);
    float angle = (((time / 1000) * 360) / rotate.value) - rot_angle;
    glRotatef(angle, rotate.x, rotate.y, rotate.z);
    rot_angle = angle;
}

//END OF CATMULL ROM STUFF


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

    float angle = group.transform.rotate.value;
    float rx = group.transform.rotate.x;
    float ry = group.transform.rotate.y;
    float rz = group.transform.rotate.z;
 

    float sx = group.transform.scale.x;
    float sy = group.transform.scale.y;
    float sz = group.transform.scale.z;


     
    Point* pos = new Point();
    Point* deriv = new Point();


    if (group.transform.catmullRom.points.size() != 0){
        
        renderCatmullRomCurve(group.transform.catmullRom);   

        float gt = ((float) glutGet(GLUT_ELAPSED_TIME) / 1000) / (float)(group.transform.catmullRom.time);
        
        getGlobalCatmullRomPoint(gt, pos, deriv, group.transform.catmullRom);
        
        glTranslatef(pos->getX(), pos->getY(), pos->getZ());
        

        if(group.transform.catmullRom.align){
            Point * up = new Point(0,1,0);
            Point * derivCross = new Point(); 
            normalize(deriv);
            cross(deriv, up, derivCross);
            normalize(derivCross);
            cross(derivCross, deriv, up);
            normalize(up);
            float m[4][4] = {{deriv->getX(),      deriv->getY(),      deriv->getZ(),      0},
                          {up->getX(),         up->getY(),         up->getZ(),         0},
                          {derivCross->getX(), derivCross->getY(), derivCross->getZ(), 0},
                          {0,        0,        0,        1}};
            glMultMatrixf((float *) m);
        }
    }



    if(group.transform.hasRotate) glRotatef(angle,rx,ry,rz);
    if(group.transform.hasTranslate) glTranslatef(tx,ty,tz);
    if(group.transform.hasScale) glScalef(sx,sy,sz);

    if(group.transform.hasTime) renderRotate(group.transform.rotate);
   
  


    for(int i = 0; i < group.models.figures.size();i++) {
        draw_model(group.models.figures[i]);
    }

    if(group.transform.hasTime) renderRotate(group.transform.rotate);

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

    t += 0.001;

    
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


    
    // Required callback registry
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);
	
	glEnableClientState(GL_VERTEX_ARRAY);
    
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
