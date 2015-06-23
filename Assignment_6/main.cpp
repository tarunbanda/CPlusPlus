#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

// method prototypes
int getBet();
string pullOne();
int getPayMultiplier(string s1, string s2, string s3);
void displayWin(string s1, string s2, string s3, int winnings);
int validInput();

//client that calls all methods
int main()
{
   int bet, payMultiplier, winnings;
   string slot1, slot2, slot3;

   do {
      bet = getBet();
      if (bet == 0)
      {
         cout << "\nGoodbye..." << endl;
         break;
      }
      cout << "\nuserBet is: " << bet << endl;
      slot1 = pullOne();
      slot2 = pullOne();
      slot3 = pullOne();
      payMultiplier = getPayMultiplier(slot1, slot2, slot3);
      winnings = payMultiplier * bet;
      displayWin(slot1, slot2, slot3, winnings);
   } while (bet != 0);


   return (0);
}

// returns the user input integer ranging from 0 to 100
int getBet()
{
   int userInput;
   cout << "\nHow much would you like to bet (1-100) or 0 to quit? ";
   userInput = validInput();

   return userInput;
}

// returns one of four slot options as a string
string pullOne()
{

   string slotResult[4] = {"BAR", "7", "cherries", "space" };
   return slotResult[rand() % 4];
}

// returns the payMultiplier for the slot results
int getPayMultiplier(string s1, string s2, string s3)
{
   if (s1.compare("cherries") == 0)
   {
      if (s2.compare("cherries") == 0)
      {
         if (s3.compare("cherries") == 0)
            return 20;
         else
            return 10;
      }
      else
         return 3;
   }
   else if ((s1.compare("BAR") == 0) && (s2.compare("BAR") == 0) &&
            s3.compare("BAR") == 0)
   {
      return 35;
   }
   else if ((s1.compare("7") == 0) && (s2.compare("7") == 0) &&
            s3.compare("7") == 0)
      return 50;
   else
      return 0;
}

//displays pull results and winnings
void displayWin(string s1, string s2, string s3, int winnings)
{
   cout << "\nwhirrrrrr .... and your pull is ...\n" << endl;
   cout << s1 + " "<< s2 + " " << s3 + " "<< endl;

   if (winnings > 0)
      cout << "\nCongratulations, you win: " << winnings << endl;
   else
      cout << "\nSorry, you lose." << endl;
}

// checks for validity of user inputs
int validInput()
{

   int input;
   string inputString;
   bool isValid = false;

   do{
      getline(cin, inputString);

      for (int i = 0; i < inputString.length(); i++)
      {
         if (inputString[i] >= '0' && inputString[i] <= '9')
            isValid = true;
         else
         {
            isValid = false;
            cin.clear();
            cout << "\nBad entry.  Enter a valid bet (1-100) or 0 to quit? ";
            break;
         }
      }
      if (isValid)
      {
         input = stoi(inputString);
         if (input >= 0 && input <= 100)
         {
            return input;
         }
         else
         {
            isValid = false;
            cout << "\nBad entry.  Enter a valid bet (1-100) or 0 to quit? ";
         }
      }
   } while (!isValid);

   return 0;
}


/*----------------------------Start Run------------------------------


 How much would you like to bet (1-100) or 0 to quit? -0

 Bad entry.  Enter a valid bet (1-100) or 0 to quit? -100

 Bad entry.  Enter a valid bet (1-100) or 0 to quit? 101

 Bad entry.  Enter a valid bet (1-100) or 0 to quit? 12adf

 Bad entry.  Enter a valid bet (1-100) or 0 to quit? aaaf

 Bad entry.  Enter a valid bet (1-100) or 0 to quit? a

 Bad entry.  Enter a valid bet (1-100) or 0 to quit? 1

 userBet is: 1

 whirrrrrr .... and your pull is ...

 space 7 7

 Sorry, you lose.

 How much would you like to bet (1-100) or 0 to quit? 2

 userBet is: 2

 whirrrrrr .... and your pull is ...

 cherries cherries BAR

 Congratulations, you win: 20

 How much would you like to bet (1-100) or 0 to quit? 10

 userBet is: 10

 whirrrrrr .... and your pull is ...

 BAR cherries space

 Sorry, you lose.

 How much would you like to bet (1-100) or 0 to quit? 100

 userBet is: 100

 whirrrrrr .... and your pull is ...

 7 BAR 7

 Sorry, you lose.

 How much would you like to bet (1-100) or 0 to quit? 99

 userBet is: 99

 whirrrrrr .... and your pull is ...

 BAR cherries space

 Sorry, you lose.

 How much would you like to bet (1-100) or 0 to quit? 0

 Goodbye...

 -------------------------------End Run ----------------------------*/
