#include "headers/tinyxml2.hpp"
#include "headers/tree.hpp"


vector<Point>* readPoints(const char * fileName)
{
    float x, y, z;
    vector<Point>* points = new vector<Point>();
    ifstream file(fileName);

    while (file >> x >> y >> z)
    {
        points->push_back(Point(x, y, z));

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

void Tree::printGroup(){
    group.printModels();
}

void Group::printModels(){
    models.printFigures();

}

void Models::printFigures(){



    printf("figures size:%d\n",figures->size());

    for(int i = 0; i < figures->size(); i++){

        figures->at(i).printPoints();

    }

    printf("---------------------------------\n");
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

    printf("radius %f,betha %f, alpha %f, lookx %f, looky %f, lookz %f, upX %f, upY %f, upZ %f, sfov %f, near %f, far %f",positionX,positionY,positionZ,lookAtPoint.getX(),lookAtPoint.getY(),lookAtPoint.getZ(),upPoint.getX(),upPoint.getY(),upPoint.getZ(),fov,near,far);


    Camera camera = Camera(alpha, beta, radius, upPoint, lookAtPoint, fov, near, far);

    return camera;
}

Transform::Transform(Coordinate myTranslate, Coordinate myRotate, Coordinate myScale)
{
    translate = myTranslate;
    rotate = myRotate;
    scale = myScale;
}


Transform::Transform()
{
    hasRotate = false;
    hasTranslate = false;
    hasScale = false;
    translate = Coordinate();
    rotate = Coordinate();
    scale = Coordinate();
}


Models::Models(){
    //intialize de vector without anything
    figures = new vector<Figure>();
}




Models::Models(vector<Figure>* myFigures){

    for (int i=0; myFigures->size(); i++){
        figures->push_back(myFigures->at(i));
    }

}


Figure::Figure(const char * myName){

    points = readPoints(myName);


}

Figure::Figure(vector<Point>* myPoints){

    points = myPoints;

}


void Figure::printPoints(){


    for (int i=0; i<points->size(); i++){

        printf("Ponto x: %f\n",points->at(i).getX());
    }
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
            printf("entrei no translate");
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
        else if (!strcmp(type->Value(), "rotate"))
        {
            float angle, x, y, z;
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
            t.rotate = Coordinate(x, y, z, angle);
            t.hasRotate = true;
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

            m.figures->push_back(Figure(type->ToElement()->Attribute("file")));
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

        printf("type:%s\n",type->Value());

        if (!strcmp(type->Value(), "transform"))
        {
            printf("transform\n");
            transform = parseTransform(type);
        }
        else if (!strcmp(type->Value(), "models"))
        {
            printf("models\n");
            models = modelsParser(type);
        }
        else if (!strcmp(type->Value(), "group"))
        {
            printf("group parser\n");
            groups.push_back(groupParser(type));
        }

        type = type->NextSibling();
    }


    Group g = Group(groups, models,transform);

    return g;
}

Tree readFile(char *filename)
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

    Camera camera = readCamera(pRoot);

    pRoot = pRoot->FirstChildElement("group");

    Group group = groupParser(pRoot);

    return Tree(group,camera);
}

