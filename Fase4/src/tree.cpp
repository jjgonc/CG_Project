#include "headers/tinyxml2.hpp"
#include "headers/tree.hpp"

#include <IL/il.h>

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
    value = myAngle;
}

Coordinate::Coordinate(float x1, float y2, float z2)
{
    x = x1;
    y = y2;
    z = z2;
    value = 0;
}

Coordinate::Coordinate()
{
    x = 0.0;
    y = 0.0;
    z = 0.0;
    value = 0;
}




Light::Light(bool my_isPoint, bool my_isDirectional, bool my_isSpotlight, float my_posX, float my_posY, float my_posZ, bool my_hasPosX, bool my_hasPosY, bool my_hasPosZ, float my_dirX, float my_dirY, float my_dirZ, bool my_hasDirX, bool my_hasDirY, bool my_hasDirZ, float my_cutoff, bool my_hasCutoff){
    isPoint = my_isPoint;
    isDirectional = my_isDirectional;
    isSpotlight = my_isSpotlight;
    posX = my_posX;
    posY = my_posY;
    posZ = my_posZ;
    hasPosX = my_hasPosX;
    hasPosY = my_hasPosY;
    hasPosZ = my_hasPosZ;
    dirX = my_dirX;
    dirY = my_dirY;
    dirZ = my_dirZ;
    hasDirX = my_hasDirX;
    hasDirY = my_hasDirY;
    hasDirZ = my_hasDirZ;
    cutoff = my_cutoff;
    hasCutoff = my_hasCutoff;
}


Lights::Lights(){
    lights = vector<Light>();
}

Lights::Lights(vector<Light> lightsVector){
    lights = lightsVector;
}

Lights readLights(tinyxml2::XMLNode *pRoot){
    std::vector<Light> lights_Vector = std::vector<Light>();
    
    // tinyxml2::XMLElement *lightElem = pRoot->FirstChildElement("lights");

    tinyxml2::XMLNode *lights = pRoot->FirstChild();

    while(lights) {

        if(!strcmp(lights->Value(), "light")){

            bool isPoint, isSpotlight, isDirectional;
            isPoint = isSpotlight = isDirectional = false;
            if (lights->ToElement()->Attribute("type")){
                char* type = (char*) lights->ToElement()->Attribute("type");


                bool isPoint, isDirectional, isSpotlight;
                if (!strcmp(type, "point")){
                    isPoint = true;
                    isDirectional = false;
                    isSpotlight = false;
                }
                else if (strcmp(type, "directional") == 0){
                    isPoint = false;
                    isSpotlight = true;
                    isDirectional = true;
                }
                else if(!strcmp(type, "spotlight")){
                    isPoint = false;
                    isDirectional = false;
                    isSpotlight = true;
                }
                else{
                    printf("Error! Light type is not supported");
                    exit(1);
                }
            }

            float posX, posY, posZ, dirX, dirY, dirZ, cutoff;
            bool hasPosX, hasPosY, hasPosZ, hasDirX, hasDirY, hasDirZ, hasCutoff;
            hasPosX = hasPosY = hasPosZ = hasDirX = hasDirY = hasDirZ = hasCutoff = false;

            if (lights->ToElement()->Attribute("posx")){
                posX = std::stof(lights->ToElement()->Attribute("posx"));
                hasPosX = true;
            }

            if (lights->ToElement()->Attribute("posy")){
                posY = std::stof(lights->ToElement()->Attribute("posy"));
                hasPosY = true;
            }

            if (lights->ToElement()->Attribute("posz")){
                posZ = std::stof(lights->ToElement()->Attribute("posz"));
                hasPosZ = true;
            }

            if (lights->ToElement()->Attribute("dirx")){
                dirX = std::stof(lights->ToElement()->Attribute("dirx"));
                hasDirX = true;
            }
            if (lights->ToElement()->Attribute("diry")){
                dirY = std::stof(lights->ToElement()->Attribute("diry"));
                hasDirY = true;
            }
            if (lights->ToElement()->Attribute("dirz")){
                dirZ = std::stof(lights->ToElement()->Attribute("dirz"));
                hasDirZ = true;
            }

            if (lights->ToElement()->Attribute("cutoff")){
                cutoff = std::stof(lights->ToElement()->Attribute("cutoff"));
                hasCutoff = true;
            }

            Light light = Light(isPoint, isDirectional, isSpotlight, posX, posY, posZ, hasPosX, hasPosY, hasPosZ, dirX, dirY, dirZ, hasDirX, hasDirY, hasDirZ, cutoff, hasCutoff);

            lights_Vector.push_back(light);
        }

        lights = lights->NextSibling();
    }

    printf("size of lights vector: %ld\n", lights_Vector.size());

    printf("%d, %f, %d\n", lights_Vector.at(0).isDirectional, lights_Vector.at(0).dirX, lights_Vector.at(0).hasDirX);

    return lights_Vector;
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
    points = std::vector<Point>();
    time = 0.0f;
    align = false;
}

//Construtor parametrizado de CatmullRom
CatmullRom::CatmullRom(std::vector<Point> nPoints, float myTime, bool myAlign){
    points = nPoints;
    time = myTime;
    align = myAlign;
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


string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

int loadTexture(string s) {
    unsigned int t, tw, th;
    unsigned char *texData;
    unsigned int texID;

    // Iniciar o DevIL
    ilInit();

    // Colocar a origem da textura no canto inferior esquerdo
    ilEnable(IL_ORIGIN_SET);
    ilOriginFunc(IL_ORIGIN_LOWER_LEFT);

    // Carregar a textura para memória
    ilGenImages(1,&t);
    ilBindImage(t);
    ilLoadImage((ILstring)s.c_str());
    tw = ilGetInteger(IL_IMAGE_WIDTH);
    th = ilGetInteger(IL_IMAGE_HEIGHT);

    ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
    texData = ilGetData();

    //Gerar a textura para a placa gráfica
    glGenTextures(1,&texID);

    glBindTexture(GL_TEXTURE_2D,texID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    //Upload dos dados da imagem
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, tw, th, GL_RGBA, GL_UNSIGNED_BYTE, texData);

    glBindTexture(GL_TEXTURE_2D, 0);

    return texID;
}


Figure::Figure(const char * myName, const char * textureAtrib){

    char generated_path[40] = "../../vertices/";
    strcat(generated_path, myName);


    if(strcmp(textureAtrib,"nothing") != 0){

        

        char textureName[40] = "../../textures/";
        strcat(textureName, textureAtrib);


        int size = sizeof(textureName) / sizeof(char);
        string textureSTR = convertToString(textureName, size); 
        
        texture = loadTexture(textureSTR);
    }
    

    //points

    int numberPoints;
    float x, y, z;
    vector<Point> points = vector<Point>();
    ifstream file(generated_path);

    file >> numberPoints;

    int n = 0;

    // printf("%d\n",numberPoints);

    while (n < numberPoints)
    {
        file >> x >> y >> z;
        points.push_back(Point(x, y, z));

        //printf("%d point %f %f %f\n",n,x,y,z);
        n++;

    }

    vector<float> pointsXYZ = vector<float>();

    for(int i = 0; i < points.size(); i++){
        pointsXYZ.push_back(points[i].getX());
        pointsXYZ.push_back(points[i].getY());
        pointsXYZ.push_back(points[i].getZ());

        
    
    }

    //ler normais

    vector<Point> normals = vector<Point>();

    n = 0;

    while (n < numberPoints)
    {
        file >> x >> y >> z;
        normals.push_back(Point(x, y, z));
        n++;

        // printf("%d normal %f %f %f\n",n,x,y,z);

    }


    vector<float> normalsXYZ = vector<float>();

    for(int i = 0; i < points.size(); i++){
        normalsXYZ.push_back(points[i].getX());
        normalsXYZ.push_back(points[i].getY());
        normalsXYZ.push_back(points[i].getZ());

       
    }

    //ler coords
  
    vector<Point> textCoords = vector<Point>();
    
    n = 0;

    while (n < numberPoints)
    {
        file >> x >> y;
        textCoords.push_back(Point(x, y, 0));
        n++;

        // printf("%d coord %f %f \n",n,x,y);
    }

    vector<float> coordsXYZ = vector<float>();

    for(int i = 0; i < points.size(); i++){
        coordsXYZ.push_back(points[i].getX());
        coordsXYZ.push_back(points[i].getY());
    }


    verticesCount = points.size();


    glGenBuffers(3, buffers);

    glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * pointsXYZ.size(), pointsXYZ.data(), GL_STATIC_DRAW);
    

    glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * normalsXYZ.size(), normalsXYZ.data(), GL_STATIC_DRAW);


    glBindBuffer(GL_ARRAY_BUFFER,buffers[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * coordsXYZ.size(), coordsXYZ.data(), GL_STATIC_DRAW);


   
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

                bool align = false;
                if (type->ToElement()->Attribute("align")){
                    char * align_str = (char *) type->ToElement()->Attribute("align");
                    
                    if (strcmp(align_str, "True") == 0) align = true;
                }

                
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
                }
                CatmullRom cat = CatmullRom(nPoints, time, align);      // TODO REVER ISTO
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

            bool hasTime = false;
            if(type->ToElement()->Attribute("time")){
                time = std::stof(type->ToElement()->Attribute("time"));
                t.hasTime = true;
                hasTime = true;
            }
            
            t.rotate = Coordinate(x, y, z, time);

            if(!hasTime){
                t.hasTime = false;
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

    const char * texture = "nothing";
    const char * modelName;

    while (type)
    {
        if (!strcmp(type->Value(), "model")){

        
            modelName = type->ToElement()->Attribute("file");
            

            tinyxml2::XMLNode *model = type -> FirstChild();

            while(model){
                
             if(!strcmp(model->Value(), "texture"))
                texture = model->ToElement()->Attribute("file");

            

                model = model->NextSibling();
            }

            m.figures.push_back(Figure(modelName,texture));
        }

            
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

    
    //Lights lights = readLights(pRoot->FirstChildElement("lights"));


    pRoot = pRoot->FirstChildElement("group");
    Group group = groupParser(pRoot);


    return Tree(group,camera);

}

