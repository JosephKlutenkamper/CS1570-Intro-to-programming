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


int main()
{
  srand(time(NULL));
  int dim;
  int loc1;
  int loc2;
  int row;
  int column;
  int numtree;
  int move;
  char nm[MAXNAME];
  int fun = ZERO;
  int al = true;
  
  //constructor fetch
  do
  {
    cout << endl; 
    cout << "Please enter board dimensions:";
    cin >> dim;
    cout << endl << endl;
  }while(dim>MAXSIZE);
  
  //constructor fetch
  cout << "Please enter the name of the tailor:";
  cin  >> nm;
  cout << endl << endl;
  
  //constructor for tailor
  tailor tail(nm,fun,al);
  
  //constructor for town
  town vil(dim);
  
  //board display w/banner.
  cout << "--------------BOARD----------------"<< endl;
  cout << endl;
  cout << vil;
  
  //catches invalid input for placement
  do
  {
    cout << "Please enter the location (row,column) you" << endl;
    cout << "wish to have " << nm << " occupy" << endl;
    cout << "Row:";
    cin  >> loc1;
    cout << endl;
    cout << "Column:";
    cin  >> loc2;
    cout << endl;
  }while(tail.placeman(loc1,loc2,vil));
  
  cout << vil;
  //prompt for how many trees the user wishes to enter.
  cout << "How many trees would you like to place:";
  cin >> numtree;
  cout << endl << endl;
  
  //loop for getting trees
  for (int w = ZERO; w < numtree; w++)
  {
    cout << "Enter row for tree:";
    cin  >> row;
    cout << endl;
    cout << "Enter column for tree:";
    cin  >> column;
    cout << endl << endl;
    vil.placetree(row,column); 
  }
  
  
  cout << tail;
  //prompt for how many moves
  cout << "How many times would you like to randomly move:";
  cin >> move;
  cout << endl << endl;
  
  //moves the tailor
  for (int y = ZERO; y < move; y++)
  {
    tail.randwalk(vil);
    cout << vil;
    cout << endl;
    cout << endl;
  }
  
  //counts bumps display
  cout << "Bumps:" << tail.getbumps();
  cout << endl;  
     
  
  
  return 0;
}
