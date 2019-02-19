//-----------------------------------------------------------------------------
//Programmer: Joseph Klutenkamper   Instructor: Dileep
//Assignment6: calculator using functions outside of main.
//Date: 3/10/2017     
//Class: CS1570                     Section: C
//-----------------------------------------------------------------------------
#include <iostream>
#include "functions.h"
using namespace std;


int main()
{
  bool redo=true;
  int choice;
  do
  {
    //Menu option.
    choice=menu();
    switch (choice)
    {
      case 1:
        
        //Function calculates and shows factorial
        showfact();
        
        break;
        
      case 2:
        
        //function that calculates and shows exponentiation.
        exponentiate();
         
        break;
        
      case 3:
        
        //Function that calculates and shows sine of X. 
        sinx();
        
        break;
        
      case 4:
       
        //Function that calculates and shows the root of a given input.
        findroot();
       
        break;
        
      case 5:
      
        //function that finds cosine of a given input
        findcos();
        
        break;
        
      case 6:
        
        //Function that displays a signoff message.
        signoff();
        
        redo=false;
        break;
        
      default:
      
      cout << "How did you even get here?\n"; 
    } 
  }while(redo);
  
  return 0;
}
