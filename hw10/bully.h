//-----------------------------------------------------------------------------
//Programmer: Joseph Klutenkamper  Instructor: Dileep
//HW9: Creating classes for HW10
//Date: 4/18/2017
//Class: CS1570                    Section: C
//-----------------------------------------------------------------------------
//Program Description: Program will show use of classes used in homework
//                     10.
//-----------------------------------------------------------------------------

#include "genhead.h"
#ifndef BULLY_H
#define BULLY_H

class bully
{
  private:
    string name[MAX_BULLY_NAME];
    short power;
    short punchprob;
    bool hit;

  public:
    //Description: constructor that sets initial values.
    //Pre        : function needs the class defined.
    //Post       : values will be initialized.
    bully();

    //Description: Function will return true if bully punches.
    //Pre        : Function needs class defined.
    //Post       : Function will have a bool returned.
    bool punch();

    //get funcion for power.
    short getpower(){return power;};

    //get function fot name.
    string getname();

    //get function for hit
    bool getpunch(){return hit;};

    //mutator funciton for hit.
    void setpunch(bool trufal){hit=trufal;};
};

#endif
