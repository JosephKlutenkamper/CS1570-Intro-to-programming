//-----------------------------------------------------------------------------
//Programmer: Joseph Klutenkamper  Instructor: Dileep
//HW9: Creating classes for HW10
//Date: 4/18/2017
//Class: CS1570                    Section: C
//-----------------------------------------------------------------------------
//Program Description: Program will show use of classes used in homework
//                   : 10.
//-----------------------------------------------------------------------------
#ifndef TOWN_H
#define TOWN_H
#include "genhead.h"

//Start of the proto type of class 'town'

class town
{
  private:
    //var only accessable in class town
    loc tow[MAXSIZE][MAXSIZE];

    //How big the grid is.
    short int max;

    //Number of houses in grid.
    short houses;

    //Number of bullies in grid.
    short bullies;

    //Description: This function clears all of the space in the 2-d charcter
    //           : array for the build function.
    //Pre        : Needs a 2-d char array.
    //Post       : Clears the array for the build fucntion.
    void clear();

    //Description: This function builds walls in the 2-d array that prevent
    //           : movement in the array past it.
    //Pre        : Funciton needs a cleared 2-d array.
    //Post       : Fucntion will build walls around the 2-d array.
    void build();

  public:

    //Description: This constructor sets the build and clear function to
    //           : build and clear within the given range.
    //Pre        : Needs an integer value for the new range.
    //Post       : The character array will cleared and built set to the
    //           : input dimensions.
    town();

    //Description: This function overloads the operator to incorperate
    //           : the class type as an output.
    //Pre        : Needs a type town to trigger.
    //Post       : Will display output of type town.
    friend ostream &operator<<(ostream &out, town &t);

    //Description: This function returns the value for max.
    //Pre        : Value for max is set.
    //Post       : Function returns value of max.
    int getmax();

    //Descritpion: Fucntion returns the value of the character.
    //Pre        : Class 'bully' and struct 'loc' need to be declared.
    //Post       : Character value assigned to the 2-d loc array will
    //           : be returned.
    char gettile(const int i, const int b){return tow[i][b].tile;};

    //Descritpion: This funciton sets a char in the 2-d array equal to the
    //           : location indicator of the tailor.
    //Pre        : Needs integer values for row and column.
    //Post       : Function will set a char value.
    void setchr(int i, int b, char lc);

    //Description: This function finds anything in the way and returns false
    //             if there is.
    //Pre        : Needs area to search
    //Post       : will return false if soemthing is there.
    bool check(int i, int b);

    //Description: This function removes the pants from the loc val.
    //Pre        : Class 'town' and struct 'loc' needs to be declared.
    //Post       : Pants will no longe be true in the loc val and returns
    //           : true
    bool buypants(const int row, const int colom);

    //Description: This function sets the tile equal to the ghost char.
    //Pre        : Town must be defined and needs row and coloumn.
    //Post       : Ghost will be in the tiles.
    void setghost(int row, int coloumn, char til);

    //Description: This funciton lets a tile be erased.
    //Pre        : Function needs row and coloumn.
    //Post       : Function will have tile erased.
    void ridtile(int row, int coloumn){tow[row][coloumn].tile=' ';};

};
#endif
