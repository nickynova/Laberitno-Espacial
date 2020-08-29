#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "MapCell.h"

class GameMap
{
protected:

    void LoadMapFromFile();
    
public:

    GameMap();

    MapCell* PlayerCell;
    MapCell Cells [10][30];

    void Draw();

    void DrawIntro();

    void DrawVictory();

    //Esta funcion tiene las cordenadas de player y actualiza el mapa
    bool SetPlayerCell(int PlayerX, int PlayerY);
    
    bool isGameOver = false;

    char id;
    
};

#endif // MAPCELL_H