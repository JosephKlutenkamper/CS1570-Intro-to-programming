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
#include <ctime>
#include <cstdlib>

//Constructor that sets values.
tailor::tailor(const char nam[], const int funds, const bool dead)
{
  strcpy(name, nam);
  money=funds;
  alive=dead;
  loc='L';
  bump = ZERO;
  
  return;
}

//Operator overload.
ostream& operator<<(ostream &out, tailor &t)
{
  if (t.alive)
  {
    out << t.name <<" is alive and at ("<< t.where1+1 << ","
        << t.where2+1 << ")\n";
  }
  else
  {
    out << t.name <<" is  dead and at ("<< t.where1+1 << ","
        << t.where2+1 << ")\n";
  }
  return out;
}


//Fucniton places the tailor int the middle of the grid.
void tailor::placeme(town &vill)
{
  int half;
  half = vill.getmax()/2;
  half-=1;
  vill.setchr(half, half, loc);
  where1=half;
  where2=half;
  return;
  
}

//Function will randomly walk in a random direction.
void tailor::randwalk(town & vill)
{ 
  const int MAXIM=4;
  const int RAN1=0;
  const int RAN2=1;
  const int RAN3=2;
  const int RAN4=3;
  int direction = ZERO; 
  direction = rand()%MAXIM;
  if(direction==RAN1)
  {
    where1-=1;
    if(vill.check(where1,where2))
    {
      vill.setchr(where1,where2,loc);
      cout << name << " Moved up."<<endl;
    }
    else
    {
      where1+=1;
      bump++;
      cout << name << " bumped something.";
      cout << endl; 
    }
  }
  if(direction==RAN2)
  {
    where1+=1;
    if(vill.check(where1,where2))
    {
      vill.setchr(where1,where2,loc);
      cout << name << " moved down."<<endl; 
    }
    else
    {
      where1-=1;
      bump++;
      cout << name << " bumped something.";
      cout << endl;
    } 
  }
  if(direction==RAN3)
  {
    where2+=1;
    if(vill.check(where1,where2))
    {
      vill.setchr(where1,where2,loc);
      cout << name << " moved to the right." << endl;
    }
    else
    {
      where2-=1;
      bump++;
      cout << name << " bumped something.";
      cout << endl;
    }
  }
  if(direction==RAN4)
  {
    where2-=1;
    if(vill.check(where1,where2))
    {
      vill.setchr(where1,where2,loc);
      cout << name << " moved to the left." << endl;
    }
    else
    {
      where2+=1;
      bump++;
      cout << name << " bumped something.";
      cout << endl;
    }
  }
  return;
}

//Function lets user place the tailor in the 2-d array
bool tailor::placeman(int i, int b, town &vill)
{
  where1=i-1;
  where2=b-1;
  bool redo=true;
  if (vill.check(where1,where2))
  {
    vill.setchr(where1,where2,loc);
    redo = false;
  }
  else
  {
    cout << "You may not place here.";
    cout << endl;
  }
   
  return redo;
}

//Fucntion returns bumps.
int tailor::getbumps()
{
  return bump;
}
