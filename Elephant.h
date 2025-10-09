#ifndef ELEPHANT_H
#define ELEPHANT_H
#include "Fridge.h"
#include <string>  

class Elephant {
private:
    std::string name;  
public:
    Elephant(std::string n);
    void enterFridge(Fridge& fridge);
};

#endif
