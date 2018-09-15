/*******************************************************
 *  Name      : Michael Zabawa
 *  Student ID: 107522040
 *  Class     :  CSCI 2312
 *  Due Date  :  Apr. 4, 2018
 *******************************************************/
//  Board.cpp

#include<iostream>
#include "Board.h"

Board::Board(){//constructor
    nRow = 10;
    nCol = 10;
    std::vector<char> temp;
    for(int i = 0; i < nCol; i++)
        temp.push_back(' ');
    for(int j = 0; j < nRow; j++)
        board.push_back(temp);
}

bool Board::checkMark(int row, int col,char mark){//checks if location on board is mark
    if (board[row][col] == mark)
        return true;
    else
        return false;
}

void Board::placeMark(int row, int col, char mark){//puts mark in location on board
    board[row][col] = mark;
}

char Board::getMark(int row, int col){ // returns board mark at row col position
    return board[row][col];
}

void Board::printBoard(){
    std::cout << "\n----------------------------------------------\n";
    std::cout << "|    | A | B | C | D | E | F | G | H | I | J ";
    std::cout << "|\n----------------------------------------------\n";
    for(int row = 0; row < nRow; row++){
        if(row < 9){
            std::cout << "| "<< row + 1 << "  ";
        }
        else{
             std::cout << "| "<< row + 1 << " ";
        }
        for(int col = 0; col < nCol; col++){
            std::cout << "| " << board[row][col] << " ";
        }
        std::cout <<"|\n----------------------------------------------\n";
    }
}

void Board::clear(){ //restores board to empty
    for(int i = 0; i < nCol; i++){
        for(int j = 0; j < nRow; j++)
            board[i][j] = ' ';
    }
}

