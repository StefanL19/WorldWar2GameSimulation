
#include "Division.hpp"
#include "MotorizedDivision.hpp"
#include "TankDivision.hpp"
using namespace std;

Division::Division(string name, string commander, ParticipatingCountries country, int numberOfSoldiers)
{
    this->name = name;
    this->commander = commander;
    this->country = country;
    this->numberOfSoldiers = numberOfSoldiers;
	this->isDefeated = false;
};

bool Division::getIsDefeated(){return this->isDefeated;}
void Division::setIsDefeated(bool isDefeated){this->isDefeated = isDefeated;}

void Division::attack(Division& opponent)
{
	this->attackedBy(opponent);
	opponent.attackedBy(*this);
}
void Division::attackedBy(Division& opponent)
{
	double divisionPower = this->getDivisionPower();
	double opponentPower = opponent.getDivisionPower();

	if (divisionPower < opponentPower)
	{
		this->isDefeated = true;
	}
}
void Division::attackedBy(MotorizedDivision& opponent)
{
	double divisionPower = this->getDivisionPower();
	double opponentPower = opponent.getDivisionPower();

	if (divisionPower < opponentPower)
	{
		this->isDefeated = true;
	}
}
void Division::attackedBy(TankDivision& opponent)
{
	double divisionPower = this->getDivisionPower();
	double opponentPower = opponent.getDivisionPower();
	if (divisionPower < opponentPower)
	{
		this->isDefeated = true;
	}
}

double Division::getDivisionPower()
{
	return this->numberOfSoldiers * 1.7;
}

ParticipatingCountries Division::getDivisionCountry()
{
    return this->country;
}

DivisionLocations Division::getLocation()
{
    return this->getLocation();
}

std::string Division::getName() 
{
	return this->name;
}

int Division::getNumberOfSoldiers()
{
	return this->numberOfSoldiers;
}
//void Division::setDivisionPosition(Battle& battle)
//{
//    switch (this->locationOnBattlefield) {
//        case <#constant#>:
//            <#statements#>
//            break;
//            
//        default:
//            break;
//    }
//}