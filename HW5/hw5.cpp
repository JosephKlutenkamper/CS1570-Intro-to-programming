//-----------------------------------------------------------------------------
//Programmer:Joseph Klutenkamper            Intsructor:Dileep
//HW5:"Everything is coming up Milhouse."   Date:3/2/2017
//Class:CS1570                              Section:C
//-----------------------------------------------------------------------------
#include <iostream>
#include <string.h>
using namespace std;


//Discription :A no-perameter function that greets user and returns their name.
//Pre         :None.
//Post        :A Greeting message is output to the screen and a string is 
//            :returned conatining user's name.
string greeting();


//Discription :A string perameter function that signsoff and says goodbye.
//Pre         :A string must be declared and assigned for perameters.
//Post        :A signoff message is displayed containing user's name. 
void signoff(string name);


//Discription :A no-perameter function that fetches and returns user input for 
//            :waist size.
//Pre         :None.
//Post        :Function returns a positive user input for waist size(integer).
int getwaistsize();


//Description :A no-perameter function that fetches and returns user input for 
//            :leg length.
//Pre         :None.
//Post        :Function returns a positive user input for leg length(integer). 
int getleglength();


//Description :A no-perameter function that fetches and returns user input for  
//            :high-water tolerance.
//Pre         :None.
//Post        :Function returns a positive user input for high-water tolerance
//            :integer. 
int getwatertolerance();


//Description :A function that will be passed an integer value and preform an 
//            :operation that will return an "inseam value."
//Pre         :A value for waist must be declared before implepentation for 
//            :the perameter.
//Post        :Function returns a positive output for the inseam value.
float getinseam(int waist);


//Description :A function that will be passed the integer value for the user's
//            :leg measurement, high-water tolerance calculation and finally
//            :the inseam value to evaluate if the pants are too long or not.
//Pre         :The function must be passed down an inseam value, a leg 
//            :measurement, and a high-water tolerance, in the perameters.
//Post        :Function will evaluate the information in the perameters and 
//            :determine a bool variable true or flase and return said
//            :boolean variable.
bool compare(int leglength, int tolerance, float inseam); 


//Description :A function that will be passed down a bool value and evaluate
//            :it. if true it will output a message notifying the user that 
//            :the pants are okay for water depth. If false it will notify the
//            :user that the pants are too big. 
//Pre         :Function needs a boolean value passed into it.
//Post        :Function will output a message explaining boolean interpretation
//            :.
void print(bool compare);


//Global constant used for calculating inseam value.
const float INSEAM_RATIO = 0.9;

//Global constant used for zero mins.
const int ZEROMIN = 0;
 
int main()
{
  bool comparison;
  string user_name;
  char redo;
  int waist_size;
  int leg_length;
  int tolerance;
  float inseam;
  
  //Grab name and greet.
  user_name = greeting();
  
  do
  {
    //Grab waist size.
    waist_size = getwaistsize();
  
    //Grab leglength,
    leg_length = getleglength();
  
    //Grab tolerance.
    tolerance = getwatertolerance();
  
    //input waist size and return inseam value.
    inseam = getinseam(waist_size);
  
    //input leg length, tolerance, inseam, and return bool
    //that compares values.
    comparison = compare(leg_length, tolerance, inseam); 
  
    //Display of what user action should be
    //determined by bool placed in peramter.
    print(comparison);
    
    cout << "Would you like to try again(for a different pair of pants)?\n";
    cout << "type 'y' for yes and 'n' for no:";
    cin >> redo;
    cout << endl;
    
  }while(redo=='y'||redo=='Y');
     
  //Displays a goodbye message with user
  //name.
  signoff(user_name);
  return 0;
}


//Greeting function that fetches name and returns it.
string greeting()
{
  //Decleratin of string used to return the name of user.
  string name;
  
  cout << "Please enter your name:";
  cin >> name;
  cout << endl;
  cout << "Hello "<<name<<", Welcome to the High Water Pants Calculator.\n";
  cout << endl;
  
  return name;
}

//Function takes name from main and displays user name in signoff message. 
void signoff(string name)
{
  cout << "Goodbye "<<name<<" have a great day!\n";
  cout << endl;      
}

//Function will prompt user to input waist size and return a value equal to 
//waist size. The user cannot enter a negative number for the size.
int getwaistsize()
{
  //Decleration of the variable that's value is assigned by the user
  //then passed to int main.
  int size;
  
  //negative input prevention.
  do
  {
    cout << "Please enter waist size(that is not negative):";
    cin >> size;
  }while (size<ZEROMIN);
  
  cout << endl;
  
  return size;
}

//Function will prompt user to input leg length and return a value equal to 
//leg length. The user, again, cannot enter a negative number.
int getleglength()
{
  //Decleration of the variable that's value is assigned by the user
  //then passed.
  int size;
  
  //Negative input prevetion.
  do
  {
    cout << "Please enter leg length(that is not negative):";
    cin >> size;
  }while (size<ZEROMIN);
  
  cout << endl;
  
  return size;
}

//Function will prompt user to input high-water tolerance and return a value
//equal to the input. The user, again, cannot enter a negative number.
int getwatertolerance()
{
  //Decleration of the variable that's value is assigned by the user
  //then passed.
  int tolerance;
  
  //Negative input prevetion.
  do
  {
    cout << "Please enter high-water tolerance(floor to bottom of pant's cuff"
         << "):";
    cin >> tolerance;     
  }while(tolerance<ZEROMIN);
  
  cout << endl;
  
  return tolerance;
}

//Function will use the user input for waist measurement to find the inseam 
//measurement by multiplying it by the inseam ratio constant.
float getinseam(int waist)
{
  float inseam;
  
  inseam=static_cast<float>(waist)*INSEAM_RATIO;
  
  return inseam;    
} 

//Function will evaluate high water value by subtracting inseam from the leg
//length to find the high-water value. It will then compare this value to the
//high-water tolerance; if greater or equal to, it will return true if not
//then it will return flase.
bool compare(int leglength, int tolerance, float inseam)
{
  float high_water_val;
  
  high_water_val=static_cast<float>(leglength)-inseam;
  
  if(high_water_val>=tolerance)
  {
    return true;
  }
  else
  {
    return false;
  }
}   

//Function will display outcome depending on the variables passed down
//relating to if the pants are too long or just right.
void print(bool compare)
{
  if (compare)
  {
    cout << "Great pair of high-waters!\n";
  }
  
  else
  {
    cout << "These pants are NOT high-water enough for you.\n";
  }
  
  cout << endl;
}
