//---------------------------------------------------------------------------
//Programmer: Joseph Klutenkamper   Instructor: Dileep
//HW7: Stock database
//Date: 3/22/2017
//Class: CS1570                     Section: C
//---------------------------------------------------------------------------
//Description: Program will use random numbers to generate a theoretical
//           : database of pants. The program will then have the user choose
//           : a pair and then calculate how much the user will owe.
//---------------------------------------------------------------------------

#include "functions.h"


//Greeting function that displays a greeting to user.
void greet()
{
  cout << endl;
  cout << "     ------------------------------     \n";
  cout << "     Welcome To The Pants Database\n";
  cout << "     ------------------------------     \n";
  cout << endl;
  
  return; 
}

//The fill array function wills the array of type inventory with each element
//containing all the member of the structure. 
void fill_array(inventory array[], int max)
{
  srand(time(NULL));  
  for (int i = 0; i < max; i++)
  {
    array[i].waist  = WAISTMIN + rand()%(WAISTMAX-WAISTMIN+1);
    array[i].inseam = INSEAMMIN + rand()%(INSEAMMAX-INSEAMMIN+1);
    array[i].color  = COLORMIN + rand()%(COLORMAX-COLORMIN+1);
    array[i].availibility = true;      
  }
  
  return;
}



//This function generates the waist values for the pants_of_size array.
void ex_array(inventory arraya[], pants_of_size arrayb[], int maxa, int maxb)
{
  for (int u = 0; u < maxb; u++)
  {
    for (int b = 0; b < COLORMAX2; b++)
    {
      arrayb[u].color[b]=0;
    }
  }  
  for (int j=0; j < maxb; j++)
  {
    for (int i = 0; i < maxa; i++)
    {
      if (arraya[i].waist == j + maxb - 1 && arraya[i].availibility == true)
      {
        arrayb[j].waist = arraya[i].waist;
        arrayb[j].color[arraya[i].color] += 1;
      }
    } 
  } 
  return;
} 

//Function that sorts the inventory array in acsending waist size. 
void sort(inventory array[], int max)
{
  for (int i = 1; i < max; i++)
  {
    for(int j = 0; j < max-i; j++)
    {
      if(array[j].waist > array[j+1].waist)
      {
        inventory swap = array[j];
        array[j]       = array[j+1];
        array[j+1]     = swap;
      }   
    }
  }
  return; 
}     

//Function will display the newly sorted inventory array.
void display(inventory array[], int max)
{
    
  for(int i = 0; i < max; i++)
  {
    if (array[i].availibility == true)
    {
      cout << "Waist:" << array[i].waist << "    inseam:" << array[i].inseam 
           << "    " << COLOR[array[i].color] << endl;
    } 
  }
  cout << endl; 
  return;  
}

//Function will display what is in stock for users. 
void read_input(inventory arraya[], int maxa, pants_of_size arrayb[])
{

  int waist;
  int ogwaist;
  int color_choice;
  int innie;
  int ind;
  bool redo = false;
  bool refer;
  char yn; 
  do
  {
    //Displays the instock items.
    display(arraya,maxa);
    
    //Grabs user input for waist measurement and validates it.
    cout << "Please enter the waist measurement you'd like (must be 20-40):";
    cin >> waist;
    cout << endl; 
    cout << endl;
    
    //Validation catch.
    if (waist < WAISTMIN || waist > WAISTMAX)
    {
      cout << "Go somewhere else to shop.\n";
      cout << endl;
    }
    
    //If valid input: Output the colors availible.
    else
    {
      cout << "For size " << waist << " we have:\n";
         
      ogwaist = waist;
      waist   = waist - LEVELER;
    
      for (int i = 0; i < COLORMAX2; i++)
      {
        if (arrayb[waist].color[i] > 0)
        {
          if(i==0)
          {
           cout <<"(Option 0)Black:"<< arrayb[waist].color[i]<<endl;
          }
          else if(i==1)
          {
            cout <<"(Option 1)Blue:"<< arrayb[waist].color[i]<<endl;
          }
          else if(i==2)
          {
            cout <<"(Option 2)Red:"<< arrayb[waist].color[i]<<endl;;
          }
          else if(i==3)
          { 
            cout <<"(Option 3)Rainbow:"<<arrayb[waist].color[i]<<endl;
          }
          else if(i==4)
          {
            cout <<"(Option 4)Checkered:"<<arrayb[waist].color[i]<<endl;
          }
          else if(i==5)
          {
            cout <<"(Option 5)Electric Green:"<< arrayb[waist].color[i]<<endl;
          }
          else if(i==6)
          {  
            cout <<"(Option 6)Polka Dot:"<<arrayb[waist].color[i]<<endl;
          } 
        }
      }   
  
      cout << endl;
      cout << endl;
      
      //Takes user input for color and validates it.
      cout << "Please enter a color you'd like by number(black = 0 ect..)\n";
      cout << "or type in a negative number to quit:";
      cin  >> color_choice;
      cout << endl;
      cout << endl;
      
      //If negative the user is not interested in the product and therefore
      //restarts the program.  
      if (color_choice < 0)
      { 
        cout << "Would you like another customer?(y/n):";
        cin  >> yn;
        cout << endl;
        if (yn=='y'||yn=='Y')
        {
          redo=true;
        }
        else 
        {
          break;
        }
        
      }
      
      //Catches invalid input and has the user input a valid number. 
      while(arrayb[waist].color[color_choice] <= 0 || color_choice 
            >  COLORMAX)
      {
        cout << "Please enter a color you'd like by number(black = 0 ect";
        cout << "):";
        cin >> color_choice;
        cout << endl;
        cout << endl;
      }  
      
      //Subrtacting the selected item from inventory.
      arrayb[waist].color[color_choice]-=1; 
      
      
      //Displays the instock inseam values of the selected waist size
      //and color.
      cout << "The following are all of the inseam values for waist size:"
           << ogwaist << " and color:" << COLOR[color_choice] <<endl<<endl;
      
      for (int p = 0; p < maxa; p++)
      {
        if(arraya[p].waist == ogwaist && arraya[p].color == color_choice && 
           arraya[p].availibility == true)
        {
          cout << "Inseam value:" << arraya[p].inseam << endl;
        } 
      }
    
      cout << endl;
      cout << endl;
      
      //Grabs the value the user wishes for inseam value of selected color 
      //and waist size.
      do
      { 
        cout << "Please enter an inseam value you wish to have from the list:";
        cin >> innie;
        for (int h = 0; h < maxa; h++)
        {
          if((arraya[h].waist == ogwaist) && (arraya[h].color == color_choice))
          {
            if(innie == arraya[h].inseam)
            {
              ind= h;
              refer = false;
            } 
          } 
        } 
      }while (refer);   
    
         
      cost(arraya, ind);
      
      cout << "Would you like to buy another?(y/n):"; 
      cin >> yn;
      cout << endl;
      cout << endl;
      if (yn=='y'||yn=='Y')
      {
        redo=true;
      }
      else
      {
        break;
      } 
      
    }        
  }while (redo);  
  return;
}

//Function will find the cost of the pants.
void cost (inventory array[], int index)
{ 
  
  const int compare           =  2;
  const int high_water_charge = 40;
  const float charge          = .9; 
  float price;
   
  cout << "The cost of the pants is $";
  
  price=array[index].waist+array[index].inseam;
  
  if (static_cast<float>(array[index].waist)*charge 
      >= array[index].inseam+compare)
  {
    price+=high_water_charge;
  }
  
  cout << price;
  cout << endl;
  cout << endl;
   
  array[index].availibility=false;
  
  return;  
}

//Signoff message to user.
void signoff()
{
  cout << "     -------------------------     \n";
  cout << "     GOOD BYE HAVE A GOOD DAY!     \n";
  cout << "     -------------------------     \n";
  cout << endl;
  return;
} 
