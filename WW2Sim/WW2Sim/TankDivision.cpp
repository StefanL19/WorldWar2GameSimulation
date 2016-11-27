
#include "TankDivision.hpp"
using namespace std;

TankDivision::TankDivision(string name, string commander, ParticipatingCountries country, int numberOfSoldiers, int numberOfCars, int numberOfMotors,  int numberOfTanks):MotorizedDivision(name, commander, country, numberOfSoldiers, numberOfCars,numberOfMotors)
{
    this->numberOfTanks = numberOfTanks;
}

void TankDivision::attack(Division &opponent){ opponent.attackedBy(*this);}
void TankDivision::attackedBy(Division& opponent){  }
void TankDivision::attackedBy(MotorizedDivision &opponent){  }
void TankDivision::attackedBy(TankDivision &opponent){  }

