/*******************************************************
 *  Name      : Michael Zabawa
 *  Student ID: 107522040
 *  Class     :  CSCI 2312
 *  Due Date  :  Apr. 4, 2018
 *******************************************************/
//  ComputerPlayer.h



#ifndef COMPUTERPLAYER_h
#define COMPUTERPLAYER_h

#include "Player.h"

class ComputerPlayer:public Player{
private:
    bool torpedoHit;
    bool hitH;
    bool HitV;
    bool hitShipIsSunk;
    
    int hitRow;
    int hitCol;
    
public:
    int randindex(){return rand()%10;}    
    
    bool gameSetup();
    bool readyAimFire(Player &player);

};

#endif /* ComputerPlayer_h */
