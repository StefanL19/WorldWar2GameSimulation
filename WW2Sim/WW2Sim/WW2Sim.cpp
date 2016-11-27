
#include <iostream>
#include "GameController.hpp"
#include <windows.h>
using namespace std;

int main(int argc, const char * argv[])
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	GameController* gameController = new GameController();


	gameController->chooseBattle();
	gameController->listBattleStory();

	cout << "\n";

	cout << "Battle troops positions \n \n";

	gameController->generateBattleTroops();

	int a;
	std::cin >> a;
	return 0;
}
