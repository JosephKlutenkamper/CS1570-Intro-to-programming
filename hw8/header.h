//-----------------------------------------------------------------------------
//Programmer:Joesph Klutenkamper  Instructor: Dileep
//Hw8: TEXT EDITOR
//Date: 4/10/2017
//Class:CS1570                     Section: C
//-----------------------------------------------------------------------------
//Program Derscription: Program will output a file of an edited text file.
//-----------------------------------------------------------------------------
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

//Constants used throughout main and functions.
const int WRDLRG       = 10;
const int RANSAYMAX    = 10;
const int MAX_CHANCE   = 100;
const int RAN_LETTER1  = 4;
const int RAN_LETTER2  = 3;
const int POS1         = 33;
const int POS2         = 66;
const int RANDNSTUFF   = 70;
const int RANDCHANCE   = 80;
const int IMRAND       = 50;
const char RANSAY1[RANSAYMAX] = {"-uhh-"};
const char RANSAY2[RANSAYMAX] = {"-err-"};
const char RANSAY3[RANSAYMAX] = {"-umm-"};

//Description:Function outputs to the screen based on random chance
//Pre: none
//Post: message is output to the screen if chance is met.
void ranmean();

//Description:Function checks for words and if the
//             criteria is met, the word is replaced
//Pre: word[] must contain a null terminated character
//Post: word is replaced if criteria is met
void changeword(char word[]);

//Description:Function searches for the word "very"
//             and concatinates very onto very
//Pre: word[] must contain a null terminated character
//Post: very is concatinated
void very(char word[]);

//Description:Function searches for words containing "ly"
//             and removes the "ly" from that word.
//Pre: word[] must contain a null terminated character.
//Post: ly is removed from word.
void lyread(char word[]);

//Description:Function searches for words longer than 10
//             and concatinates a random filler into the middle of it.
//Pre: word[] must contain a null terminated character.
//Post: A filler is contatinated into the middle of the word.
void lrgwrd(char word[]);

//Description: Function randomly determines which filler to
//             concatinate into the word.
//Pre: word[] must contain a null terminated character.
//Post: random filler is determined.
void sayrand(char word[]);

//Description:Function outputs to the screen based on random chance
//Pre: word[] must contain a null terminated character
//Post: message is output to the screen if chance is met.
bool stuff(char word[]);

#endif
