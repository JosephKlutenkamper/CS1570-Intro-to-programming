//-----------------------------------------------------------------------------
//Programmer:Joesph Klutenkamper  Instructor: Dileep
//Hw8: TEXT EDITOR
//Date: 4/10/2017
//Class:CS1570                     Section: C
//-----------------------------------------------------------------------------
//Program Derscription: Program will output a file of an edited text file.
//-----------------------------------------------------------------------------
#include "header.h"



//Function changes words at random
void changeword(char word[])
{
  int chance;

  chance = rand() % MAX_CHANCE;

  if(chance <= RANDCHANCE)
  {
    if(!strcmp(word,"is"))
      strcpy(word,"are");
    else if(!strcmp(word,"isn't"))
      strcpy(word,"ain't");
    else if(!strcmp(word,"has"))
      strcpy(word,"have");
    else if(!strcmp(word,"she"))
      strcpy(word,"her");
    else if(!strcmp(word,"he"))
      strcpy(word,"him");
  }

  return;
}


//Function that adds very onto any word that has very in it.
void very(char word[])
{
  if(!strcmp(word,"very"))
    strcat(word," very");

  return;
}

//Function deletes 'ly' from word
void lyread(char word[])

{
  int leng = strlen(word);
  if(word[leng-2] == 'l' && word[leng-1] == 'y')
  {
    word[leng-2] = '\0';
  }
  return;
}


//Function that finds large words and randomly placers stutter.
void lrgwrd(char word[])
{
  int j = 0;
  int leng = strlen(word);
  char index[40] = {'\0'};
  int num = rand() % RAN_LETTER1 + RAN_LETTER2;

  if(leng > WRDLRG)
  {

    for(int i = num+1; i < leng; i++)
    {
      index[j] = word[i];
      j++;
    }


    word[num+1] = '\0';

    sayrand(word);

    strcat(word, index);

  }

  return;
}

//Function that places stutter in large words
void sayrand(char word[])
{
  int random = rand()% MAX_CHANCE;
  if(random <= POS1)
   strcat(word, RANSAY1);
  else if(random <= POS2)
   strcat(word, RANSAY2);
  else
   strcat(word,RANSAY3);

  return;
}

//Ranmean produces a random chance message to user
void ranmean()
{

  int random = rand() % MAX_CHANCE;

  if(random <= IMRAND)
  {
    cout << "I mean.. ";
  }

  return;

}

//Function has a chance of outputting a message on the screen
bool stuff(char word[])
{
  int random = rand() % MAX_CHANCE;
  int leng = 0;
  bool chance = false;
  leng = strlen(word);

  if(random <= RANDNSTUFF)
  {
    if(word[leng-1] == '.' || word[leng-1] == '?' ||
       word[leng-1] == '!' )
      word[leng-1] = '\0';
     chance = true;
     cout << word <<"n'stuff." << endl;
  }
  return chance;
}
