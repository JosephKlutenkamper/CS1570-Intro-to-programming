//---------------------------------------------------------------------------
//Programmer: Joseph Klutenkamper   Instructor: Dileep
//HW7: Stock database
//Date: 3/22/2017
//Class: CS1570                     Section: C
//---------------------------------------------------------------------------
//Description: Program will use random numbers to generate a theoretical
//           : database of pants. The program will then have the user choose
//           : a pair and then calculate how much the user will owe.
//---------------------------------------------------------------------------
#include "functions.h"

int main()
{
  const int COLORMAX      =   7;
  const string COLOR[COLORMAX]  ={"Black","Blue","Red","Rainbow","Checkered",
                                 "Electric Green","Polka dot"};
  const int PANTSMAX      = 100;
  const int PANTMAX       =  21; 
  inventory pants[PANTSMAX];
  pants_of_size pant[PANTMAX];
  
  //Greet function that greets user.
  greet();
  
  //Fills inventory array with with random values.
  fill_array(pants, PANTSMAX);
  
  //Fills pants array with all color values of inventory for waist sizes 20-40.
  ex_array(pants, pant, PANTSMAX, PANTMAX);
  
  //Function sorts inventory array to display all the values of the inventory
  //in decending value.
  sort(pants, PANTSMAX);
  
  //Function reads user input and preforms comparisons to check inventory. 
  read_input(pants, PANTSMAX, pant);
  
  //Function will display a signoff message to user.
  signoff();   

  return 0;
}
