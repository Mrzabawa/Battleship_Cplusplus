/*******************************************************
 *  Name      : Michael Zabawa
 *  Student ID: 107522040
 *  Class     :  CSCI 2312
 *  Due Date  :  Apr. 4, 2018
 *******************************************************/
//  Board.h


#ifndef Board_h
#define Board_h
#include <vector>
#include <string>

class Board{
private:
    std::vector< std::vector<char> > board;
    int nRow;
    int nCol;
    
public:
    Board();//constructor
    ~Board(){;}//destruct
    
    //getters and setters
    int getNrow() {return nRow;}
    int getNcol() {return nCol;}
    
    //precondition: Board
    //postcondition: if mark is at location on board returns true else false
    bool checkMark(int row, int col, char mark);
    
    //precondition: Board
    //postcondition: puts mark at location row and col on board
    void placeMark(int row, int col, char mark);
    
    //precondition: Board
    //postcondition: returns mark at location row and col
    char getMark(int row, int col);
    
    void printBoard();
    void clear();
};

#endif /* Board_hp */
