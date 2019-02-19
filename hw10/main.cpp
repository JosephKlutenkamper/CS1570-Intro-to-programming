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

  //local types
  town  vill;
  tailor mill(NAME,TAILOR_CHAR);
  bully bul;
  pants ghost[GHOST_MAX];
  mill.placeman(vill);

  //Display first
  cout << vill;
  cout << mill;

  //loop display that displays 35 times
  do
  {
    usleep(SLEEPVAL);
    count++;
    mill.randwalk(vill);
    mill.action(vill,bul);

    //Chceckc if the bully punched and of there are less than 3 ghosts and
    //adds one if they are both true.
    if(bul.getpunch()&&ghostCount<GHOST_MAX)
    {
      ghost[ghostCount].placeme(vill);
      ghostCount++;
      bul.setpunch(SETPUNCHFALSE);
      cout << "A Ghost is chasing the tailor!\n";
    }

    //loop that allows the ghost to chase the tailor.
    if(ghostCount!=INITAL)
    {
      for (int i=INITAL; i<ghostCount; i++)
      {
        ghost[i].chase(vill,mill);

      }
    }

    //Stops output after 35 turns.
    if(count<=STOP)
    {
      cout << mill;
      cout << endl;
      cout << vill;
    }

  //constinues game until he is dead or if there reaches a turn past 1000
  } while(mill.getalive()&&count<=MAX_TURN);

  //Death display.
  cout << mill;
  cout << vill;


  return 0;
}
