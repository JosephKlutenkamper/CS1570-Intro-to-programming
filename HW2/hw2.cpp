//-----------------------------------------------------------------------------
//Programmer: Joseph Klutenkamper   Instructor:Dileep
//Homework 2: Millhouse's pill calculator
//Date: 2/3/2017
//Class: CS1570                     Section:C
//-----------------------------------------------------------------------------
#include <iostream>
using namespace std;

const float soyfact = 1.9;
const float tatpois = 3.5;

int main()
{
  int classes;
  int hrsgame;
  float soycons;
  int numpills;
  int tat;
  cout << "Welcome, Millhouse, to your pill-computer\n";
  cout << endl;
  cout << "Please eneter the following information:\n";
  cout << "   # classes you studied:";
  cin >> classes;
  cout << "   # hrs gaming:";
  cin >> hrsgame;
  cout << "   cups soy consumed:";
  cin >> soycons;
  cout << "   tatto yesterday?(1-yes,0-no):";
  cin >> tat;
  cout << endl;
  
  numpills = (static_cast<float>(classes)/hrsgame)
            +(static_cast<float>(soycons)*soyfact)
            +(static_cast<float>(tat)*tatpois);
  
  cout << "You need to take "<<numpills<<" pills today. Don't choke!\n";
  cout << endl;
  cout << "Bye for now, and enjoy your pills.....\n";
  return 0;
}
