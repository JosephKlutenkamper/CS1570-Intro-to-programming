//-----------------------------------------------------------------------------
//Programmer: Joseph Klutenkamper  Instructor: Dileep
//HW9: Creating classes for HW10
//Date: 4/18/2017
//Class: CS1570                    Section: C
//-----------------------------------------------------------------------------
//Program Description: Program will show use of classes used in homework
//                   : 10.
//-----------------------------------------------------------------------------
#ifndef TAILOR_H
#define TAILOR_H
#include "town.h"
#include "bully.h"

class tailor
{
  private:
    //Variables for class 'tailor'
    char name[MAXNAME];
    short pants_num;
    short money;
    int health;
    int where1;
    int where2;
    int bump;
    char loca;
    bool alive;

  public:
    //Default concstructor
    tailor(){};


    //Description: Constructor that sets the values of money, alive
    //           : and name to a value.
    //Pre        : Function needs the values to assign to a bool an int
    //           : and a char array.
    //Post       : Values for the type tailor will be set.
    tailor (const char nam[], const char locat);

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
    void placeman(town &vill);

    //Descritpion: Function will return the value for bumps.
    //Pre        : value for bumps
    //Post       : value for bumps returned.
    int getbumps();

    //Descritpion: Function will check to see if there is a house or a
    //           : Bully that will effect the tailor.
    //Pre        : Function needs to take a type town.
    //Post       : Funciton will manipulate the object acordingly.
    void action(town &vill, bully &bul);

    //Description: Function preforms the operations on tailor class after
    //           : he is punnched.
    //Pre        : Funciton needs an object bully and an object town
    //Post       : Fucntion will nothing but have objects changed.
    void knock (town &vill, bully &bul);

    //Description: Funtion finds if health is below INITAL and if so sets
    //           : alive bool to false or if he has sold all his pants.
    //Pre        : Function needs a class tailor to be initialized.
    //Post       : Function will return nothing but have bool alive
    //           : changed to false.
    void checkdead();

    //Description: Function returns the bool value for alive.
    //Pre        : Function needs a value for alive.
    //Post       : Function returns a bool value for alive.
    bool getalive(){return alive;};

    //Description: Function returns the value for where1.
    //Pre        : Function needs a value for where1.
    //post       : Function returns the value of where1.
    int getloc1(){return where1;};

    //Description: Function returns the value for where2.
    //Pre        : Function needs a value for where2.
    //post       : Function returns the value of where2.
    int getloc2(){return where2;};

    //Description: Function makes the tailor bool var for alive false.
    //Pre        : Class bool variable for alive needs to be true.
    //Post       : Bool for alive will be false.
    void makedead(){alive=false;};

    //Description: Function makes a sale my subtracting one pants and
    //           : adding 10 money.
    //Pre        : Money and pants_num need to be initialized.
    //Post       : Money will be incremented by 10 and pants_num by 1.
    void sell();




};
#endif
