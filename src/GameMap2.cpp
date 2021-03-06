#include <iostream>
#include "../src/headers/GameMap2.h"
#include <fstream>

using namespace std;

GameMap2::GameMap2()
{
    id = ' ';
    PlayerCell = NULL;
    LoadMapFromFile();
    isGameOver = false;

}

void GameMap2::Draw()
{
    for (int i = 0; i < 30; i++)
    {
        for (int p = 0; p < 50; p++)
        {
            cout << Cells[i][p].id;
        }
        
        cout << endl;
    }
    
}


bool GameMap2::SetPlayerCell(int PlayerX, int PlayerY)
{
    if (Cells[PlayerX][PlayerY].IsBlocked() == false)
    {
        if (Cells[PlayerX][PlayerY].id == '$')
        {
            DrawVictory();
            isGameOver = true;
            return true;
        }
        else
        {
            if (PlayerCell != NULL)
            {
                PlayerCell->id = ' ';
            }
    
            PlayerCell = &Cells[PlayerX][PlayerY];
            PlayerCell->id = 'V';
            //cout << "las cordenadas del player estan en: " << "," << PlayerY;
        }
        
        return true;
    }
    else
    {
        return false;
    }
    
    
}

void GameMap2::LoadMapFromFile()
{
    /* ofstream FileCreated("Map2.txt");

    if (FileCreated.is_open())
    {
        
    }
    else
    {
        cout << "FATAL ERROR: MAP COULD NOT BE CREATED" << endl;
    } */
    
    string line;
    int row = 0;
    ifstream MyFile("Map2.txt");

    if (MyFile.is_open())
    {
        while ( getline(MyFile, line))
        {
            for (int p = 0; p < line.length(); p++)
            {
                if (line[p] == '0')
                {
                    Cells[row][p].id = ' ';
                }
                else
                {
                    Cells[row][p].id = line[p];
                }
                
                
            }
            
            row++;
        }
        
    }
    else
    {
        cout << "FATAL ERROR: MAP COULD NOT BE LOADED" << endl;
    }
    
    
}

void GameMap2::DrawVictory()
{
    string line;
    ifstream MyFile("Victory.txt");

    if (MyFile.is_open())
    {
        while ( getline(MyFile, line))
        {
            cout << line << endl;
        }

        cin >> line;
        
    }
    else
    {
        cout << "FATAL ERROR: VICTORY COULD NOT BE LOADED" << endl;
    }


}