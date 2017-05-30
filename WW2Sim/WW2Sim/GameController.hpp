
#ifndef GameController_hpp
#define GameController_hpp

#include <stdio.h>
#include "Enums.h"
#include "Army.hpp"
#include "TankDivision.hpp"
#include "Battle.hpp"
#include <vector>
class GameController
{
private:
    Battles battleChoice;
    Battle battle;
public:
    GameController(){};
    void chooseBattle();
    void listBattleStory();
    void generateBattleTroops();
    void generateWiznaTroops();
	void generateStalingradTroops();
	void listDivisionsByPower(std::vector<Division *> alliesDivisions, std::vector<Division *> wehrmachtDivisions);
};
#endif /* GameController_hpp */
