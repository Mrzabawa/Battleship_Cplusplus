/*******************************************************
 *  Name      : Michael Zabawa
 *  Student ID: 107522040
 *  Class     :  CSCI 2312
 *  Due Date  :  Apr. 4, 2018
 *******************************************************/
//  watervehicle.h


#ifndef watervehicle_h
#define watervehicle_h

#include <string>
#include <vector>
//chose to keep my namespace clean for the classes to increase modularity

class Watervehicle{
private:
    std::string typeOfShip;
    char mark;
    int lengthOfShip;
    int startingRow;
    int startingCol;
    char orentation;
    int hit;
    bool sunk;
    
public:
    Watervehicle(){;}//default constructor
    Watervehicle(std::string _typeOfShip);
    ~Watervehicle(){;}
    
    //getters and setters functions not in cpp file
    std::string shipType() {return typeOfShip;}
    char shipMark() {return mark;}
    int sizeOfShip() {return lengthOfShip;}
    void setRow(int _startingRow) {startingRow = _startingRow;}
    int getStartRow() {return startingRow;}
    void setCol(int _startingCol) {startingCol = _startingCol;}
    int getStartCol() {return startingCol;}
    char getOrentation() {return orentation;}
    void setOrentation(char _orentation){orentation = _orentation;}
    void setHit(int _hit) {hit = _hit;}
    bool is_sunk(){return sunk;}
    
    //precondition:shots fired
    //postcondition:increases hit for the ship that was hit. If hit == size reports sunk
    void gotHit();
    
    };
#endif /* watervehicle_h */
