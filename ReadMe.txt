*******************************************************
*  Name      : Michael Zabawa         
*  Student ID: 107522040                
*  Class     :  CSCI 2312           
*  Due Date  :  Apr. 4, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

Basic functionality for the classic battleship game. 
User sets up the board by file and then the computer sets ship randomly.
After the game is set up the player and computer takes turns firing at each other.
If a player computer of human makes a hit an additional call is then made.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
	Driver for the player, board, water vehicle class

       Player.h
	Holds the definitions for the Player class.
       Player.cpp
	Implements the definition in the h file. Functions for checking if a 
	ship is already located in the desired position. Setting up the board 
	and placing ships along with shooting torpedos.

       ComputerPlayer.h
	Derived class of Player and holds the definitions for the ComputerPlayer class.
       ComputerPlayer.cpp
	Functions for setting up the game and to fire a torpedo. These functions randomly
	selects the location and orientation.

       HumanPlayer.h
	Derived class of Player and holds the definitions for the HumanPlayer class
       HumanPlayer.cpp
	Functions to set up the game for the player by way of file and to fire torpedos. 

       watervehicle.h
	Holds the definitions for the Watervehicle class.
       watervehicle.cpp 
	Implementations for the functions that get the placement of the ship and 
	to mark the ship hit.

       Board.h
	Holds the definitions for the Board class.
       Board.cpp
   	Implements basic functions to check the mark, change the mark, 
	and return the mark at requested locations. Also clears the board and
	prints the board with grid pattern and index.

       MyException.h
	Holds three exception classes: fileFailedToOpen, shipsMissing, incorrectInout.
	fileFailedToOpen will be thrown if the file failed to open.
	shipsMissing will be thrown if there is an error with the file input.
	incorrectInout will be thrown if the user inputs incorrectly.

       gameinstrucoions.txt
	Holds a message to the user about the rules and expected formats that the
	program needs to run.

       ship_placement.csv
	Holds the ship placements that is defined by the user.

*******************************************************
*  Status of program
*******************************************************

   The program runs successfully. The functionality is after a hit the user 
   and computer will take additional shots until a miss or the game is won.
   Each ship requires that it is fully hit to be sunk as per the extra credit.
   I was not able to finish the additional logic for the computer to track hits
   and adjust the next shots accordingly. 
   
   The program was developed and tested on Xcode g++.  It was 
   compiled, run, and tested on csegrid.ucdenver.pvt.

