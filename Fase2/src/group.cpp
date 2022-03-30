#include "headers/tinyxml2.hpp"
#include "headers/group.hpp"

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

Camera::Camera(float myAlpha, float myBeta, float myRadius, Point myUp, Point myLookAt, float myFov, float myNear, float myFar)
{
    float alpha = myAlpha;
    float beta = myBeta;
    float radius = myRadius;
    Point up = myUp;
    Point lookAt = myLookAt;
    float fov = myFov;
    float near = myNear;
    float far = myFar;
    Point scale = Point(1.0, 1.0, 1.0);
}

Group::Group(vector<Group> myGroups, Models myModels)
{
    groups = myGroups;
    models = myModels;
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

Transform::Transform(Coordinate myTranslate, Coordinate myRotate, Coordinate myScale)
{
    translate = myTranslate;
    rotate = myRotate;
    scale = myScale;
}


Transform::Transform()
{
    translate = Coordinate();
    rotate = Coordinate();
    scale = Coordinate();
}


Models::Models(){
    figures = vector<Figure>();     //intialize de vector without anything
}


Models::Models(vector<Figure> myFigures){
    figures = myFigures;
}


Figure::Figure(string myName){
    name = myName;
}


Transform parseTransform(tinyxml2::XMLNode *pRoot)
{
    Coordinate translate, rotate, scale;

    tinyxml2::XMLNode *type = pRoot->FirstChild();

    while (type)
    {
        if (!strcmp(type->Value(), "translate"))
        {
            float x, y, z;
            if (type->ToElement()->Attribute("X"))
                x = std::stof(type->ToElement()->Attribute("X"));
            else
                x = 0;
            if (type->ToElement()->Attribute("Y"))
                y = std::stof(type->ToElement()->Attribute("Y"));
            else
                y = 0;
            if (type->ToElement()->Attribute("Z"))
                z = std::stof(type->ToElement()->Attribute("Z"));
            else
                z = 0;
            translate = Coordinate(x, y, z, 0);
        }
        else if (!strcmp(type->Value(), "rotate"))
        {
            float angle, x, y, z;
            if (type->ToElement()->Attribute("angle"))
                angle = std::stof(type->ToElement()->Attribute("angle"));
            else
                angle = 0;
            if (type->ToElement()->Attribute("X"))
                x = std::stof(type->ToElement()->Attribute("X"));
            else
                x = 0;
            if (type->ToElement()->Attribute("Y"))
                y = std::stof(type->ToElement()->Attribute("Y"));
            else
                y = 0;
            if (type->ToElement()->Attribute("Z"))
                z = std::stof(type->ToElement()->Attribute("Z"));
            else
                z = 0;
            rotate = Coordinate(x, y, z, angle);
        }
        else if (!strcmp(type->Value(), "scale"))
        {
            float x, y, z;
            if (type->ToElement()->Attribute("X"))
                x = std::stof(type->ToElement()->Attribute("X"));
            else
                x = 0;
            if (type->ToElement()->Attribute("Y"))
                y = std::stof(type->ToElement()->Attribute("Y"));
            else
                y = 0;
            if (type->ToElement()->Attribute("Z"))
                z = std::stof(type->ToElement()->Attribute("Z"));
            else
                z = 0;
            scale = Coordinate(x, y, z);
        }

        type = type->NextSibling();
    }

    return Transform(translate, rotate, scale);
}



Models modelsParser(tinyxml2::XMLNode *models)
{
    std::vector<Figure> figures = std::vector<Figure>();
    tinyxml2::XMLNode *type = models->FirstChild();

    while (type)
    {
        if (!strcmp(type->Value(), "model"))
            figures.push_back(Figure(type->ToElement()->Attribute("file")));
        type = type->NextSibling();
    }
    return Models(figures);    //criar construtor
}

Group groupParser(tinyxml2::XMLNode *pRoot)
{

    vector<Group> groups;
    Models models;

    tinyxml2::XMLNode *type = pRoot->FirstChild();
    while (type)
    {
        if (!strcmp(type->Value(), "transform"))
        {
            Transform transform = parseTransform(type);
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

    return Group(groups, models);
}

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

    Camera camera = readCamera(pRoot);
    Group group = groupParser(pRoot);
}



int main(int argc, char **argv)
{
    readFile("/home/josejoao/Universidade/3ano/2 Semestre/CG/CG_Project/Ficheiros_Stor/teste.xml");

}