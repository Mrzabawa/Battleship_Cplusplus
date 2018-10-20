/*******************************************************
 *  Name      : Michael Zabawa
 *  Student ID: 107522040
 *  Class     :  CSCI 2312
 *  Due Date  :  Apr. 4, 2018
 *******************************************************/
//  main.cpp


#include <iostream>
#include <fstream>
#include <ctime>//to seed random generator
#include <cstdlib>//for rand()
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "watervehicle.h"
#include "Board.h"
using namespace std;

int main(){
    srand(time(nullptr));
    
    int choice = 0;
    char play = ' ';
    string fileName;
    bool readyToPlay = true;
    bool gameOn = true;
    
    while(gameOn){
        cout << "Welcome to the Battleship Game\n\tEnter 1 to view game instructions\n\tEnter 2 to play the game\n\tEnter 3 to exit game\n";
        if(!(cin >> choice)){
            cin.clear();
            cin.ignore();
            choice = -1;
        }
        switch(choice){
            case 1://gives user the rules of the game and the expected format of the ship file
            {
                ifstream inFile("gameinstructions.txt");
                cout << inFile.rdbuf();
                inFile.close();
                cout<<endl;
                break;
            }
            case 2://plays game; this is a two step process. 1 set up the game. 2 fire torpedos until someone wins
            {
                HumanPlayer player1;
                ComputerPlayer player2;
                readyToPlay = false;//returns true when game is setup
                
                while(!readyToPlay){
                    try{
                        cout << "Enter a file path to the ship file: ";//to ask user for file path
                        cin >> fileName;
                        readyToPlay = player1.filesetupgame(fileName);//sets up game for human player by way of file
                    }catch(fileFailedToOpen e){
                        cerr << e.info()<<" "<<e.what();
                        cerr << "Would you like to try again? Only 'q' or 'Q' will quit the game: \n";
                        cin >> play;
                        play = toupper(play);
                        if(play == 'Q'){
                            cout << "Thanks for playing\n";
                            exit(0);
                        }//if quit
                    }catch(shipsMissing e){
                        player1.printShipBoard();
                        cerr <<"There is an issue with the format of the file\n";
                        cerr << e.info()<< " "<<e.what();
                        cerr << "Would you like to try again? Only 'q' or 'Q' will quit the game: \n";
                        cin >> play;
                        play = toupper(play);
                        if(play == 'Q'){
                            cout << "Thanks for playing\n";
                            exit(0);
                        }//if quit
                    }
                }//while for board set up
                player2.gameSetup();//randomly sets up game for computer
                
                //game is set up ready to fire topedos
                while(!player1.is_Winner() & !player1.is_Winner()){
                    readyToPlay = false;
                    while(!readyToPlay){
                        try{
                            readyToPlay = player1.readyAimFire(player2);
                        }catch(incorrectInput){
                            cerr << "You entered incorrect input!\nThe correct format is a letter A - J \nThen a number 1 - 10\n";
                        }
                    }
                    if(player1.is_Winner()){//checks if human won
                        player1.printShotBoard();
                        cout<< "You beat the computer!!!!\n";
                        readyToPlay = true;
                        break;
                    }
                    
                    player2.readyAimFire(player1);//fires torpedo at human
                    player1.printShipBoard();//shows the result of the shot
                    if(player2.is_Winner()){//checks if computer won
                        cout<< "You lost!!!!\nBetter luck next time\n";
                        readyToPlay = true;
                        break;
                    }
                }//while shots are fired and no winner
                break;
            }//end of case 2
                
            case 3:
            {
                cout << "Have a Greatday!\n";
                gameOn = false;//ends the while gameOn loop
                break;
            }
                
            default:
            {
                cout<<"Make a different choice";
            }
                
        }//switch
    }//while for gameOn
    return 0;
}
