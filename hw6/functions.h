//-----------------------------------------------------------------------------
//Description: This is the function header file for the function used in 
//           : hw6.cpp
//-----------------------------------------------------------------------------
#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
using namespace std;

//Description: This function is the main mene function and will prompt user to
//           : input a number that is in the list of numbers provided for a 
//           : function selection.
//Pre        : None.
//Post       : The function will return a value that will serve as the option 
//           : given by the user.
int menu();

//Description: This function will prompt the user for an input to have factored
//Pre        : None.
//Post       : User will be displayed his or her factorial unlesss it is 
//           : Negative or above 10.
void showfact();

//Description: This function will take in an integer value and retrun a double
//           : value after finding the factorial.
//Pre        : Function needs a integer value.
//Post       : Function will return a factorialized number based on input.
double fact(int num);

//Description: This function will take in 2 integer values and return a double
//           : value after finding the exponential form of the input.
//Pre        : Function needs an integer for xvalue and an integer for exponent
//Post       : Function will return a double for the exponential form.
double expo(int xval, int ex);

//Description: This function will exponentiate a given x value.
//Pre        : None. 
//Post       : X value that was exponentiated will be displayed.
void exponentiate();

//Description: This function will find the value of sin x. 
//Pre        : none.
//Post       : Sine of input X will be displayed for user.
void sinx();

//Description: This funciton will find the desired root of a given value for x.
//Pre        : None.
//Post       : Display the value of the rooted x desired.
void findroot();

//Description: This function will find the hyberbolic cosine of a value.
//Pre        : None.
//Post       : Cosine of X will be displayed for user.
void findcos();

//Description: This function displays a signoff message for user to see.
//Pre        : None.
//Post       : Signoff message is displayed.
void signoff(); 

#endif
