//-----------------------------------------------------------------------------
//Programmer: Joseph Klutenkamper  Instructor: Dileep
//HW9: Creating classes for HW10
//Date: 4/18/2017
//Class: CS1570                    Section: C
//-----------------------------------------------------------------------------
//Program Description: Program will show use of classes used in homework
//                   : 10.
//-----------------------------------------------------------------------------
#include "town.h"

//clear function that removes any unwanted value and replaces them with actual
//values.---------------------------------------------------------------------
void town::clear()
{
  for (int i = INITAL; i <= max; i++)
  {
    for (int b = INITAL; b <= max; b++)
    {
      tow[i][b].tile=' ';
    }
  }
  return;
}

//Build function build a wall around the edge of the 2-d array.----------------
void town::build()
{

  //Places wall around grid.
  for(int i = INITAL; i <= max; i++)
  {
    for (int b = INITAL; b <= max; b++)
    {
      if(i==INITAL||i==max||b==INITAL||b==max)
      {
        tow[i][b].tile='W';
      }
    }
  }

  //Places houses in random locations.
  int temp  = INITAL;
  int temp2 = INITAL;
  for (int i = INITAL; i <= houses; i++)
  {
    temp  = rand()%(max-DECREMENT);
    temp2 = rand()%(max-DECREMENT);
    temp  += 1;
    temp2 += 1;

    tow[temp][temp2].tile='H';

  }

  //Places bullies only in spots where there are no houses.
  for (int i = INITAL; i <= bullies; i++)
  {
    temp  = rand()%(max-DECREMENT);
    temp2 = rand()%(max-DECREMENT);
    temp  += 1;
    temp2 += 1;

    if(tow[temp][temp2].tile=='H')
    {
      i--;
    }
    else
    {
      tow[temp][temp2].tile  = 'B';
      tow[temp][temp2].pants = true;
    }
  }

  return;
}

//Construtor that creates the new max.-----------------------------------------
town::town ()
{
  max     = BOARD;
  bullies = BULLIES;
  houses  = HOUSES;
  clear();
  build();
  return;
}

//Operator overload
ostream& operator << (ostream &out, town &t)
{
  for (int i = INITAL; i <= t.max; i++)
  {
    out << "|";
    for (int b = INITAL; b <= t.max; b++)
    {
      if(b==t.max)
      {
        out << t.tow[i][b].tile;
      }
      else
      {
        out << t.tow[i][b].tile << " ";
      }
    }
    cout << "|";
    out << endl;
  }
  out << endl;
  return out;
}



//returns value for max--------------------------------------------------------
int town::getmax()
{
  return static_cast<int>(max);
}

//function sets a char val in the 2-d array to the location char of tailor.
void town::setchr(int i, int b, char lc)
{
  for (int j = INITAL; j <= max; j++)
  {
    for (int p = INITAL; p <= max; p++)
    {
      if (tow[j][p].tile==lc)
      {
        tow[j][p].tile=' ';
      }
    }
  }
  tow[i][b].tile=lc;
  return;
}

//Fucntion finds anything in the way and returns false if there is.------------
bool town::check(int i, int b)
{
  if (tow[i][b].tile=='W'||tow[i][b].tile=='B'||i > max||b > max||
      tow[i][b].tile=='H'||tow[i][b].tile=='M')
  {
    return false;
  }
  else
  {
    return true;
  }

}




//Function will return true if there are pants and it will remove the
//pants.-----------------------------------------------------------------------
bool town::buypants(const int row, const int colom)
{
  bool temp;
  int chance=rand()%HUNDPERC;
  if(chance>=SEVENPERC)
  {
    if (tow[row][colom].pants)
    {
      tow[row][colom].pants=false;
      temp=true;
    }
  }
  else
  {
    temp=false;
  }
  return temp;
}

//function sets a char val in the 2-d array to the location char of ghost.-----
void town::setghost(int row, int coloumn, char til)
{
  tow[row][coloumn].tile=til;
  return;
}
