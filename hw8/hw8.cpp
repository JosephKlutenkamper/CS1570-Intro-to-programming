//-----------------------------------------------------------------------------
//Programmer:Joesph Klutenkamper  Instructor: Dileep
//Hw8: TEXT EDITOR
//Date: 4/10/2017
//Class:CS1570                     Section: C
//-----------------------------------------------------------------------------
//Program Derscription: Program will output a file of an edited text file.
//-----------------------------------------------------------------------------
#include "header.h"


int main()
{
//Filestream assignment
  ifstream fin;

//Variables used in main
  int puncts       = 0;
  int letters      = 0;
  int maxPunct     = 0;
  int commaIndex   = 0;
  int count1       = 0;
  int count2       = 0;
  int count3       = 0;
  int count4       = 0;
  int length       = 0;
  int lenBefore    = 0;
  int lenAfter     = 0;
  char wrd[100]    = {'\0'};
  char beforeComma[1000] = {'\0'};
  char afterComma[1000]  = {'\0'};
  bool comma  = false;
  bool used_indices = false;
  bool hasRan       = false;
  bool programRan   = false;
  srand(time(NULL));
//Open file
  fin.open("speech.dat");

//COUNTING LOOP
  while(fin>>wrd)
  {
    length = strlen(wrd);

    if(wrd[length-1] == '.' || wrd[length-1] == '?' || wrd[length-1] == '!')
    {
       puncts++;
       letters++;
    }
    if(wrd[length-1] == ',' && comma == false && puncts >= 2)
    {
        commaIndex = puncts;
        comma      = true;
    }

  }

   fin.close();

   fin.open("speech.dat");

   puncts = 0;
   comma = false;

//Input for arrays to swap
   while(fin >> wrd && puncts < commaIndex+1)
   {

//acquires size of data.
     changeword(wrd);
     very(wrd);
     lyread(wrd);
     lrgwrd(wrd);
     length = strlen(wrd);


     if(wrd[length-1] == '.' || wrd[length-1] == '?' || wrd[length-1] == '!')
     {
       puncts++;
     }

     if(puncts == commaIndex)
     {

       if(wrd[length-1] == '.' || wrd[length-1] == '?'
          || wrd[length-1] == '!')
         fin>>wrd;

//retain info before comma
       if(comma == false && count1 == 0)
       {
         strcat(beforeComma, wrd);
         strcat(beforeComma, " ");
       }
       if(wrd[length-1] == ',')
       count1++;
     }

//retain info after first comma
     if(comma == true && count1 > 0)
     {
       strcat(afterComma, wrd);
       strcat(afterComma, " ");
     }

     if(puncts == commaIndex && wrd[length-1] == ',')
       comma = true;
   }

  fin.close();

  fin.open("speech.dat");

  puncts = 0;

//output of run-on sentence.


  while(fin >> wrd)
  {
//Condition runs once.
    if(hasRan == false)
    {
      ranmean();
      hasRan=true;
    }
//continuation
    changeword(wrd);
    very(wrd);
    lyread(wrd);
    lrgwrd(wrd);

//punct count
    length = strlen(wrd);
    if(wrd[length-1] == '.' || wrd[length-1] == '?' || wrd[length-1] == '!')
    {
      puncts++;

    }


    if(puncts < 1)
    {
      letters += strlen(wrd);
      cout << wrd << " ";
    }

    else if((wrd[length-1] == '.' || wrd[length-1] == '?' || wrd[length-1] == '!')
            && puncts <= 1)
    {
      wrd[length-1] = '\0';
      cout << wrd <<  " ";

    }

    if(puncts >= 1 && puncts < 2)
    {

      letters += strlen(wrd);

       if(puncts == 1 &&count2>0)
       {
         if(count2 == 1)
           wrd[0] += 32;


         cout << wrd << " ";
       }

       count2++;

    }

//Output after run on sentence
    if(puncts >= 2 && puncts < commaIndex+1)
    {
      letters += strlen(wrd);

        cout << wrd << " ";

      count3++;

    }
//output before and after arrays
    if(puncts >= commaIndex && puncts < commaIndex+1)
    {
      if(used_indices == false)
      {
         lenBefore = strlen(beforeComma);
         lenAfter  = strlen(afterComma);

         afterComma[0] -= 32;
         afterComma[lenAfter-2] = ',';

         cout << afterComma;

         beforeComma[0] += 32;
         beforeComma[lenBefore-2] = '.';
         cout << beforeComma;

         used_indices = true;
      }

      if(wrd[length-1] == '.' || wrd[length-1] == '?' || wrd[length-1] == '!')
      {
        puncts++;
      }

   }

//outputs after coma
    if(puncts >= commaIndex+2 && puncts <maxPunct+1)
     {
       if(count4 > 0 && puncts != maxPunct)
         cout << wrd << " ";
       count4++;
     }
     else if(puncts == maxPunct+1)
     {
       length = strlen(wrd);
       programRan = stuff(wrd);
       if(programRan == false)
         cout << wrd;
     }

  }

   cout << endl;
   fin.close();

  return 0;
}//end main
