
#include "GameController.hpp"
#include <iostream>
#include <fstream>
#include "Enums.h"

using namespace std;

void readTextFile(string path)
{
    ifstream infile(path);
    string line;
    
    while (getline(infile, line))
    {
        cout << line << endl;
    }
}

void GameController::chooseBattle()
{
    int battleChoise;
    cout << "Please, choose a battle: \n Possibilities: \n 1. Battle of Wizna \n 2. Battle of Stalingrad \n 3. Battle of Kursk \n";
    cin >> battleChoise;
    switch (battleChoise) {
        case 1:
            this->battleChoice = Wizna;
            break;
        case 2:
            this->battleChoice = Stalingrad;
            break;
        case 3:
            this->battleChoice = Kursk;
            break;
        default:
            break;
    }
}

void GameController::listBattleStory()
{
    switch (this->battleChoice)
    {
        case Wizna:
            readTextFile("BattleOfWiznaStory.txt");
            break;
        case Stalingrad:
            readTextFile("BattleOfStalingradStory.txt");
            break;
        case Kursk:
            readTextFile("BattleOfKurskStory.txt");
            break;
        default:
            break;
    }
}

void GameController::generateWiznaTroops()
{
    vector<Division *> polishDivisions;
    Division polandDivision1 = Division("Narew IOG", "Młot-Fijałkowski", ParticipatingCountries::Poland,  400);
    Division polandDivision2 = Division("Odcinek Obrony Wizna", "Raginis", ParticipatingCountries::Poland, 100);
    Division polandDivision3 = Division("8th company of 135th Infantry Regiment", "Schmidt", ParticipatingCountries::Poland,  100);
    Division polandDivision4 = Division("3rd heavy MG company of Osowiec fortress batt", "Raginis", ParticipatingCountries::Poland,  50);
    Division polandDivision5 = Division("Battery of positional artillery", "Brykalski", ParticipatingCountries::Poland, 70);
    polishDivisions.push_back(&polandDivision1);
    polishDivisions.push_back(&polandDivision2);
    polishDivisions.push_back(&polandDivision3);
    polishDivisions.push_back(&polandDivision4);
    polishDivisions.push_back(&polandDivision5);
    Army polishArmy = Army(Sides::Allies, "Raginis", polishDivisions);
    
    Division wmDivision1 = Division("3rd Army", "von Kuechler", ParticipatingCountries::Germany,  20000);
	TankDivision wmDivision2 = TankDivision("XIX Panzer Corps", "Guderian", ParticipatingCountries::Germany,  50000, 300, 10000, 500);
	TankDivision wmDivision3 = TankDivision("3rd Panzer Division", "Stumpff", ParticipatingCountries::Germany,  50000, 300, 10000, 500);
	TankDivision wmDivision4 = TankDivision("10th Panzer Division", "Falkenhorst", ParticipatingCountries::Germany,  50000, 300, 10000, 500);
	MotorizedDivision wmDivision5 = MotorizedDivision("20th Motorised Division", "von Wiktorin", ParticipatingCountries::Germany,  2000, 500, 500);
    Division wmDivision6 = Division("Lötzen Fortress Brigade", "Offenbacher", ParticipatingCountries::Germany, 5000);
    vector<Division*> wmDivisions;
    
    wmDivisions.push_back(&wmDivision1);
    wmDivisions.push_back(&wmDivision2);
    wmDivisions.push_back(&wmDivision3);
    wmDivisions.push_back(&wmDivision4);
    wmDivisions.push_back(&wmDivision5);
    wmDivisions.push_back(&wmDivision6);
    Army wehrmacht = Army(Sides::Axis, "Guderian", wmDivisions);
    
    Battle currentBattle = Battle("Battle of Wizna", polishArmy, wehrmacht);
    this->battle = currentBattle;
    
    int sizePolishArmyDivisions = polishDivisions.size();
    int sizeWehrmachtArmy = wmDivisions.size();
    
    this->battle.printGeneralTroopsmatrix();
	cout << "\n\n";
	this->battle.clashOfDivisions();
}

void GameController::generateStalingradTroops()
{
	vector<Division *> sovietDivisions;
	vector<Division *> wmDivisions;

	Division sovietDivision1 = Division("28th Army", "Vladimir Kachalov", ParticipatingCountries::USSR, 100000);
	Division sovietDivision2 = Division("51st Army", "Fyodor Kuznetsov", ParticipatingCountries::USSR, 300000);
	MotorizedDivision sovietDivision3 = MotorizedDivision("57th Army", "Andrey Vlasov", ParticipatingCountries::USSR, 100000, 2000, 2000);
	TankDivision sovietDivision4 = TankDivision("62nd Order of Lenin Army", "Vasily Chuikov", ParticipatingCountries::USSR, 200000, 300, 7500, 500);
	TankDivision sovietDivision5 = TankDivision("7th Guards Army", "Georgy Zhukov", ParticipatingCountries::USSR, 400000, 300, 2500, 500);
	
	TankDivision wmDivision1 = TankDivision("6th Army", "Friedrich Paulus", ParticipatingCountries::Germany, 400000, 300, 500, 200);
	TankDivision wmDivision2 = TankDivision("4th Panzer Army", "Friedrich Paulus", ParticipatingCountries::Germany, 100000, 100, 500, 300);
	Division wmDivision3 = Division("Armata Italiana in Russia", "Italo Gariboldi", ParticipatingCountries::Italy, 300000);
	sovietDivisions.push_back(&sovietDivision1);
	sovietDivisions.push_back(&sovietDivision2);
	sovietDivisions.push_back(&sovietDivision3);
	sovietDivisions.push_back(&sovietDivision4);
	sovietDivisions.push_back(&sovietDivision5);

	wmDivisions.push_back(&wmDivision1);
	wmDivisions.push_back(&wmDivision2);
	wmDivisions.push_back(&wmDivision3);

	Army sovietArmy = Army(Sides::Allies, "Zhukov", sovietDivisions);
	Army wmArmy = Army(Sides::Axis, "Paulus", wmDivisions);

	Battle currentBattle = Battle("Battle of Stalingrad", sovietArmy, wmArmy);
	this->battle = currentBattle;
	
	this->battle.printGeneralTroopsmatrix();
	cout << "\n\n";
	this->battle.clashOfDivisions();

	//Armata Italiana in Russia
	//4th Panzer Army

}

void generateKurskTroops()
{
    
}

void GameController::generateBattleTroops()
{
    switch (this->battleChoice) {
        case Wizna:
            generateWiznaTroops();
            break;
        case Stalingrad:
            generateStalingradTroops();
            break;
        case Kursk:
            generateKurskTroops();
            break;
        default:
            break;
    }
}



