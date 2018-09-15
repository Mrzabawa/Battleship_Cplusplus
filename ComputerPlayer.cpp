/*******************************************************
 *  Name      : Michael Zabawa
 *  Student ID: 107522040
 *  Class     :  CSCI 2312
 *  Due Date  :  Apr. 4, 2018
 *******************************************************/
//  ComputerPlayer.cpp


#include<iostream>//cout cin
#include "ComputerPlayer.h"


bool ComputerPlayer::gameSetup(){
    bool nextShip = false;//assumes not successful
    for(int i = 0; i <5;i++){
        nextShip = false;
        while(!nextShip){
            int orentation = rand()%2;
            if (orentation == 1){
                shipStart(fleet[i], randindex() , randindex(), 'H');
                if(noShipHere(fleet[i])){
                    placeShip(fleet[i]);
                    nextShip = true;
                }//if
            }//if direction
            else{
                shipStart(fleet[i], randindex(),randindex(), 'V');
                if(noShipHere(fleet[i])){
                    placeShip(fleet[i]);
                    nextShip = true;
                }//if
            }//else direction
        }//while not placed
    }//for
    return true;
}

//fireTorpedo postcondition:returns 0 if a miss, returns 1 if a hit, returns 2 if already shot there, returns -1 for an error.
bool ComputerPlayer::readyAimFire(Player &player){
    int row, col, fire;
    bool nextPlayer = false;
    while(!nextPlayer){//allows player to continue to call shots if not a miss or shot was already called
        /*
        if(torpedoHit){//if last shot was a hit
            //row, col +1; row, col - 1;
            row = hitRow;
            col = hitCol;
            //row+1, col; row-1, col;
        
        }
        //if the last shot was not a hit or the opposing player ship was not sunk then try:
       */
        row = randindex();
        col = randindex();
        fire = fireTorpedo(row, col, player);
        if(fire == 1){//lets computerplayer know the shot was a hit saves center hit for follow up shot.
            
            torpedoHit = true;
            hitRow = row;
            hitCol = col;
        }
        else if(fire == 0){//allows player to continue to call shots if not a miss or shot was already called; 0 indicates a miss.
            std::cout << "Missed\nYour turn\n";
            nextPlayer = true;
        }
    }
    return nextPlayer;
}




