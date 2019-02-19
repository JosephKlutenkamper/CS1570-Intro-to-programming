//-----------------------------------------------------------------------------
//Programmer: Joseph Klutekamper   Instructor: Dileep
//Homework 3: Photo-Honest Optic-Neuron Yadi Yadi Yadi (PHONEY)
//Date: 2/10/2017
//Class: cs1570                    Section: C
//-----------------------------------------------------------------------------
#include <iostream>
using namespace std;


int main()
{
//The following is a list of everything that can be held as a constant, held 
//as a constant, as stated in the homework. I personally feel this to be
//completely usesless as there as no classes or functions nor is this
//a large enough algorythm for such direction, but please do not mark off 
//for using too many constants it is what I askes and told to do.
  const int X_CONST_ONE=7919;
  const int X_CONST_TWO=104729;
  const int X_CONST_THREE=101;
  const int X_CONST_FOUR=150;
  const int CORNEA_MAX=20;
  const int CORNEA_MIN=1;
  const int PMAX=5;
  const int BMAX=10;
  const int BMIN=6;
  const int CMIN=12;
  const int START1=1;
  const int START2=2;
  const int START3=3;
  const int AVRGDIV=2;
  const int INMIN=150;
  const int INMAX=200;
  const int SNELLMIN=1;
  const int SNELLMAX=9;
  const int KEVAL=2;
  const int PVAL=3;
  const string PCHAR="P";
  const string BCHAR="B";
  const string CCHAR="C";
  const string NCHAR="N";
  const string DCHAR="d";
  const string HCHAR="h";
  const string INSTRING="iN";
  const string LISTRING="Li";
  const string KESTRING="Ke";
  const string KYSTRING="ky";
  const string YESTRING="ye";
  int cornea;
  int start;
  int snellen;
  int xsubone;
  int xsubtwo;
  float xaverage;
  string first_let;
  char redo;
  string secstring;
  string thirdstring;
  string fourthstring; 
  
//Start of process prompts user to input the first part of the cornea.
  do
  {
    cout << "Hello Welcome to the Photo-Honest Optic-Neuron Yadi Yadi Yadi"
         << "Phoney.\n";
    cout << endl;
    cout << "Please enter the measurement of your right cornea in millimeters"
         << "(mm):";
         
//Loop below catches errors in input processs.
    do
    {     
      cin >> cornea;
      cout << endl;
    }while (cornea<=CORNEA_MIN||cornea>=CORNEA_MAX);
    
//First process determines where the value given for cornea falls in terms
//of the first string value "P,B,or C. 
    if (cornea>=CORNEA_MIN&&cornea<=PMAX)
    { 
      first_let=PCHAR;
      start=START1; 
    }
    else if (cornea>=BMIN&&cornea<=BMAX)
    {
      first_let=BCHAR;
      start=START2;
    }
    else if (cornea>=CMIN&&cornea<=CORNEA_MAX)
    {
      first_let=CCHAR;
      start=START3;
    }
    
//The following is an logic step to finding out the second string value
//using the start value assigned by the previous loop.
    xsubone=((start*X_CONST_ONE+X_CONST_TWO) % X_CONST_THREE) + X_CONST_FOUR;
    
    xsubtwo=((xsubone*X_CONST_ONE+X_CONST_TWO) % X_CONST_THREE) + X_CONST_FOUR;
    
    xaverage=static_cast<float>(xsubone+xsubtwo)/AVRGDIV;
    
//Filter for the number retreived by the previous allgorythim. It is 
//then placed in this to determine the values corresponding string 
//value. The else could have anther loop making sure a value falls
//within the prompted perameters but I find this redundant as the 
//previous filter for corenea would rule that out.
    if (xaverage>=INMIN&&xaverage<=INMAX)
    {
      secstring = INSTRING;
    }
    else
    {
      secstring = LISTRING;
    }
    
//The second user input used to determine the rest of the string values.
    cout << "Please enter the first line on the 9-line Snellen chart the user "
         << "has answered incorrectly:";
         
//Anther loop used to catch any flase user input value.
    do
    {     
      cin >> snellen;
      cout << endl;
    }while(snellen<SNELLMIN||snellen>SNELLMAX);
    
//Start of the third part to deterime the string value of the third string.
    if (snellen == SNELLMIN)
    {
      thirdstring = NCHAR;
    }
    else if (snellen == KEVAL)
    {
      thirdstring = KESTRING;
    }
    else if (snellen >= PVAL && snellen <= SNELLMAX)
    {
       thirdstring = PCHAR;
    }
    
//Final algorythim used to determine the full end string which is many 
//of the string values put together.
    if (first_let == PCHAR ||(first_let == BCHAR && snellen == SNELLMIN))
    {
      fourthstring = DCHAR; 
    }
    else if (first_let == CCHAR && snellen == SNELLMIN)
    {
      fourthstring = KYSTRING;
    }
    else if (secstring == INSTRING && thirdstring == PCHAR)
    {
      fourthstring = HCHAR;
    }
    else
    {
      fourthstring = YESTRING;
    }
    
//Output of stirng in the exact template used on the homework.
    cout <<"If the first input is " << cornea <<", the first substring "
         <<"is '"<< first_let <<"'; this results in the second part being \n'"
         <<secstring<<"'; if the input for part 3 is "<<snellen<<", the "
         <<"third substring is '"<<thirdstring<<"'; and thus the fourth \n"
         <<"subsring is '"<<fourthstring<<"'. So the final code is "
         <<"'"<<first_let<<secstring<<thirdstring<<fourthstring<<"'\n"
         <<endl;
         
//Redo loop input
    cout <<"Would you like to try again? Press 'y' for yes and 'n' for no.\n";     
    cin >> redo;
  }while (redo == 'y');
  return 0;
}
