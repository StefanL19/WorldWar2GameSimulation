#include "Battle.hpp"
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

#define ROW 20
#define COL 20

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
};

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

unordered_map<Point, Point> shortestPath(bool battleField[ROW][COL], Point source, Point destination)
{
    
    
	unordered_map<Point, Point> previous_point;
    if (!battleField[source.x][source.y] || !battleField[destination.x][destination.y])
    {
		return previous_point;
    }
    
    //matrix of visited elements
    bool visited[ROW][COL];
    //declare all elements in the visited matrix as unvisited
    memset(visited, false, sizeof(visited));
    
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
            if (isValid(row, col) && battleField[row][col] &&
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

void Battle::printShortestPath()
{
    Point source = Point(0,0);
    Point destination = Point(2, 2);
    
    bool battleMatrix [20][20] = {};
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < 20; ++j)
        {
            battleMatrix[i][j] = 1;
        }
    }
    
	bool** currentBattleReplication = matrixReplication(this->divisionMatrix);
	bool battleM[ROW][COL] = {};
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			battleM[i][j] = currentBattleReplication[i][j];
		}
	}

    unordered_map<Point, Point> solution = shortestPath(battleMatrix, source, destination);
	Point currentPoint = destination;
	while (currentPoint.x != source.x || currentPoint.y != source.y)
	{
		
		currentPoint = solution[currentPoint];
		cout << currentPoint.x << " : " << currentPoint.y << endl;
	}

	int a;
	cin >> a;
}