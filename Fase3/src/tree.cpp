#include "headers/tinyxml2.hpp"
#include "headers/tree.hpp"


vector<Point> readPoints(const char * fileName)
{

    float x, y, z;
    vector<Point> points = vector<Point>();
    ifstream file(fileName);

    while (file >> x >> y >> z)
    {
        points.push_back(Point(x, y, z));

    }

    return points;
}




Tree::Tree(){
    group = Group();
    camera = Camera();
}

Tree::Tree(Group g, Camera cam){
    group = g;
    camera = cam;

}



Coordinate::Coordinate(float x1, float y2, float z2, float myAngle)
{
    x = x1;
    y = y2;
    z = z2;
    angle = myAngle;
}

Coordinate::Coordinate(float x1, float y2, float z2)
{
    x = x1;
    y = y2;
    z = z2;
    angle = 0;
}

Coordinate::Coordinate()
{
    x = 0.0;
    y = 0.0;
    z = 0.0;
    angle = 0;
}


Camera::Camera(){
    float alpha = 0;
    float beta = 0;
    float radius = 0;
    Point up = Point(1.0, 1.0, 1.0);
    Point lookAt = Point(1.0, 1.0, 1.0);
    float fov = 0;
    float near = 0;
    float far = 0;
    Point scale = Point(1.0, 1.0, 1.0);
}



Camera::Camera(float myAlpha, float myBeta, float myRadius, Point myUp, Point myLookAt, float myFov, float myNear, float myFar){

    alpha = myAlpha;
    beta = myBeta;
    radius = myRadius;
    up = myUp;
    lookAt = myLookAt;
    fov = myFov;
    near = myNear;
    far = myFar;
    scale = Point(1.0, 1.0, 1.0);
}


Group::Group(){

    groups = vector<Group>();
    models = Models();
    transform = Transform();

}


Group::Group(vector<Group> myGroups, Models myModels,Transform myTransform)
{
    groups = myGroups;

    models = myModels;

    transform = myTransform;


}

Models Group::getModels(){
    return models;
}

Camera readCamera(tinyxml2::XMLNode *pRoot)
{

    tinyxml2::XMLElement *position = pRoot->FirstChildElement("camera")->FirstChildElement("position");
    tinyxml2::XMLElement *lookAt = pRoot->FirstChildElement("camera")->FirstChildElement("lookAt");
    tinyxml2::XMLElement *up = pRoot->FirstChildElement("camera")->FirstChildElement("up");
    tinyxml2::XMLElement *projection = pRoot->FirstChildElement("camera")->FirstChildElement("projection");

    Point lookAtPoint = Point(stof(lookAt->Attribute("x")), stof(lookAt->Attribute("y")), stof(lookAt->Attribute("z")));
    Point upPoint = Point(stof(up->Attribute("x")), stof(up->Attribute("y")), stof(up->Attribute("z")));

    float fov = stof(projection->Attribute("fov"));
    float near = stof(projection->Attribute("near"));
    float far = stof(projection->Attribute("far"));

    float positionX = stof(position->Attribute("x"));
    float positionY = stof(position->Attribute("y"));
    float positionZ = stof(position->Attribute("z"));

    float radius = sqrt(positionX * positionX + positionY * positionY + positionZ * positionZ);
    float beta = atan2(positionY, positionX);
    float alpha = acos(positionZ / radius);



    Camera camera = Camera(alpha, beta, radius, upPoint, lookAtPoint, fov, near, far);

    return camera;
}

//Construtor vazio de CatmullRom
CatmullRom::CatmullRom(){
    time = 0;
    points = std::vector<Point>();
    isRotate = false;
    point = Point();
}

//Construtor parametrizado de CatmullRom
CatmullRom::CatmullRom(float nTime, std::vector<Point> nPoints, bool myIsRotate, Point myPoint){
    time = nTime;
    points = nPoints;
    isRotate = myIsRotate;
    point = myPoint;
}


Transform::Transform(Coordinate myTranslate, Coordinate myRotate, Coordinate myScale, CatmullRom myCatmullRom)
{
    translate = myTranslate;
    rotate = myRotate;
    scale = myScale;
    catmullRom = myCatmullRom;
}


Transform::Transform()
{
    hasRotate = false;
    hasTranslate = false;
    hasScale = false;
    isCatmullRom = false;
    translate = Coordinate();
    rotate = Coordinate();
    scale = Coordinate();
    catmullRom = CatmullRom();
}


Models::Models(){
    //intialize de vector without anything
    figures = vector<Figure>();
}




Models::Models(vector<Figure> myFigures){

    for (int i=0; myFigures.size(); i++){
        figures.push_back(myFigures.at(i));
    }

}


Figure::Figure(const char * myName){

    char generated_path[40] = "../../vertices/";
    strcat(generated_path, myName);
    vector<Point>  points = readPoints(generated_path);


    vector<float> pointsXYZ = vector<float>();

    for(int i = 0; i < points.size(); i++){
        pointsXYZ.push_back(points[i].getX());
        pointsXYZ.push_back(points[i].getY());
        pointsXYZ.push_back(points[i].getZ());
    }


    verticesCount = points.size();

    glGenBuffers(1,&vertices);
    glBindBuffer(GL_ARRAY_BUFFER, vertices);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * pointsXYZ.size(), pointsXYZ.data(),GL_STATIC_DRAW); 

}


Transform parseTransform(tinyxml2::XMLNode *pRoot)
{
    Coordinate translate, rotate, scale;

    tinyxml2::XMLNode *type = pRoot->FirstChild();
    Transform t = Transform();
    while (type)
    {
        if (!strcmp(type->Value(), "translate"))
        {
            if (type->ToElement()->Attribute("time")){
                std::vector<Point> nPoints = std::vector<Point>();
                float time = std::stof(type->ToElement()->Attribute("time"));

                
                //parse the points of the translation
                tinyxml2::XMLNode *type2 = type->FirstChild();   //todos os point que tem
                while(type2){

	            	if(!strcmp(type2->Value(), "point")){
	            		nPoints.push_back(Point(std::stof(type2->ToElement()->Attribute("x")),
                                                std::stof(type2->ToElement()->Attribute("y")),
                                                std::stof(type2->ToElement()->Attribute("z"))));
                    }
                    type2 = type2->NextSibling();
                }


                for(Point p : nPoints){
                    nPoints.push_back(p);
                    printf("x: %f, y:%f, z:%f\n", p.getX(), p.getY(), p.getZ());
                }
                CatmullRom cat = CatmullRom(time,nPoints, false, Point());      // TODO REVER ISTO
                t.catmullRom = cat;
            }

            else {
               float x, y, z;
            if (type->ToElement()->Attribute("x"))
                x = std::stof(type->ToElement()->Attribute("x"));
            else
                x = 0;
            if (type->ToElement()->Attribute("y"))
                y = std::stof(type->ToElement()->Attribute("y"));
            else
                y = 0;
            if (type->ToElement()->Attribute("z"))
                z = std::stof(type->ToElement()->Attribute("z"));
            else
                z = 0;
            t.translate = Coordinate(x, y, z, 0);
            t.hasTranslate = true; 
            }            
        }
        else if (!strcmp(type->Value(), "rotate"))
        {
            float angle, x, y, z, time;
            if (type->ToElement()->Attribute("angle"))
                angle = std::stof(type->ToElement()->Attribute("angle"));
            else
                angle = 0;
            if (type->ToElement()->Attribute("x"))
                x = std::stof(type->ToElement()->Attribute("x"));
            else
                x = 0;
            if (type->ToElement()->Attribute("y"))
                y = std::stof(type->ToElement()->Attribute("y"));
            else
                y = 0;
            if (type->ToElement()->Attribute("z"))
                z = std::stof(type->ToElement()->Attribute("z"));
            else
                z = 0;

            bool hasTime;
            if(type->ToElement()->Attribute("time")){
                time = std::stof(type->ToElement()->Attribute("time"));
                hasTime = true;
            }
            else
                time = 0;

            if(hasTime) {
                //criar nova cena no catmullrom que passa o point e o time
                printf("hasTime = true    x: %f, y:%f, z:%f\n", x,y,z);
                Point newPoint = Point(x, y, z);
                CatmullRom cat = CatmullRom(time, std::vector<Point>(), true, newPoint);      // TODO REVER ISTO
                t.catmullRom = cat;
            }
            else{
                printf("hasTime = false  x: %f, y:%f, z:%f\n", x,y,z);
                t.rotate = Coordinate(x, y, z, angle);
                t.hasRotate = true;
            }
        }
        else if (!strcmp(type->Value(), "scale"))
        {
            float x, y, z;
            if (type->ToElement()->Attribute("x"))
                x = std::stof(type->ToElement()->Attribute("x"));
            else
                x = 0;
            if (type->ToElement()->Attribute("y"))
                y = std::stof(type->ToElement()->Attribute("y"));
            else
                y = 0;
            if (type->ToElement()->Attribute("z"))
                z = std::stof(type->ToElement()->Attribute("z"));
            else
                z = 0;
            t.scale = Coordinate(x, y, z);
            t.hasScale = true;
        }


        type = type->NextSibling();
    }

    return t;
}



Models modelsParser(tinyxml2::XMLNode *models)
{
    Models m = Models();
    tinyxml2::XMLNode *type = models->FirstChild();

    while (type)
    {
        if (!strcmp(type->Value(), "model"))

            m.figures.push_back(Figure(type->ToElement()->Attribute("file")));
        type = type->NextSibling();
    }

    return m;
}

Group groupParser(tinyxml2::XMLNode *pRoot)
{


    vector<Group> groups;
    Models models;
    Transform transform;

    tinyxml2::XMLNode *type = pRoot->FirstChild();
    while (type)
    {


        if (!strcmp(type->Value(), "transform"))
        {

            transform = parseTransform(type);
        }
        else if (!strcmp(type->Value(), "models"))
        {
            models = modelsParser(type);
        }
        else if (!strcmp(type->Value(), "group"))
        {
            groups.push_back(groupParser(type));
        }

        type = type->NextSibling();
    }


    Group g = Group(groups, models,transform);

    return g;
}

Tree readFile(char *filename)
{

    tinyxml2::XMLDocument doc;
    doc.LoadFile(filename);
    if (doc.ErrorID())
    {
        printf("erro");
        exit(0);
    } // abre ficheiro XML
    


    tinyxml2::XMLNode *pRoot = doc.FirstChildElement("world");
    if (pRoot == nullptr)
         exit(0);


    

    Camera camera = readCamera(pRoot);

    pRoot = pRoot->FirstChildElement("group");

        

    Group group = groupParser(pRoot);


    return Tree(group,camera);

}

