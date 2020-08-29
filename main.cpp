#include <iostream>
#include "./src/headers/Player.h"
#include "./src/Player.cpp"
#include "./src/headers/MapCell.h"
#include "./src/MapCell.cpp"
#include "./src/headers/GameMap.h"
#include "./src/GameMap.cpp"

using namespace std;

int main()
{
    
    GameMap Map;
    Player Hero;

    Map.DrawIntro();
    Map.Draw();

    while (Map.isGameOver == false)
    {
        
        //el loop del juego
        cout << "introduce el comando de movimiento 'w' 'a' 's' 'd' " << endl;
        cout << "lleva tu nave espacial por el laberinto hasta llegar al tesoro escondido en alguno de los signos $" << endl;
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
    return 0;
}
