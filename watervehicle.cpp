/*******************************************************
 *  Name      : Michael Zabawa
 *  Student ID: 107522040
 *  Class     :  CSCI 2312
 *  Due Date  :  Apr. 4, 2018
 *******************************************************/
//  watervehicle.cpp


#include <iostream>
#include <ctype.h>//toupper for col converstion
#include "watervehicle.h"

Watervehicle::Watervehicle(std::string _typeOfShip){//constructor
    typeOfShip = _typeOfShip;
    sunk = false;
    hit = 0;
    if(typeOfShip == "CARRIER"){
        lengthOfShip = 5;
        mark = 'C';
    }
    if(typeOfShip == "BATTLESHIP"){
        lengthOfShip = 4;
        mark = 'B';
    }
    if(typeOfShip == "CRUISER"){
        lengthOfShip = 3;
        mark = 'U';
    }
    if(typeOfShip == "SUBMARINE"){
        lengthOfShip = 3;
        mark = 'S';
    }
    if(typeOfShip == "DESTROYER"){
        lengthOfShip = 2;
        mark = 'D';
    }
}

void Watervehicle::gotHit(){//increments hit and checks if sunk mutates sunk if hits == size of ship
    std::string shipName;
    shipName = typeOfShip;
    for(int i = 1; i < shipName.size(); i++){//gives the proper case for the ship
        shipName[i] = tolower(shipName[i]);
    }
    std::cout << std::endl << shipName << " was hit\n";
    hit = hit + 1;
    if(hit == lengthOfShip){//indicates that the ship is sunk
        sunk = true;
    }
}
