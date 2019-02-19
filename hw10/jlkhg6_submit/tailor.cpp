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
tailor::tailor(const char nam[], const char locat)
{
  strcpy(name, nam);

  money=rand()%(21)+20;
  pants_num=START_PANTS;
  where1=-DECREMENT;
  where2=-DECREMENT;
  alive=ALIVE;
  health=HUNDPERC;
  loca=locat;
  bump = INITAL;
  cout << health;

  return;
}

//Operator overload.
ostream& operator <<(ostream &out, tailor &t)
{
  if (t.alive)
  {
    out << t.name <<" is alive and at ("<< t.where1+INCREMENT << ","
        << t.where2+INCREMENT << ")"<<" has "<<t.pants_num<<" pants "<<
        t.money<<" money and "<<t.health<<" health";
  }
  else
  {
    out << t.name <<" is  dead and at ("<< t.where1+INCREMENT << ","
        << t.where2+INCREMENT << ")\n";
  }
  return out;
}


//Function will randomly walk in a random direction.
void tailor::randwalk(town & vill)
{
  const int MAXIM=4;
  const int RAN1=0;
  const int RAN2=1;
  const int RAN3=2;
  const int RAN4=3;

  int direction = INITAL;
  direction = rand()%MAXIM;
  if(direction==RAN1)
  {
    where1-=1;
    if(vill.check(where1,where2))
    {
      vill.setchr(where1,where2,loca);
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
      vill.setchr(where1,where2,loca);
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
      vill.setchr(where1,where2,loca);
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
      vill.setchr(where1,where2,loca);
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
void tailor::placeman(town &vill)
{
  bool redo=true;

  where1 = rand()%(vill.getmax()-DECREMENT);
  where2 = rand()%(vill.getmax()-DECREMENT);
  where1 += 1;
  where2 += 1;

  do
  {
    if (vill.check(where1,where2))
    {
      vill.setchr(where1, where2, loca);
      redo=false;
    }
  }while(redo);

}

//Fucntion returns bumps.
int tailor::getbumps()
{
  return bump;
}

//Fucntion that manipulates the object taylor if there is a bully
void tailor::action(town &vill, bully &bul)
{
  if(!vill.check(where1+INCREMENT, where2))
  {
    if(vill.gettile(where1+INCREMENT, where2)==BULLY)
    {
      knock(vill, bul);
    }
    if(vill.gettile(where1+INCREMENT, where2)==HOUSE)
    {
      if(vill.buypants(where1+INCREMENT, where2))
      {
        sell();
      }
    }
  }
  if(!vill.check(where1-DECREMENT, where2))
  {
    if(vill.gettile(where1-DECREMENT, where2)==BULLY)
    {
      knock(vill, bul);
    }
    if(vill.gettile(where1-DECREMENT, where2)==HOUSE)
    {
      if (vill.buypants(where1-DECREMENT, where2))
      {
        sell();
      }
    }
  }
  if(!vill.check(where1, where2+INCREMENT))
  {
    if(vill.gettile(where1, where2+INCREMENT)==BULLY)
    {
      knock(vill, bul);
    }
    if(vill.gettile(where1, where2+INCREMENT)==HOUSE)
    {
      if(vill.buypants(where1, where2+INCREMENT))
      {
        sell();
      }
    }
  }
  if(!vill.check(where1, where2-DECREMENT))
  {
    if(vill.gettile(where1, where2-DECREMENT)==BULLY)
    {
      knock(vill, bul);
    }
    if(vill.gettile(where1, where2-DECREMENT)==HOUSE)
    {
      if(vill.buypants(where1, where2-DECREMENT))
      {
        sell();
      }
    }
  }
  vill.setchr(where1, where2, loca);
  checkdead();
}

//Funciton will knock the tailor to a free spot.
void tailor::knock(town &vill, bully &bul)
{
  float steal;
  int difference;
  bool redo = true;
  if (bul.punch())
  {
    health=health-DAMAGE;
    steal = static_cast<float>(bul.getpower())/100;
    difference = steal * static_cast<float>(money);
    money-=difference;

    cout << endl;
    cout << bul.getname()<< "has punched the poor tailor making him lose "
         <<DAMAGE<<" health and "<< difference << " money.";
    cout << endl;

    do
    {
      int move1=rand()%(vill.getmax()-DECREMENT);
      int move2=rand()%(vill.getmax()-DECREMENT);
      move1+=1;
      move2+=1;
      if(vill.check(move1,move2))
      {
        where1=move1;
        where2=move2;
        redo=false;
      }
    }while(redo);
  }
}

//Checks to see if tailor is dead or game ends.
void tailor::checkdead()
{
  if(health<=INITAL)
  {
    cout << name << "Has died of a bully attack!"<<endl;
    alive=false;
  }
  if(pants_num<=INITAL)
  {
    cout << name << "Has run out of pants to sell!"<<endl;
    alive=false;
  }
}

//Function that sells pants.
void tailor::sell()
{
  money+=BUY;
  pants_num-=PANTS_SALE;

  return;
}
