/*******************************************************
 *  Name      : Michael Zabawa
 *  Student ID: 107522040
 *  Class     :  CSCI 2312
 *  Due Date  :  Apr. 4, 2018
 *******************************************************/
//  Player.cpp


#include <iostream>
#include <ctype.h>//toupper for converstion
#include "Player.h"

Player::Player(){
    winner = false;
    shipSunk = 0;
    //declares ships
    Watervehicle carrier("CARRIER");
    Watervehicle battleship("BATTLESHIP");
    Watervehicle cruiser("CRUISER");
    Watervehicle submarine("SUBMARINE");
    Watervehicle destroyer("DESTROYER");
    //fills fleet
    fleet.push_back(carrier);
    fleet.push_back(battleship);
    fleet.push_back(cruiser);
    fleet.push_back(submarine);
    fleet.push_back(destroyer);
}

void Player::clearBoards(){
    shipBoard.clear();
    shotBoard.clear();
    for(int i = 0; i< fleet.size(); i++)
        fleet[i].setHit(0);
}

void Player::shipStart(Watervehicle &ship, int col, int row, char direction){//
    ship.setCol(col); //sets starting col for ship
    ship.setRow(row); // sets starting row for ship
    ship.setOrentation(direction);// sets direction for ship
}


bool Player::noShipHere(Watervehicle ship){ //function noShipHere
    bool notHere = true;//assumes a ship can go in the location
    if(!(shipBoard.checkMark(ship.getStartRow(), ship.getStartCol(), ' '))){
         notHere = false;
         return notHere;
    }//checks starting location
    if(ship.getOrentation() == 'H'){
        if((ship.getStartCol() + ship.sizeOfShip()) > shipBoard.getNcol()){//checks if inbounds
            notHere = false;
            return notHere;
        }
        for(int i = 0; i < ship.sizeOfShip(); i++){//checks for ships in path
            notHere = shipBoard.checkMark(ship.getStartRow(),ship.getStartCol() + i, ' ');//checkMark for ' ' at until size of ship
            if(!notHere){
                return notHere;
            }//if
        }//for size of ship
    }//if H
    if(ship.getOrentation() == 'V'){
        if((ship.getStartRow() + ship.sizeOfShip()) > shipBoard.getNrow()){//checks if inbounds
            notHere = false;
            return notHere;
        }//if
        for(int i = 0; i < ship.sizeOfShip(); i++){//check for other ships in path
            notHere = shipBoard.checkMark(ship.getStartRow() + i, ship.getStartCol(), ' ');//checkMark for ' ' at i, j + 1 until size of ship
            if(!notHere){
                return notHere;
            }//if
        }//for sizeofship
    }//if v
    return notHere;
}//function noShipHere end

void Player::placeShip(Watervehicle ship){//puts the ship on the shipBoard
    if(ship.getOrentation() == 'H'){
        for(int i = 0; i < ship.sizeOfShip(); i++)//for size of ship placemark
            shipBoard.placeMark(ship.getStartRow(),ship.getStartCol() + i, ship.shipMark());
    }//if
    if(ship.getOrentation() == 'V'){
        for(int i = 0; i < ship.sizeOfShip(); i++)//for size of ship placemark
            shipBoard.placeMark(ship.getStartRow() + i, ship.getStartCol(), ship.shipMark());
    }//if
}//function end


void Player::placeShip(Watervehicle ship, Board &board1){//puts the ship on the shipBoard
    if(ship.getOrentation() == 'H'){
        for(int i = 0; i < ship.sizeOfShip(); i++)//for size of ship place mark
            board1.placeMark(ship.getStartRow(),ship.getStartCol() + i, ship.shipMark());
    }//if
    if(ship.getOrentation() == 'V'){
        for(int i = 0; i < ship.sizeOfShip(); i++)//for size of ship placemark
            board1.placeMark(ship.getStartRow() + i, ship.getStartCol(), ship.shipMark());
    }//if
}//function end

int Player::fireTorpedo(int row, int col, Player &player){
    std::string shipName;
    int result = -1;//if -1 returned then there was an error in the function
    if(!shotBoard.checkMark(row, col, ' ')){//shot was already made if board was already marked with a O (miss) or X (hit) returns 2.
        return 2;
    }
    else if(player.shipBoard.checkMark(row, col, ' ')){//miss returns 0.
            shotBoard.placeMark(row, col, 'O');//mark shot board of calling player with a O (miss)
            return 0;
        }
    else{
        for(int i = 0; i < player.fleet.size(); i++){//if not a miss or a previous shot checks the mark from each ship in the players fleet to see if it was a hit.
            if(player.shipBoard.checkMark(row , col, player.fleet[i].shipMark())){//checks each ship mark for placement on player board.
                player.fleet[i].gotHit();//if hit increments the hit counter.
                player.shipBoard.placeMark(row, col, 'X');//marks oposing player ship board
                shotBoard.placeMark(row, col, 'X');//marks calling player shot board
                if(player.fleet[i].is_sunk()){
                    placeShip(player.fleet[i], shotBoard);
                    shipSunk++;
                    shipName = player.fleet[i].shipType();
                    for(int i = 1; i < shipName.size(); i++){
                        shipName[i] = tolower(shipName[i]);
                    }
                    std::cout<< std::endl << shipName << " is sunk!\n";
                    if(shipSunk == 5){
                        winner = true;
                        return 3;
                    }
                }
                return 1;
            }
        }
    }
    return result;//returns -1 if an error occured.
}
