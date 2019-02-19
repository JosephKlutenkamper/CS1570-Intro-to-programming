//-----------------------------------------------------------------------------
//Description: The following are the function definitions for the file hw6 and
//           : used in int main. for full program discriptions refer to 
//           : "functions.h"
//-----------------------------------------------------------------------------
#include "functions.h"

//Menu function that returns a choice integer value.
int menu()
{
  const int CHMAX=6;
  const int CHMIN=1;
  int choice;
  
  cout << "    OPTIONS    \n";
  cout << "    -------    \n";
  cout << "1. Factorial of X.\n";
  cout << "2. Exponentiation of X.\n";
  cout << "3. Sine of X.\n";
  cout << "4. Roots of X.\n";
  cout << "5. Hyberbolic Cosine of X.\n";
  cout << "6. Exit.\n";
  cout << endl;
  do
  {
    cout << "Choose a menu option:";
    cin >> choice;
    cout << endl;
  }while (choice<CHMIN||choice>CHMAX);
  
  return choice; 
}

//Function that finds the factorial of a given input.
double fact(int num)
{
  const int INITIALIZER=1;
  double factorial=INITIALIZER;
  
  for (int i=INITIALIZER;i<=num;i++)
  {
    factorial*=i; 
  }
  
  return factorial;
}

//Fucntion that finds exponential value of an x value and its exponent.
double expo(int xval, int ex)
{
  const int INITIALIZER=1;
  double exponent=INITIALIZER;
  
  for (int i=INITIALIZER;i<=ex;i++)
  {
    exponent*=xval;
  } 
  
  return exponent;
}

//Function that prompts user for a xvalue to factorialize then displays it.
void showfact()
{
  int xval;
  double factorial;
  
  cout << "Welcome to the Factorial Calculator.\n";
  cout << endl;
  cout << "Enter an X value:";
  cin >> xval;
  
  factorial=fact(xval);
  
  cout << "The factorial of "<<xval<<" is "<<factorial<<".\n";
  cout << endl;
  
  return;
} 

//Fucntion that prompts the user for X value input and then exponentiates the
//input.
void exponentiate()  
{
  const int INITIALIZER=0;
  const int COUNT=8;
  double expon=INITIALIZER;
  int xval;
  
  cout << "Welcome to the Exponentiation Calculator.\n";
  cout << endl;
  cout << "Enter an X value:";
  cin >> xval;
  cout << endl;
  
  for (int i=INITIALIZER;i<COUNT;i++)
  { 
    //This calls the two functions that are needed to complete this operation.
    //The exponent funtion finds what x is when its to the power of i.
    //It is then divivded by the factorial of i.
    expon+=(expo(xval,i)/fact(i));
  }
  
  cout << "The Exponentiated Value of "<<xval<<" is "<<expon<<endl;
  cout << endl;
  
  return; 
   
}

//Function finds the sin value of x.
void sinx()
{
  const int K_CON=1;
  const int K_COEF=2;
  const int ZERO_INITIALIZER=0;
  const int INITIALIZER=1;
  const int EVEN=2;
  const int NEG=-1;
  double sin=ZERO_INITIALIZER;
  int xval;
  int kval;
  int posneg=INITIALIZER;
  int ktot;
  
  
  cout << "Welcome to the Sine Calculator.\n";
  cout << endl;
  cout << "Enter an X value:";
  cin >> xval;
  cout << endl;
  cout << endl;
  cout << "Please enter a k value(to determine accuracy):";
  cin >> kval;
  cout << endl; 
  
  ktot=K_COEF*kval-K_CON;
  
  for (int i=INITIALIZER;i<=ktot;i++)
  {
    if (i%EVEN==0)
    {
      posneg*=NEG;
    }
    sin+=(expo(xval,i)/fact(i))*posneg;
  }  
  cout << "If X is "<<xval<<" and K is "<<kval<<" then sine of "<<xval
         << " is "<<sin<<endl;
  cout <<endl;
    
  return; 
     
}

//This function will find the roots of a given x value and root value.
void findroot()
{
  const int K_CON=1;
  const int LOOPMAX=10;
  int xval;
  int ktot;
  double nroot;
  double kval;
  
  cout << "Welcome to the Root Calculator.\n";
  cout << endl;
  cout << "Please enter an X value:";
  cin >> xval;
  cout <<endl<<endl;
  cout << "Please enter the nth root:";
  cin >> kval;
  cout <<endl;
  
  nroot=xval;
  
  ktot=kval-K_CON;
  
  for (int i=K_CON;i<=LOOPMAX;i++)
  {
    nroot=((ktot*nroot)+(static_cast<double>(xval)/expo(nroot,ktot)))/kval;
  } 
  
  cout << "The "<<kval<<" root of "<<xval<<" is "<<nroot<<endl;
  return;
}

//This function will output the hyberbolic cosine of X.
void findcos()
{
  const int ZEROID=0;
  const int INITIALIZER=1;
  const int SER_LIM=12;
  const int EVEN=2;
  double cosh=INITIALIZER;
  int xval;
  cout << "Welcome to the Hyperbolic Cosine Calculator.\n";
  cout << endl;
  cout << "Please enter an X value:";
  cin >> xval;
  cout << endl;
  cout << endl;
  
  for (int i=INITIALIZER;i<=SER_LIM;i++)
  {
    if (i%EVEN==ZEROID)
    {
      cosh+=(expo(xval,i)/fact(i));
    }
  }
  
  cout << "Hyperbolic Cosine of "<<xval<<" is "<<cosh<<endl;
  
  return;
   
  
} 

//Signoff function will display a signoff message for user.
void signoff()
{
  cout << "Bye have a great day!\n";
  cout << endl;
  return;
}
