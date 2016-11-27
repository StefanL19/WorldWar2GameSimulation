#include "Battle.hpp"
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

#define ROW 20
#define COL 20

struct Point
{
	Point(int x1, int y1)
	{
		this->x = x1;
		this->y = y1;
	}
	Point()
	{
		this->x = -1;
		this->y = -1;
	}
	int x;
	int y;

	bool operator!=(const Point &another)
	{
		return (this->x != another.x && this->y != another.y);
	}
};

bool** matrixReplication(Division* divisionMatrix[20][20])
{
	bool** battleReplication = 0;
	battleReplication = new bool*[ROW];
	for (int i = 0; i < ROW; ++i)
	{
		battleReplication[i] = new bool[COL];
		for (int j = 0; j < COL; j++)
		{
			if (divisionMatrix[i][j] != nullptr)
			{
				battleReplication[i][j] = false;
			}
			else
			{
				battleReplication[i][j] = true;
			}
		}
	}
	return battleReplication;
}

bool operator==(const Point &firstPoint, const Point &anotherPoint) 
{
	return (firstPoint.x == anotherPoint.x && firstPoint.y == anotherPoint.y);
}


//injection of a custom hash to the std namespace 
namespace std
{
	template<> struct hash<Point>
	{
		typedef Point argument_type;
		typedef std::size_t result_type;
		result_type operator()(argument_type const& s) const
		{
			result_type const h1 = std::hash<std::int64_t>{}(s.x);
			result_type const h2 = std::hash<std::int64_t>{}(s.y);
			return h1 ^ (h2 << 1); // or use boost::hash_combine
		}
	};
}

// An Data Structure for queue used in BFS
struct queueNode
{
    Point pt;  // The cordinates of a cell
    int dist;  // cell's distance of from the source
};

// check whether given cell (row, col) is a valid
// cell or not.
bool isValid(int row, int col)
{
    // return true if row number and column number
    // is in range
    return (row >= 0) && (row < ROW) &&
    (col >= 0) && (col < COL);
}

// These arrays are used to get row and column
// numbers of 4 neighbours of a given cell
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

bool isNotBlocked(bool battleField[ROW][COL], int x, int y, int destX, int destY) 
{
	if (x == destX && y == destY)
		return true;

	else if(battleField[x][y])
	{
		return true;
	}

	else
	{
		return false;
	}
}

unordered_map<Point, Point> shortestPath(bool battleField[ROW][COL], Point source, Point destination)
{
    
    
	unordered_map<Point, Point> previous_point;
    /*if (!battleField[source.x][source.y] || !battleField[destination.x][destination.y])
    {
		return previous_point;
    }*/
    
    //matrix of visited elements
    bool visited[ROW][COL];
    //declare all elements in the visited matrix as unvisited
    memset(visited, false, sizeof(visited));
	visited[source.x][source.y] = true;

    // Create a queue for BFS
    queue<queueNode> q;
    
    
    queueNode s = {source, 0}; // Distance from source cell is 0
    q.push(s);
    
    while (!q.empty())
    {
        queueNode current = q.front();
        Point pt = current.pt;
        
        // If we have reached the destination cell,
        // we are done
		if (pt.x == destination.x && pt.y == destination.y)
			return previous_point;
        
        // Otherwise dequeue the front cell in the queue
        // and enqueue its adjacent cells
        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];
            
            // if adjacent cell is valid, has path and
            // not visited yet, enqueue it.
            if (isValid(row, col) && isNotBlocked(battleField, row, col, destination.x, destination.y) &&
                !visited[row][col])
            {
				Point new_point{ row, col };

                // mark cell as visited and enqueue it
                visited[row][col] = true;
                queueNode Adjcell = { {row, col},
                    current.dist + 1 };
                q.push(Adjcell);
				previous_point[new_point] = current.pt;
                //cout << Adjcell.pt.x << ", "<< Adjcell.pt.y << endl;
            }
           
        }
    }
    
	return previous_point;
}

bool checkIfAllies(ParticipatingCountries country)
{
    switch (country) {
        case ParticipatingCountries::Germany:
            return 0;
            break;
        case ParticipatingCountries::Japan:
            return 0;
        default:
            return 1;
            break;
    }
}

Battle::Battle(){};
Battle::Battle(string battleName, Army& army1, Army& army2)
{
    this->battleName = battleName;
    this->army1 = &army1;
    this->army2 = &army2;
}


void Battle::printGeneralTroopsmatrix()
{
    for (int row = 0; row < 20; ++row)
    {
        
        for (int col = 0; col < 20; ++col)
        {
            if (this->divisionMatrix[row][col] == nullptr)
            {
                cout << "///" << " | ";
                continue;
            }
            else
            {
                //checkWhy throwing bad access
                ParticipatingCountries divisionCountry = this->divisionMatrix[row][col]->getDivisionCountry();
                int isAllies = checkIfAllies(divisionCountry);
                
                if (isAllies == 1)
                {
                    cout << "ALL" << " | ";
                }
                else if(!checkIfAllies(divisionCountry))
                {
                    cout << "AXS" << " | ";
                }
            }
        }
        cout << endl;
    }
}

void Battle::alterDivisionMatrix(Division* division)
{
    bool shoudExit = 0;
    if (checkIfAllies(division->getDivisionCountry()))
    {
                for (int row = 0; row < 5; ++row)
                {
                    for (int col = 0; col < 19; ++col)
                    {
                        if (this->divisionMatrix[row][col] == nullptr)
                        {
                            this->divisionMatrix[row][col] = division;
                            shoudExit = 1;
                            break;
                        }
                    }
                    if (shoudExit) {
                        break;
                    }
                }
    } //end check if allies
    
    else
    {
        for (int row = 15; row < 20; ++row)
        {
            for (int col = 19; col >= 0; --col)
            {
                if (this->divisionMatrix[row][col] == nullptr)
                {
                    this->divisionMatrix[row][col] = division;
                    shoudExit = 1;
                    break;
                }
            }
            if (shoudExit) {
                break;
            }
        }
    }
    
}

Point Battle::printShortestPath(Point source, Point destination)
{   
	bool** currentBattleReplication = matrixReplication(this->divisionMatrix);
	bool battleMatrix[ROW][COL] = {};
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			battleMatrix[i][j] = currentBattleReplication[i][j];
		}
	}

    unordered_map<Point, Point> solution = shortestPath(battleMatrix, source, destination);
	Point currentPoint = destination;
	Point safeMove = solution[currentPoint];
	//flip the unordered map, so we can find the shortest safe mpv
	while (solution[currentPoint].x != source.x || solution[currentPoint].y != source.y)
	{
	  currentPoint = solution[currentPoint];
	}
	return currentPoint;
	/*while (currentPoint.x != source.x || currentPoint.y != source.y)
	{
		
		currentPoint = solution[currentPoint];
		cout << currentPoint.x << " : " << currentPoint.y << endl;
	}

	int a;
	cin >> a;*/
}

Point Battle::getDivisionPosition(Division* division)
{
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			if (this->divisionMatrix[i][j] != nullptr)
			{
				if (this->divisionMatrix[i][j]->getName() == division->getName())
				{
					return Point{ i, j };
				}
			}
		}
	}

	return Point{ -1, - 1 };
}

// A function to clash all divisions, it implements a small artificial intelligence
void Battle::clashOfDivisions() 
{
	vector<Division*> alliesDivisions = this->army1->getDivisions();
	vector<Division*> wmDivisions = this->army2->getDivisions();

	size_t sizeAlliesArmy = alliesDivisions.size();
	size_t sizeWehrmachtArmy = wmDivisions.size();


	for (int i = 0; i < sizeWehrmachtArmy; ++i) 
	{
		this->alterDivisionMatrix(wmDivisions[i]);
	}

	for (int i = 0; i < sizeAlliesArmy; ++i) 
	{
		this->alterDivisionMatrix(alliesDivisions[i]);
	}

	this->printGeneralTroopsmatrix();

	this->clashTwoDivisions(alliesDivisions[0], wmDivisions[0]);
}

void Battle::clashTwoDivisions(Division* division1, Division* division2)
{
	
	
	Point division1Position = this->getDivisionPosition(division1);
	Point division2Position = this->getDivisionPosition(division2);


	bool collisionDetected = 0;
	system("cls");

	while (!collisionDetected)
	{
		Sleep(1500);
		system("cls");
		//check if division 1 can move
		Point shortestPathForDivision1 = this->printShortestPath(division1Position, division2Position);

		if (shortestPathForDivision1 == division2Position)
		{
			collisionDetected = 1;
			continue;
		}

		//move division 1
		moveDivision(division1Position, shortestPathForDivision1);

		//change division 1 position
		division1Position = shortestPathForDivision1;

		//check if division 2 can move
		Point shortestPathForDivision2 = this->printShortestPath(division2Position, division1Position);

		if (shortestPathForDivision2 == division1Position)
		{
			collisionDetected = 1;
			continue;
		}

		//move division 2
		moveDivision(division2Position, shortestPathForDivision2);

		//change division 2 position
		division2Position = shortestPathForDivision2;
		
		cout << "\n\n\n\n\n";
		this->printGeneralTroopsmatrix();
	}

	int a;
	cin >> a;
	//check if they do not collide
	//if collide fight and see which one wins
	//else update the battle matrix

}

void Battle::moveDivision(Point currentPosition, Point nextPosition)
{
	Division* divisionToMove = this->divisionMatrix[currentPosition.x][currentPosition.y];
	this->divisionMatrix[currentPosition.x][currentPosition.y] = nullptr;
	this->divisionMatrix[nextPosition.x][nextPosition.y] = divisionToMove;
}