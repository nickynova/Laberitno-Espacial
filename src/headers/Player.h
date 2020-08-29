#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    
public:

    Player();

    int x, y;

    int lastX, lastY;


    void CallInput();

    void ResetToSafePos();

   
};

#endif // PLAYER_H
