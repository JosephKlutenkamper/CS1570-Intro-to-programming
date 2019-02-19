//-----------------------------------------------------------------------------
//Programmer: Joseph Klutenkamper  Instructor: Dileep
//HW9: Creating classes for HW10
//Date: 4/18/2017
//Class: CS1570                    Section: C
//-----------------------------------------------------------------------------
//Program Description: Program will show use of classes used in homework
//                     10.
//-----------------------------------------------------------------------------

#include "tailor.h"
#ifndef PANTS_H
#define PANTS_H

class pants
{
  private:
    int location_row;
    int location_coloumn;

  public:
    //Description: Default constructor that sets both locations to -1.
    //Pre        : Function needs class pants defined.
    //Post       : Funciton will have values for location initialized.
    pants();

    //Description: Funciton will place the pants in the town in a random spot
    //           : and set its location eqaul to its grid location.
    //Pre        : Funcion needs locations initialized and a class pants
    //           : and town initialized.
    //Post       : Function returns nothing but has values for location set
    //           : equal to its place in town.
    void placeme (town &vill);

    //Description: Function will chase the tailor by taking its location and
    //           : compairing it to it's own.
    //Pre        : Functiion needs to take a type town and a type tailor by
    //           : value and simulates a chase.
    //Post       : The location of pants will be closer to the location of
    //           : tailor.
    void chase   (town &vill, tailor &mill);

    //Description: Function will set the tailor's alive bool to false.
    //Pre        : Funciton needs a type tailor.
    //Post       : Tailor will be dead
    void kill    (tailor &mill);

    int getloca(){return location_row;};
    int getlocb(){return location_coloumn;};
};

#endif
