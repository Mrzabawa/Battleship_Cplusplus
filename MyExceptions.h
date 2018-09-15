/*******************************************************
 *  Name      : Michael Zabawa
 *  Student ID: 107522040
 *  Class     :  CSCI 2312
 *  Due Date  :  Apr. 4, 2018
 *******************************************************/
//  MyExceptions.h

#ifndef MyExceptions_h
#define MyExceptions_h
#include <exception>
#include <string>
class fileFailedToOpen:public std::exception{
private:
    std::string fileName;
public:
    fileFailedToOpen(std::string _fileName){fileName = _fileName;}
    std::string info() const {return fileName;}
    const char* what() const noexcept {return "File failed to open!\n";}
};

class shipsMissing:public std::exception{
private:
    std::string shipName;
public:
    shipsMissing(std::string _shipName){shipName = _shipName;}
    std::string info() const {return shipName;}
    const char* what() const noexcept {return "ship was not placed!\n";}
};

class incorrectInput:public std::exception{
public:
    incorrectInput(){;}
    const char* what() const noexcept {return "Wrong Input!\n";}
};


#endif /* MyExceptions_h */
