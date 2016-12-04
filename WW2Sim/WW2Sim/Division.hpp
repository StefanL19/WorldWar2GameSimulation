
#ifndef Division_hpp
#define Division_hpp

#include <stdio.h>
#include <string>
#include "Enums.h"
//#include "Battle.hpp"

// Derived classes
class Division;
class MotorizedDivision;
class TankDivision;


class Division
{
private:
    std::string name;
    std::string commander;
    ParticipatingCountries country;
    int numberOfSoldiers;
	bool isDefeated;
    int currentRow;
    int currentCol;
public:
    Division(std::string name, std::string commander, ParticipatingCountries country, int numberOfSoldiers);
    virtual void attack(Division& opponent);
    bool getIsDefeated();
	std::string getCommander();
    void setIsDefeated(bool isDefeated);
    virtual void attackedBy(Division& opponent);
    virtual void attackedBy(MotorizedDivision& opponent);
	virtual void attackedBy(TankDivision& opponent); 
	virtual double getDivisionPower();
    ParticipatingCountries getDivisionCountry();
    DivisionLocations getLocation();
	std::string getName();
	int getNumberOfSoldiers();
    //void setDivisionPosition(Battle &battle);
};
#endif /* Division_hpp */
