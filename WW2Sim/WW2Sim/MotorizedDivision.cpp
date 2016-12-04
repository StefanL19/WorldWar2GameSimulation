

#include "MotorizedDivision.hpp"
#include "TankDivision.hpp"
#include <string>
using namespace std;

MotorizedDivision::MotorizedDivision(string name, string commander, ParticipatingCountries country, int numberOfSoldiers, int numberOfCars, int numberOfMotors):Division(name, commander, country, numberOfSoldiers)
{
    this->numberOfCars = numberOfCars;
    this->numberOfMotors = numberOfMotors;
};

void MotorizedDivision::attack(Division &opponent)
{
	this->attackedBy(opponent);
	opponent.attackedBy(*this);
}
void MotorizedDivision::attackedBy(Division& opponent)
{
	double divisionPower = this->getDivisionPower();
	double opponentPower = opponent.getDivisionPower();
	if (divisionPower < opponentPower)
	{
		this->setIsDefeated(true);
	}
}
void MotorizedDivision::attackedBy(MotorizedDivision &opponent)
{
	double divisionPower = this->getDivisionPower();
	double opponentPower = opponent.getDivisionPower();
	if (divisionPower < opponentPower)
	{
		this->setIsDefeated(true);
	}
}
void MotorizedDivision::attackedBy(TankDivision &opponent)
{
	double divisionPower = this->getDivisionPower();
	double opponentPower = opponent.getDivisionPower();
	if (divisionPower < opponentPower)
	{
		this->setIsDefeated(true);
	}
}

double MotorizedDivision::getDivisionPower()
{
	return this->getNumberOfSoldiers() * 1.7 + this->getNumberOfCars() * 2.1 + this->getNumberOfMotors() * 1.9;
}

int MotorizedDivision::getNumberOfMotors()
{
	return this->numberOfMotors;
}

int MotorizedDivision::getNumberOfCars()
{
	return this->numberOfCars;
}