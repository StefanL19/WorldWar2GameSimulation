
#include "TankDivision.hpp"
using namespace std;

TankDivision::TankDivision(string name, string commander, ParticipatingCountries country, int numberOfSoldiers, int numberOfCars, int numberOfMotors,  int numberOfTanks):MotorizedDivision(name, commander, country, numberOfSoldiers, numberOfCars,numberOfMotors)
{
    this->numberOfTanks = numberOfTanks;
}

void TankDivision::attack(Division &opponent)
{
	this->attackedBy(opponent);
	opponent.attackedBy(*this);
}

void TankDivision::attackedBy(Division& opponent)
{
	double divisionPower = this->getDivisionPower();
	double opponentPower = opponent.getDivisionPower();
	if (divisionPower < opponentPower)
	{
		this->setIsDefeated(true);
	}
}
void TankDivision::attackedBy(MotorizedDivision &opponent)
{
	double divisionPower = this->getDivisionPower();
	double opponentPower = opponent.getDivisionPower();
	if (divisionPower < opponentPower)
	{
		this->setIsDefeated(true);
	}
}
void TankDivision::attackedBy(TankDivision &opponent)
{
	double divisionPower = this->getDivisionPower();
	double opponentPower = opponent.getDivisionPower();
	if (divisionPower < opponentPower)
	{
		this->setIsDefeated(true);
	}
}
double TankDivision::getDivisionPower()
{
	return this->getNumberOfSoldiers() * 1.7 + this->getNumberOfCars() * 2.1 + this->getNumberOfMotors() * 1.9 + this->numberOfTanks * 4;
}

