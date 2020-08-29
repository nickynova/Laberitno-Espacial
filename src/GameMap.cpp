#include <iostream>
#include "../src/headers/GameMap.h"
#include <fstream>

using namespace std;

GameMap::GameMap()
{
    id = ' ';
    PlayerCell = NULL;
    LoadMapFromFile();
    isGameOver = false;

}

void GameMap::Draw()
{
    for (int i = 0; i < 10; i++)
    {
        for (int p = 0; p < 30; p++)
        {
            cout << Cells[i][p].id;
        }
        
        cout << endl;
    }
    
}

void GameMap::DrawIntro()
{
    string line;
    ifstream MyFile("Intro.txt");

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
        cout << "FATAL ERROR: INTRO COULD NOT BE LOADED" << endl;
    }


}

bool GameMap::SetPlayerCell(int PlayerX, int PlayerY)
{
    if (Cells[PlayerX][PlayerY].IsBlocked() == false)
    {
        if (Cells[PlayerX][PlayerY].id == '$')
        {
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

void GameMap::LoadMapFromFile()
{
    /* ofstream FileCreated("Map.txt");

    if (FileCreated.is_open())
    {
        
    }
    else
    {
        cout << "FATAL ERROR: MAP COULD NOT BE CREATED" << endl;
    } */
    
    string line;
    int row = 0;
    ifstream MyFile("Map.txt");

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

