
#include <iostream>
#include "GameController.hpp"
using namespace std;

int main(int argc, const char * argv[])
{
    GameController* gameController = new GameController();
    
    
    gameController->chooseBattle();
    gameController->listBattleStory();
    
    cout << "\n";
    
    cout << "Battle troops positions \n \n";
    
    gameController->generateBattleTroops();
    return 0;
}
