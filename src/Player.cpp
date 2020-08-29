#include <iostream>
#include "../src/headers/Player.h"


using namespace std;

Player::Player()
{
    x = 1;
    y = 1;
    
}

void Player::CallInput()
{

    char UserInput = ' ';

    cin >> UserInput;

    switch (UserInput)
    {
    case 'd':
        lastY = y;
        y++;
        break;

    case 'a':
        lastY = y;
        y -= 1;
        break;    
    
    case 's':
        lastX = x;
        x++;
        break;

    case 'w':
        lastX = x;
        x -= 1;
        break;  
    case 'p':
        cout << "te has salido del juego" << endl;
    }
    
}


void Player::ResetToSafePos()
{
    x = lastX;
    y = lastY;
}

