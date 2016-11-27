
#ifndef Army_hpp
#define Army_hpp

#include <stdio.h>
#include <string>
#include "Enums.h"
#include "Division.hpp"
#include <vector>

using namespace std;

class Army
{
private:
    Sides side;
    string general;
    vector<Division*> divisions;
public:
    Army();
    Army(Sides side, string general);
    
    Army(Sides side, string general, vector<Division*> divisions);
    
    //Think about add division method
    
};
#endif /* Army_hpp */
