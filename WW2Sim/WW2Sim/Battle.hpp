
#ifndef Battle_hpp
#define Battle_hpp

#include <stdio.h>
#include <string>
#include "Army.hpp"


struct Point;
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
    Point printShortestPath(Point source, Point destination);
	void clashOfDivisions();
	Point getDivisionPosition(Division* division);
	void clashTwoDivisions(Division* division1, Division* division2);
	void moveDivision(Point currentPosition, Point nextPosition);
	void collideDivisions(Division* division1, Division* division2);
};
#endif /* Battle_hpp */
