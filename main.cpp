#include <iostream>
#include "./src/headers/Player.h"
#include "./src/Player.cpp"
#include "./src/headers/MapCell.h"
#include "./src/MapCell.cpp"
#include "./src/headers/GameMap.h"
#include "./src/GameMap.cpp"
#include "./src/headers/GameMap2.h"
#include "./src/GameMap2.cpp"

using namespace std;

int main()
{
    
    GameMap Map;
    GameMap2 Map2;
    Player Hero;

    Map.DrawIntro();
    Map.Draw();

    while (Map.isGameOver == false)
    {
        
        //el loop del juego
        cout << "introduce el comando de movimiento 'w' 'a' 's' 'd' " << endl;
        cout << "lleva tu nave espacial por el laberinto hasta llegar al signo $ para curzar al siguiente nivel" << endl;
        Hero.CallInput();
    
        
        //se actualiza la info del hero a mapa
        if (Map.SetPlayerCell(Hero.x, Hero.y))
        {
            //aqui se dibuja el mapa
            Map.Draw();
        }
        else
        {
            Hero.ResetToSafePos();
            Map.Draw();
        } 
        
        
    }

    while (Map2.isGameOver == false)
    {
        
        //el loop del mapa 2
        cout << "introduce el comando de movimiento 'w' 'a' 's' 'd' " << endl;
        cout << "Has pasado de nivel! Ahora deberas lleva tu nave espacial por el laberinto hasta llegar al tesoro escondido en alguno de los signos $" << endl;
        Hero.CallInput();
    
        
        //se actualiza la info del hero a mapa
        if (Map2.SetPlayerCell(Hero.x, Hero.y))
        {
            //aqui se dibuja el mapa
            Map2.Draw();
        }
        else
        {
            Hero.ResetToSafePos();
            Map2.Draw();
        }    
    }

    return 0;
}
