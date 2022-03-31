#include <vector>
#include <stdio.h>






class coisas {
    public:
    std::vector<int> myFigures;
    
    
    coisas(){

    }


    coisas(std::vector<int> figures){
        myFigures = figures;
    }

};





coisas createCoisas(){

    coisas coisa = coisas();

    coisa.myFigures.push_back(100);


    return coisa;

}


coisas createCoisas2(){


    std::vector<int> figures;
    figures.push_back(300);

    coisas coisa = coisas(figures);


    return coisa;

}







int main(int argc, char **argv)
{
    
    coisas coisa = createCoisas2();


    printf("%d\n",coisa.myFigures[0]);



    return 1;
}