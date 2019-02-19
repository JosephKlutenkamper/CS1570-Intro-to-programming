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

pants::pants()
{
  location_row     =-1;
  location_coloumn =-1;
}

void pants::placeme(town &vill)
{
  bool redo=true;
  do
  {
    int move1=rand()%(vill.getmax()-1);
    int move2=rand()%(vill.getmax()-1);
    move1+=1;
    move2+=1;
    if(vill.check(move1,move2))
    {
      vill.ridtile(location_row, location_coloumn);
      location_row     = move1;
      location_coloumn = move2;
      vill.setghost(location_row, location_coloumn, PANTS);
      redo=false;
    }
  }while(redo);

  cout << endl;
  cout << "A ghost has been placed at"<<location_row<< ","<<location_coloumn
       <<endl;
  cout << endl;
}

void pants::chase(town &vill, tailor &mill)
{
  int if_move_chance;
  int move_chance;
  int row     = mill.getloc1();
  int coloumn = mill.getloc2();
  if_move_chance = rand()%HUNDPERC;
  move_chance = rand()%HUNDPERC;
  if(if_move_chance<=24)
  {
    if (location_coloumn==coloumn&&location_row==row)
    {
      kill(mill);
    }
    else if(location_coloumn!=coloumn&&location_row!=row&&move_chance<=49)
    {
      if(location_coloumn<coloumn&&
          vill.check(location_row, location_coloumn+INCREMENT))
      {
        location_coloumn+=INCREMENT;
      }
      else if(location_coloumn>coloumn&&
              vill.check(location_row, location_coloumn-DECREMENT))
      {
        location_coloumn-=DECREMENT;
      }
    }
    else if(location_coloumn!=coloumn&&location_row!=row&&move_chance>=49)
    {
      if(location_row<row&&vill.check(location_row+INCREMENT, location_coloumn))
      {
        location_row+=INCREMENT;
      }
      else if(location_row>row&&
               vill.check(location_row-DECREMENT, location_coloumn))
      {
        location_row-=DECREMENT;
      }
    }
    else if(location_coloumn!=coloumn&&location_row==row)
    {
      if (location_coloumn>coloumn&&
          vill.check(location_row, location_coloumn-DECREMENT))
      {
        location_coloumn-=DECREMENT;
      }
      else if(location_coloumn<coloumn&&
              vill.check(location_row, location_coloumn+INCREMENT))
      {
        location_coloumn+=INCREMENT;
      }

    }
    else if(location_coloumn==coloumn&&location_row!=row)
    {
      if(location_row>row&&
          vill.check(location_row-DECREMENT, location_coloumn))
      {
        location_row-=DECREMENT;
      }
      else if(location_row<row&&
              vill.check(location_row+INCREMENT,location_coloumn))
      {
        location_row+=INCREMENT;
      }
    }
    vill.setchr(location_row, location_coloumn, PANTS);
  }
}

void pants::kill(tailor &mill)
{
  cout << "A Ghost pants has killed the tailor.\n";
  cout <<endl;
  mill.makedead();
}
