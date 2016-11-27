

#include "MotorizedDivision.hpp"
#include <string>
using namespace std;

MotorizedDivision::MotorizedDivision(string name, string commander, ParticipatingCountries country, int numberOfSoldiers, int numberOfCars, int numberOfMotors):Division(name, commander, country, numberOfSoldiers)
{
    this->numberOfCars = numberOfCars;
    this->numberOfMotors = numberOfMotors;
};

void MotorizedDivision::attack(Division &opponent){ opponent.attackedBy(*this);}
void MotorizedDivision::attackedBy(Division& opponent){  }
void MotorizedDivision::attackedBy(MotorizedDivision &opponent){  }
void MotorizedDivision::attackedBy(TankDivision &opponent){  }