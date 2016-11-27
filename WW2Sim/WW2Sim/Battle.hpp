
#ifndef Battle_hpp
#define Battle_hpp

#include <stdio.h>
#include <string>
#include "Army.hpp"
class Battle
{
private:
    std::string battleName;
    Army* army1;
    Army* army2;
    Division* divisionMatrix[20][20] = {};
public:
    Battle();
    Battle(std::string battleName, Army& army1, Army& army2);
    std::string getBattleName();
    void setGeneralTroopsMatrix();
    void printGeneralTroopsmatrix();
    void alterDivisionMatrix(Division* division);
    void printShortestPath();
};
#endif /* Battle_hpp */
