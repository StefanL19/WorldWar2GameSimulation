
#ifndef TankDivision_hpp
#define TankDivision_hpp

#include <stdio.h>
#include "MotorizedDivision.hpp"
using namespace std;

class TankDivision : public MotorizedDivision
{
private:
    int numberOfTanks;
public:
    TankDivision(string name, string commander, ParticipatingCountries country, int numberOfSoldiers, int numberOfCars, int numberOfMotors, int numberOfTanks);
    
    void attack(Division &opponent) override;
    void attackedBy(Division& opponent) override;
    void attackedBy(MotorizedDivision &opponent) override;
    void attackedBy(TankDivision& opponent) override;
};
#endif /* TankDivision_hpp */
