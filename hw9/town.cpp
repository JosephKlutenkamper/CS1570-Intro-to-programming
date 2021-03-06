//-----------------------------------------------------------------------------
//Programmer: Joseph Klutenkamper  Instructor: Dileep
//HW9: Creating classes for HW10
//Date: 4/18/2017
//Class: CS1570                    Section: C
//-----------------------------------------------------------------------------
//Program Description: Program will show use of classes used in homework
//                     10.
//-----------------------------------------------------------------------------
#include "town.h"

//clear function that removes any unwanted value and replaces them with actual
//values.
void town::clear()
{
  for (int i = ZERO; i <= max; i++)
  {
    for (int b = ZERO; b <= max; b++)
    {
      tow[i][b]='.';
    }
  }
  return; 
}

//Build function build a wall around the edge of the 2-d array.
void town::build()
{
  for(int i = ZERO; i <= max; i++)
  {
    for (int b = ZERO; b <= max; b++)
    {
      if(i==ZERO||i==max||b==ZERO||b==max)
      {
        tow[i][b]='W';
      }
    }
  }
  return;
}

//Construtor that creates the new max.
town::town (int newmax)
{
  max=newmax-1;
  clear();
  build();
  return;
}

//Operator overload
ostream& operator << (ostream &out, town &t)
{
  for (int i = ZERO; i <= t.max; i++)
  {
    out << "|";
    for (int b = ZERO; b <= t.max; b++)
    { 
      if(b==t.max)
      {
        out << t.tow[i][b];    
      }
      else
      {   
        out << t.tow[i][b] << " ";
      }
    }
    cout << "|";
    out << endl;
  }
  return out;
}



//returns value for max
int town::getmax()
{
  return max;
}

//function sets a char val in the 2-d array to the location char of tailor.
void town::setchr(int i, int b, char lc)
{
  for (int j = ZERO; j <= max; j++)
  {
    for (int p = ZERO; p <= max; p++)
    {
      if (tow[j][p]==lc)
      {
        tow[j][p]='.';
      }
    } 
  }
  tow[i][b]=lc;
  return;
}

//Fucntion finds anything in the way and returns false if there is.
bool town::check(int i, int b)
{
  if (tow[i][b]=='W'||tow[i][b]=='T'||i > max||b > max)
  {
    return false;
  }
  else
  {
    return true;
  }
}

//Function places trees in the array.
void town::placetree(int i, int b)
{
  int j;
  int p;
  j=i-1;
  p=b-1;
  tow[j][p]='T';
  return;
} 
