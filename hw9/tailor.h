//-----------------------------------------------------------------------------
//Programmer: Joseph Klutenkamper  Instructor: Dileep
//HW9: Creating classes for HW10
//Date: 4/18/2017
//Class: CS1570                    Section: C
//-----------------------------------------------------------------------------
//Program Description: Program will show use of classes used in homework
//                     10.
//-----------------------------------------------------------------------------
#ifndef TAILOR_H
#define TAILOR_H
#include "town.h"
class tailor
{
  private:
    //Variables for class 'tailor'
    char name[MAXNAME];
    int money;
    int where1;
    int where2;
    int bump;
    char loc;
    bool alive;
  
  public:
    //Description: Constructor that sets the values of money, alive 
    //           : and name to a value.
    //Pre        : Function needs the values to assign to a bool an int
    //           : and a char array.
    //Post       : Values for the type tailor will be set.
    tailor (const char nam[], const int funds, const bool dead);
    
    //Description: Fucntion that places the tailor in the middle.
    //Pre        : assigned variables for row and column and var of type town.
    //Post       : The location of the tailor in the town is recorded and
    //           : displayed.
    void placeme(town &vill);
    
    //Descritpion: Function will determine a place for the tailor to walk.
    //Pre        : Needs a town to traverse.
    //Post       : tailor will have changed locations.
    void randwalk(town &vill);
    
    //Description: overloaded opperator will output a type tailord.
    //Pre        : Defined variables that will be output.
    //Post       : tailor type will be output.
    friend ostream &operator<<(ostream &out, tailor &t);             
    
    //Description: Funtion will allow the user to input the original placement
    //           : of the tailor.
    //Pre        : Fucntion needs the values to place the tailor in.
    //Post       : Tailor's where1 and where2 will be the location of the tailor.
    bool placeman(int i, int b,town &vill);
    
    //Descritpion: Function will return the value for bumps.
    //Pre        : value for bumps
    //Post       : value for bumps returned.
    int getbumps();
     
};
#endif
