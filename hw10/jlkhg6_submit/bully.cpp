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


//Bully constructor
bully::bully()
{
  int chance_name;
  ifstream in;
  in.open("bully.dat");

  string nam[MAX_BULLY_NAME];

  for(int i=INITAL; i<=MAX_BULLY_NAME; i++)
  {
    while(in>>nam[i])
    {
      in >> nam[i];
    }
  }

  in.close();

  chance_name=rand()%(MAX_BULLY_NAME-1);

  name=nam[chance_name];

  power=rand()%(21)+30;

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
