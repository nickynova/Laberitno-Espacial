#include <iostream>
#include "../src/headers/MapCell.h"

MapCell::MapCell()
{
    id = 0;
}

bool MapCell::IsBlocked()
{
    if (id == '1')
    {
        return true;
    }
    else
    {
        return false;
    }
    
    
}