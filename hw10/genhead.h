//-----------------------------------------------------------------------------
//Programmer: Joseph Klutenkamper  Instructor: Dileep
//HW9: Creating classes for HW10
//Date: 4/18/2017
//Class: CS1570                    Section: C
//-----------------------------------------------------------------------------
//Program Description: Program will show use of classes used in homework
//                     10.
//-----------------------------------------------------------------------------
#ifndef GENHEAD_H
#define GENHEAD_H
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
using namespace std;

//Constants used int the program
const int  MAX_HEALTH = 100;
const int  SLEEPVAL = 200000;
const int  TOWN_SIZE = 17;
const int  INCREMENT = 1;
const int  DECREMENT =1;
const int   MAXSIZE = 25;
const int   MAX_BULLY_NAME = 4;
const int   INITAL=0;
const int   MAXNAME = 30;
const int   BUY = 10;
const int   MAX_TURN = 1000;
const int   GHOST_MAX = 3;
const int   DAMAGE = 10;
const int   STOP = 35;
const int   FIFTYPERC = 49;
const int   SEVENPERC = 69;
const int   EIGHTYPERC = 79;
const int   HUNDPERC = 99;
const int   HOUSES = 40;
const int   BULLIES = 10;
const int   BOARD = 17;
const short PANTS_SALE = 1;
const short START_PANTS  =30;
const char  TAILOR_CHAR='M';
const char  BULLY ='B';
const char  HOUSE ='H';
const char  PANTS ='P';
const char  NAME[MAXSIZE] = "Millhouse";
const bool  SETPUNCHTRUE = true;
const bool  SETPUNCHFALSE = false;
const bool  ALIVE = true;
const bool  DEAD = false;
//decleration of struct loc
struct loc
{
  char tile;
  bool pants;
};



#endif
