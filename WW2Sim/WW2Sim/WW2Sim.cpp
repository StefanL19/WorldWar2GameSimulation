
#include <iostream>
#include "GameController.hpp"
#include <windows.h>
using namespace std;

int main()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	GameController* gameController = new GameController();


	gameController->chooseBattle();
	gameController->listBattleStory();

	int ac;
	cout << "Enter 1 to proceed battle: ";
	cin >> ac;
	if (ac != 1)
	{
		main();
	}
	cout << "\n";

	cout << "Battle troops positions \n \n";

	gameController->generateBattleTroops();

	int a;
	std::cin >> a;
	return 0;
}
