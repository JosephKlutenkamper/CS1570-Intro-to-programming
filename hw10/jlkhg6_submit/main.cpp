//-----------------------------------------------------------------------------
//Programmer: Joseph Klutenkamper  Instructor: Dileep
//HW9: Creating classes for HW10
//Date: 4/18/2017
//Class: CS1570                    Section: C
//-----------------------------------------------------------------------------
//Program Description: Program will show use of classes used in homework
//                     10.
//-----------------------------------------------------------------------------
#include "pants.h"
#include "unistd.h"

//Start of main
int main()
{
  srand(time(NULL));

  //local varibales
  int   count=INITAL;
  int   ghostCount=INITAL;
  town  vill;
  tailor mill(NAME,TAILOR_CHAR);
  bully bul;
  pants ghost[GHOST_MAX];
  mill.placeman(vill);
  do
  {
    usleep(1000000);
    count++;
    mill.randwalk(vill);
    mill.action(vill,bul);
    if(ghostCount!=INITAL)
    {
      for (int i=INITAL; i<ghostCount; i++)
      {
        ghost[i].chase(vill,mill);
      }
    }
    if(bul.getpunch()&&ghostCount<=GHOST_MAX)
    {
      ghost[ghostCount].placeme(vill);
      ghostCount++;
      bul.setpunch(SETPUNCHFALSE);
    }
    do
    {
      cout << mill;
      cout << endl;
      cout << vill;
    }while(count<=STOP);
  } while(mill.getalive()&&count<=MAX_TURN);

  cout << mill;
  cout << vill;


  return 0;
}
