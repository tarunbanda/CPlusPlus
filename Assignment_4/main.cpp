//
//  main.cpp
//  CWeek4
//
//  Created by Tarun Banda on 5/6/15.
//  Copyright (c) 2015 Tarun Banda. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
   int CURRENT_BALANCE = 5000;
   string tempInputVal;
   char userChoice;
   int inputAmount;
   bool STATUS = true;

   //shows user the menu until STATUS is set to false, this only happens when
      //theh user chooses to quit.
   while (STATUS == true)
   {

      cout << "\nMenu:\n\n W (Withdrawl)\n\n D (Deposit)\n\n B (Show Balance)\n\n"
      " Q (Quit)\n\n Your Choice:";
      getline(cin, tempInputVal);

      userChoice = toupper(tempInputVal[0]);
      if (userChoice == 'W')
      {
         cout << " Amount of Withdrawl (whole dollars only): " << endl;
         getline(cin, tempInputVal);
         istringstream(tempInputVal) >> inputAmount;
         if ((CURRENT_BALANCE - inputAmount) >= 0 && inputAmount >= 0)
         {
            CURRENT_BALANCE = CURRENT_BALANCE - inputAmount;
            cout << " Your current balance is $" << CURRENT_BALANCE << endl;
         }
         else
            cout << " Sorry, amounts must be between 0 and $" <<
            CURRENT_BALANCE << endl;
      }

      else if(userChoice == 'D')
      {
         cout << " Amount of Deposit (whole dollars only):" << endl;
         getline(cin, tempInputVal);
         istringstream(tempInputVal) >> inputAmount;
         if (inputAmount > 0)
         {
            CURRENT_BALANCE = CURRENT_BALANCE + inputAmount;
            cout << " Your current balance is $" << CURRENT_BALANCE << endl;
         }
         else
            cout << " Sorry, amount must be greater than 0" << endl;
      }

      else if(userChoice == 'B')
      {
         cout << " Your current balance is $" << CURRENT_BALANCE << endl;
      }

      else if (userChoice == 'Q')
      {
         STATUS = false;
         cout << "\n Goodbye" << endl;
         break;
      }
      else
         cout << " Use W, D, B, or Q, please" << endl;
   }
   return (0);
}


/* ----------- Output ----------------

 Menu:

 W (Withdrawl)

 D (Deposit)

 B (Show Balance)

 Q (Quit)

 Your Choice:w
 Amount of Withdrawl (whole dollars only):
 400
 Your current balance is $4600

 Menu:

 W (Withdrawl)

 D (Deposit)

 B (Show Balance)

 Q (Quit)

 Your Choice:w
 Amount of Withdrawl (whole dollars only):
 -4500
 Sorry, amounts must be between 0 and $4600

 Menu:

 W (Withdrawl)

 D (Deposit)

 B (Show Balance)

 Q (Quit)

 Your Choice:dep
 Amount of Deposit (whole dollars only):
 500
 Your current balance is $5100

 Menu:

 W (Withdrawl)

 D (Deposit)

 B (Show Balance)

 Q (Quit)

 Your Choice:D
 Amount of Deposit (whole dollars only):
 900
 Your current balance is $6000

 Menu:

 W (Withdrawl)

 D (Deposit)

 B (Show Balance)

 Q (Quit)

 Your Choice:W
 Amount of Withdrawl (whole dollars only):
 60001
 Sorry, amounts must be between 0 and $6000

 Menu:

 W (Withdrawl)

 D (Deposit)

 B (Show Balance)

 Q (Quit)

 Your Choice:cur
 Use W, D, B, or Q, please

 Menu:

 W (Withdrawl)

 D (Deposit)

 B (Show Balance)

 Q (Quit)

 Your Choice:Balance
 Your current balance is $6000

 Menu:

 W (Withdrawl)

 D (Deposit)

 B (Show Balance)

 Q (Quit)

 Your Choice:quit

 Goodbye

 ------------------------------------- */
