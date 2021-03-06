//-----------------------------------------------------------------------------
//Programmer: Joseph Klutenkamper   Instructor: Dileep
//HW7: Stock database
//Date: 3/22/2017 
//Class: CS1570                     Section: C
//-----------------------------------------------------------------------------
//Description: Program will use random numbers to generate a theoretical 
//           : database of pants. The program will then have the user choose
//           : a pair and then calculate how much the user will owe.
//-----------------------------------------------------------------------------
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

//Constant variables needed in preforming calulculations and
//functions.
const int COLORMAX2           =  7;
const string COLOR[COLORMAX2] = {"Black","Blue","Red","Rainbow","Checkered",
                                 "Electric Green","Polka dot"};
const int WAISTMIN            = 20;
const int WAISTMAX            = 40;
const int INSEAMMIN           = 14;
const int INSEAMMAX           = 45;
const int COLORMIN            =  0;
const int COLORMAX            =  6;
const int LEVELER             = 20;
const int compare             =  2;
const int high_water_charge   = 40;





//Description: Structure that has the values used to determine pants.
//Pre        : Const string array muct be present.
//Post       : Structure will help idetify elements in array.
struct inventory 
{
  int waist;
  int inseam;
  int color;
  bool availibility;
 
};

//Description: Structure that holds values for color and waist.
//Pre        : String color array must be present.
//Post       : Structure will help identify elements in an array.     
struct pants_of_size
{
  int waist;
  int color[COLORMAX2];
};




//Description: Function will provide the reader with a greeting.
//Pre        : None.
//Post       : A greeting will be displayed for the user.
void greet();

//Description: Function will fill an array with random numbers.
//Pre        : An array needs to be passed down of type inventory.
//Post       : The array will be filled with values of random numbers.
void fill_array(inventory array[], int max);  

//Description: Function will condense the inventory array to fit waist size
//           : ease of access.
//Pre        : Array of type inventory and pants_of_size as well as max
//           : for both.
//Post       : Array of type pants_of_size will be filled.
void ex_array(inventory arraya[], pants_of_size arrayb[], int maxa, int maxb);

//Description: Function will sort the inventory array based on waist.
//Pre        : Max of array and array of type inventory.
//Post       : Array will be sorted in ascending waist size.
void sort(inventory array[], int max);

//Description: Function will display the sorted inventory array.
//Pre        : Array of type inventory and max.
//Post       : Array will be displayed for user. 
void display(inventory array[], int max);

//Description: Function will ask for user input and display options.
//Pre        : Array of type pants_of_size and inventory, and max value.
//Post       : Function will take user input and display stock accordingly.
void read_input(inventory arraya[], int maxa, pants_of_size arrayb[]);
                

//Description: Function will take user input for which pants they wanted
//           : and display cost.
//Pre        : Array of type inventory and choice.
//Post       : Cost will be displayed.
void cost(inventory array[], int index);

//Description: Function will display a signoff message. 
//Pre        : none.
//Post       : A signoff message will be displayed.
void signoff();        

#endif
