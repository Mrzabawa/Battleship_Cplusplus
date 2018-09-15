/*******************************************************
 *  Name      : Michael Zabawa
 *  Student ID: 107522040
 *  Class     :  CSCI 2312
 *  Due Date  :  Apr. 4, 2018
 *******************************************************/
//  HumanPlayer.cpp

#include<iostream>
#include<fstream>
#include "HumanPlayer.h"
#include "MyExceptions.h"

bool HumanPlayer::filesetupgame(std::string fileName) throw(fileFailedToOpen, shipsMissing){
    std::string shipName, location, orentation;
    bool complete = false;
    int startingRow, startingCol;
    const char *direction;
    const char *startPosition;
    char tempChar, tempOrentation;
    
    std::ifstream infile(fileName);//open input file
        if(infile.fail()){
            throw fileFailedToOpen(fileName);
        }
    getline(infile, shipName);
    while(getline(infile, shipName, ',')){
        for(int i = 0; i < shipName.length(); i++){//makes shipname case insensitive
            shipName[i] = toupper(shipName[i]);
        }
        getline(infile, location, ',');
        getline(infile, orentation);
        if(shipName == "" || location == ""|| orentation == ""){//check files for missing input
            throw shipsMissing(shipName);
        }
        
        direction = orentation.c_str();
        tempOrentation = direction[0];
        tempOrentation = toupper(tempOrentation);
        startPosition = location.c_str();
        tempChar = startPosition[0];
        startingCol = convert(tempChar);
        startingRow = startPosition[1] - 49;
        if(location.size() > 2){
            if(startPosition[1] == 49 & startPosition[2] == 48)
                startingRow = 9;
            else
                startingRow = -1;
        }
        if(startingCol == -1 || startingRow < 0 || startingRow > 9 || (tempOrentation != 'H' & tempOrentation != 'V')){//checks input for correct indexs
            throw shipsMissing(shipName);
        }
        for(int i = 0; i<5 ; i++){
            if(fleet[i].shipType() == shipName){//checks if ship is the one to place
                shipStart(fleet[i], startingCol, startingRow, tempOrentation);//set starting location
                if(noShipHere(fleet[i])){//checks for placement conflicts
                    placeShip(fleet[i]);//puts ship on board if no conflict
                    shipsPlaced++;
                }//noShipHere
                else{
                    throw shipsMissing(shipName);
                }
            }//if ship i is the ship to place
        }//for each ship in fleet
    }//while
    if(shipsPlaced == 5){//if 5 ships were placed return true
        complete = true;
    }
    else{
        throw shipsMissing("A");//throws an exception for "A" missing ship
    }
    std::cout << "Player Ship Board\n";
    printShipBoard();
    infile.close();
    return complete;
}//function

bool HumanPlayer::readyAimFire(Player &player) throw (incorrectInput){
    int row = -1, fire, numCol;
    char col;
    bool nextPlayer = false;
    while(!nextPlayer){//allows player to continue to call shots if not a miss or shot was already called
        printShotBoard();
        std::cout <<"Q to quit \nOr Call a shot...Ready? Aim...: \n";
        std::cin >> col;
        if(!isalpha(col)){//if not a char throw exception
            throw incorrectInput();
        }
        col = toupper(col);//converts a char to proper index
        if(col == 'Q'){
            std::cout << "Thanks for playing!\nHere are your guesses";
            printShotBoard();
            std::cout << "Computers Ship board";
            player.printShipBoard();
            exit(1);
        }
        if(!(std::cin >> row)){
            std::cin.clear();//resets stream after a fail 
            throw incorrectInput();
        }
        numCol = convert(col);//returns -1 if failed to be in the range of A - J
        if( !( 1 <= row & row <= 10) || numCol == -1){
            throw incorrectInput();
        }
        fire = fireTorpedo(row - 1, numCol, player);//-1 to conform to the index convention
        if(fire == 0){//allows player to continue to call shots if not a miss or shot was already called; 0 indicates a miss.
            std::cout << "MISS!!!!\nComputers Turn\n";
            nextPlayer = true;
        }
        else if(fire == 2){
            std::cout << "You Already called that shot\nTry Again: \n";
        }
        else if(fire == 3){//winner
            return true;
        }
    }
    return nextPlayer;
}


//private
int HumanPlayer::convert(char col){//a function to convert a char to int that corresponds to the correct index returns -1 if failed
    int numCol = -1;
    col = toupper(col);
    switch(col){
        case 'A':
            numCol = 0;
            break;
        case 'B':
            numCol = 1;
            break;
        case 'C':
            numCol = 2;
            break;
        case 'D':
            numCol = 3;
            break;
        case 'E':
            numCol = 4;
            break;
        case 'F':
            numCol = 5;
            break;
        case 'G':
            numCol = 6;
            break;
        case 'H':
            numCol = 7;
            break;
        case 'I':
            numCol = 8;
            break;
        case 'J':
            numCol = 9;
            break;
        default:
            numCol = -1;
    }
    return numCol;
}

