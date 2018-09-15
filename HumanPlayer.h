/*******************************************************
 *  Name      : Michael Zabawa
 *  Student ID: 107522040
 *  Class     :  CSCI 2312
 *  Due Date  :  Apr. 4, 2018
 *******************************************************/
//  HumanPlayer.h

#ifndef HUMANPLAYER_h
#define HUMANPLAYER_h

#include "Player.h"
#include "MyExceptions.h"

class HumanPlayer:public Player{
private:
    int convert(char col);
    int shipsPlaced = 0;
    
public:
    
    //precondition:
    //postcondition: human player set up and ready to play
    bool filesetupgame(std::string fileName) throw(fileFailedToOpen, shipsMissing);
    
    //precondition: a game set up and ready to play
    //postcondition: marked boards according to the user shot called
    bool readyAimFire(Player &player) throw (incorrectInput);
};


#endif /* HumanPlayer_h */
