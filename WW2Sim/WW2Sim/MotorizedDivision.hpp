
#ifndef MotorizedDivision_hpp
#define MotorizedDivision_hpp

#include <stdio.h>
#include <string>
#include "Division.hpp"


class MotorizedDivision : public Division
{
private:
    int numberOfCars;
    int numberOfMotors;
    int fuel;
    
public:
    
    MotorizedDivision(std::string name, std::string commander, ParticipatingCountries country, int numberOfSoldiers, int numberOfCars, int numberOfMotors);
    
    void attack(Division &opponent) override;
    void attackedBy(Division& opponent) override;
    void attackedBy(MotorizedDivision &opponent) override;
    void attackedBy(TankDivision& opponent) override;
	double getDivisionPower() override;
	int getNumberOfCars();
	int getNumberOfMotors();
    
};
#endif /* MotorizedDivision_hpp */
