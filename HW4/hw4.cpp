//-----------------------------------------------------------------------------
//Programmer: Joseph Klutenkamper    Instructor: Dileep
//Homework4: Millhouse Calculator 
//Date: 2/20/2017
//Class: cs1570                      Section: C
//-----------------------------------------------------------------------------
#include <iostream>
using namespace std;

//Start of program
int main()
{
//variable decleration with all numbers in program declared as constants
//as instructed in homework.
  bool redo = true;
  bool redo2 = true;
  const int EXPMIN=0;
  const int EXPMAX=7;
  const int CHOICEONE = 1;
  const int CHOICETWO =2;
  const int CHOICETHREE =3;
  const int CHOICEFOUR =4;
  const int INITIALIZER = 1;
  const int ZEROMIN = 0;
  const int EXPFORMAX = 6;
  const int KCOEF = 2;
  const int KCONST = 1;
  const int KMIN = 1;
  const int KMAX = 5;
  const int DIV2 = 2;
  const int CBRTCOEF = 2;
  const int CBRTDIV = 3;
  const int POSNEGONE = -1;
  const int SQRTDIV = 2; 
  int choice;
  int choice2;
  int expval;
  int kval;
  int ktot;
  int icopy;
  int xval2 = ZEROMIN;
  int expforval = INITIALIZER;
  int expfordiv = INITIALIZER;
  int divval = INITIALIZER;
  int posneg = INITIALIZER;
  int divtot = INITIALIZER;
  float xtot = INITIALIZER;
  float eval = ZEROMIN;
  float sinx = ZEROMIN;
  float xval;
  float aval;
  float bval;
  float bvalsq;
  //start of first menu loop.
  do
  {
    cout << endl;
    cout << "        OPTIONS        \n";
    cout << endl;
    cout << "       ---------       \n";
    cout << endl;
    cout << "1. Exponential of x(i.e. e^x)\n";
    cout << "2. Sine of x\n";
    cout << "3. Roots of x\n";
    cout << "4. Quit (and run away)\n";
    cout << endl;
    cout << "Please choose from the list:";
    cin >> choice;
    cout << endl;
    
//Begining of the switch for the first menu  
    switch (choice)
    {
    
//CASE ONE    
      case CHOICEONE:
      
//start of the exponetiation function which takes user input and outputs the 
//exponetiated form.
    
        do
        {
          cout << "Please input a real number to Exponentiate between 0 and 7:";
          cin >>expval;
          cout << endl;
       
        }while (expval<=EXPMIN||expval>=EXPMAX);
        
        cout <<endl;
           
        for (int i=ZEROMIN;i<=EXPFORMAX;i++)
        { 
          icopy=i;
          if(i>ZEROMIN) 
          {  
            expforval *= expval;
            expfordiv *=icopy;
          }
          eval+=static_cast<float>(expforval)/expfordiv;
          
        }
        cout << "The exponentiated value of "<<expval<<" is "<<eval<<endl; 
        eval = ZEROMIN;
        
//Reinitializing the variables so if you were to choose this option again
//the variables would refresh making the calculation possible.
        expforval = INITIALIZER;
        expfordiv = INITIALIZER;
          
        break;
        
//CASE TWO        
      case CHOICETWO:
      
//Start of sine function this time reinitializatiion starts at the begining.         
        sinx=ZEROMIN;
        posneg=INITIALIZER;
//This taks the user input for x and k value for accuracy.
     
        cout << "Please enter the x value:";
        cin >> xval;
        cout << endl;
        do
        {
          cout <<"Please enter the k value for accuracy of sine it must be \n"
               <<"between 1 and 5: ";
          cin >>kval;
        }while (kval<KMIN||kval>KMAX);
     
        cout << endl;
     
        ktot=(KCOEF*kval)-KCONST;
     
        for (int h=INITIALIZER;h<=ktot;h++)
        {
          if (h%DIV2==ZEROMIN)
          {
            posneg*=POSNEGONE;
          }
          else
          {
            for (int j=INITIALIZER;j<=h;j++)
            {
              xtot*=xval;
              divval=j;
            }
        
            do
            {
              divtot*=divval;
              divval--;
            }while (divval > ZEROMIN);
            sinx+=xtot/divtot*posneg;
            xtot=INITIALIZER;
            divtot=INITIALIZER; 
          }
        }    
        cout << "sin("<<xval<<") with K being "<<kval<<" is "<<sinx<<endl;
        cout << endl;
        break;

//CASE THREE
      case CHOICETHREE:
        redo2=true;   
        xval2=ZEROMIN;
//Start of the second menu
        
        do
        {
          cout << endl;
          cout <<"       ROOTS         "<<endl;
          cout <<endl;
          cout <<"      -------        "<<endl;
          cout <<endl;
          cout <<"1. Enter x\n";
          cout <<"2. Sqaure root\n";
          cout <<"3. Cube root\n";
          cout <<endl;
          if (xval2==ZEROMIN)
          { 
            do 
            {
              cout << "Please choose from the list you must enter x first:";
              cin >> choice2;
            }while (choice2 != CHOICEONE);
          }
          else
          {
            cout << "Please choose from the list:";
            cin >> choice2;
          }
          
          cout << endl;
//The first sub-case one in which the user must input the x value or it wont
//continue.    
        
          switch (choice2)
          {
            case CHOICEONE:
              cout << "Please input a positive value for x:";
              do
              {
                cin >> xval2;
             
              }while (xval2<=ZEROMIN);
          
              cout << endl;
        
              break;
//Sub-case two where the sqrt of x is found, this option is only avalible when
//the first option is chosen              
              
            case CHOICETWO:
         
              aval=xval2;
           
              for( int y=INITIALIZER;y<=EXPFORMAX;y++)
              {
             
                aval=((aval)+(static_cast<float>(xval2)/aval));
                aval/=SQRTDIV;
            
              }
              cout << endl;
              cout << "The Square root is " << aval <<endl;
              cout << endl;
             
              redo2=false;
            
              break;
//Third sub-case where the x value is cube rooted again this option is only
//avalible when the first option is chosen.
           
            case CHOICETHREE:
              bval=xval2;
              bval/=EXPFORMAX;
         
              for(int g=INITIALIZER;g<=EXPFORMAX;g++)
              { 
                bvalsq=bval;
                bvalsq*=bval;
                bval=((CBRTCOEF*bval)+(static_cast<float>(xval2)/bvalsq));
                bval/=CBRTDIV;
              }
           
              cout << "The cube root is " << bval <<endl;
              cout << endl;
            
              redo2=false;
           
              break;
//default statement that repeats if the user does not input a valid input. 
           
            default:
         
              cout << "Sorry the number you entered is not a valid option.\n";
              cout << endl;
          }     
        }while(redo2);
//end of 3rd case
     
        break;
//start of fouth case whiich ends the program.
        
      case CHOICEFOUR:
        redo=false;
        break;
//default case that repeats if user does not input a valid input.        
         
      default:
        cout << "The number you have chosen is not an option please enter \n"
             << "a valid option.\n"
             << endl;
    }
//end of original case.
           
  }while (redo);
//end of original do while loop

  return 0;  
}
//end of program
