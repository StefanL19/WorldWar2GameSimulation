
#include "Division.hpp"
using namespace std;

Division::Division(string name, string commander, ParticipatingCountries country, int numberOfSoldiers)
{
    this->name = name;
    this->commander = commander;
    this->country = country;
    this->numberOfSoldiers = numberOfSoldiers;
};

bool Division::getIsDefeated(){return this->isDefeated;}
void Division::setIsDefeated(bool isDefeated){this->isDefeated = isDefeated;}

void Division::attack(Division& opponent){ opponent.attackedBy(*this);}
void Division::attackedBy(Division& opponent){  }
void Division::attackedBy(MotorizedDivision& opponent){  }
void Division::attackedBy(TankDivision& opponent){  }

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