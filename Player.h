/*******************************************************
 *  Name      : Michael Zabawa
 *  Student ID: 107522040
 *  Class     :  CSCI 2312
 *  Due Date  :  Apr. 4, 2018
 *******************************************************/
//  Player.h


#ifndef Player_h
#define Player_h

#include <string>
#include "Board.h"
#include "watervehicle.h"

class Player{
private:
    Board shipBoard;
    Board shotBoard;
    int shipSunk;
    bool winner;
    
protected:
    std::vector<Watervehicle> fleet;
    
public:
    Player();//constructor
    ~Player(){;}//destructor
    
    //getters and setters
    bool is_Winner(){return winner;}
    Watervehicle getFleet(int index){return fleet[index];}
    void printShotBoard(){shotBoard.printBoard();}
    void printShipBoard(){shipBoard.printBoard();}
    
    //precondition: game is being reset
    //postcondition: empty boards ready to set up again
    void clearBoards();
   
    //precondition: initlized Watervehicle
    //postcondition: Fully formed ship ready to be placed
    void shipStart(Watervehicle &ship, int col, int row, char direction);
    
    //precondition:initalized Board, Watervehicle
    //postcondition:returns if a ship is at location and orentation on board
    bool noShipHere(Watervehicle ship);
    
    //precondition:initalized Board, Watervehicle
    //postcondition:board with ship mark at start location and for the length of ship in direction of ship
    void placeShip(Watervehicle ship, Board &board1);
    
    //precondition:initalized Board, Watervehicle
    //postcondition:board with ship mark at start location and for the length of ship in direction of ship
    void placeShip(Watervehicle ship);
    
    //precondition:two intergers and a player
    //postcondition:returns 0 if a miss, returns 1 if a hit, returns 2 if already shot there, returns -1 for an error.
    int fireTorpedo(int row, int col, Player &player1);
};

#endif /* Player_h */
