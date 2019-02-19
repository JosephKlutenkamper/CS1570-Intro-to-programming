//-----------------------------------------------------------------------------
//Programmer: Joseph Klutenkamper  Instructor: Dileep
//HW9: Creating classes for HW10
//Date: 4/18/2017
//Class: CS1570                    Section: C
//-----------------------------------------------------------------------------
//Program Description: Program will show use of classes used in homework
//                     10.
//-----------------------------------------------------------------------------

#include "bully.h"

//Bully constructor-----------------------------------------------------------
bully::bully()
{
  //Grabs a name to put into an array for the bullies.
  ifstream in;
  in.open("bully.dat");

  string nam[MAX_BULLY_NAME];
  int count;
  for(int i=INITAL; i<=MAX_BULLY_NAME; i++)
  {
      in >> name[i];
      count=i;
  }

  cout <<endl;
  cout <<endl;
  cout <<endl;
  cout <<count;
  cout <<endl;
  cout <<endl;
  cout <<endl;

  hit=SETPUNCHFALSE;

  in.close();

  //Finds the power of thr bully
  power=rand()%(21)+30;

  //Makes a punch probability of 80%
  punchprob=EIGHTYPERC;
}

//Punch funciton
bool bully::punch()
{
  int chance;
  chance=rand()%HUNDPERC;
  if(chance<=punchprob)
  {
    hit=SETPUNCHTRUE;
    return true;
  }
  else
  {
    return false;
  }
}

//Get name function for bully.
string bully::getname()
{
  int chance_name;
  //makes a random number for the index of the array of bullies.
  chance_name=rand()%(MAX_BULLY_NAME-1);

  return name[chance_name];
}
