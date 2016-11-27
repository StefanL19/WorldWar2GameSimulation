

#include "Army.hpp"
using namespace std;

Army::Army()
{
}

Army::Army(Sides side, string general)
{
    this->side = side;
    this->general = general;
}

Army::Army(Sides side, string general, vector<Division*> divisions)
{
    this->side = side;
    this->general = general;
    this->divisions = divisions;
}