//
//  main.cpp
//  Foothill_Assignment3
//
//  Created by Tarun Banda on 4/29/15.
//  Copyright (c) 2015 Tarun Banda. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
   // static variables
   double DOLLARS_PER_WH = .00005;
   int MAX_WATTS = 100000;
   int MAX_HOURS = 24;

   // variables for watts and hours
   int watt1, watt2, watt3, hour1, hour2, hour3;
   int totalWattHours;
   double electricBill;

   // tempVal stores the value for each user input
   string tempVal;


   //take user input for watts and hours for water heater
   cout << "How many Watts for the Water Heater? ";
   getline(cin, tempVal);
   istringstream(tempVal) >> watt1;

   cout << "\nHow many hours/day do you run the Water Heater? ";
   getline(cin, tempVal);
   istringstream(tempVal) >> hour1;

   //take user input for watts and hours for computer equipment
   cout << "\nHow many Watts for the Computer Equipment? ";
   getline(cin, tempVal);
   istringstream(tempVal) >> watt2;

   cout << "\nHow many hours/day do you run the Computer Equipment? ";
   getline(cin, tempVal);
   istringstream(tempVal) >> hour2;

   //take user input for watts and hours for lights
   cout << "\nHow many Watts for the Lights? ";
   getline(cin, tempVal);
   istringstream(tempVal) >> watt3;

   cout << "\nHow many hours/day do you run the Lights? ";
   getline(cin, tempVal);
   istringstream(tempVal) >> hour3;

   //check for errors
   if ((watt1 > 0 && watt1 <= MAX_WATTS) && (watt2 > 0 && watt2 <= MAX_WATTS)
       && (watt3 > 0 && watt3 <= MAX_WATTS))
   {
      if ((hour1 > 0 && hour1 <= MAX_HOURS) && (hour2 > 0 && hour2 <= MAX_HOURS)
          && (hour3 > 0 && hour3 <= MAX_HOURS))
      {
         // final calculations
         totalWattHours = 30*(watt1*hour1 + watt2*hour2 + watt3*hour3);
         electricBill = totalWattHours*DOLLARS_PER_WH;
      }
      else
      {
         cout << "\nError: Invalid input" << endl;
         return (0);
      }

   }
   else
   {
      cout << "\nError: Invalid input" << endl;
      return (0);
   }

   cout << "\nYou have used " << totalWattHours << " Watt-Hours "
   "of electricity" << endl;
   cout << "\nYour total bill this month is $" << electricBill << endl;

   return (0);

}

/* ------------------- Sample Run(1) --------------------

 How many Watts for the Water Heater? 4500

 How many hours/day do you run the Water Heater? 12

 How many Watts for the Computer Equipment? 1500

 How many hours/day do you run the Computer Equipment? 24

 How many Watts for the Lights? 1000

 How many hours/day do you run the Lights? 16

 You have used 3180000 Watt-Hours of electricity

 Your total bill this month is $159

 ---------------------- End Sample Run(1) ---------------- */



/* ------------------- Sample Run(2) --------------------

 How many Watts for the Water Heater? -12000

 How many hours/day do you run the Water Heater? 10

 How many Watts for the Computer Equipment? 1400

 How many hours/day do you run the Computer Equipment? 24

 How many Watts for the Lights? 4500

 How many hours/day do you run the Lights? 4

 Error: Invalid input

 ---------------------- End Sample Run(2) ---------------- */



/* ------------------- Sample Run(3) --------------------

 How many Watts for the Water Heater? 10000

 How many hours/day do you run the Water Heater? 40

 How many Watts for the Computer Equipment? 4000

 How many hours/day do you run the Computer Equipment? 10

 How many Watts for the Lights? 1000

 How many hours/day do you run the Lights? 10

 Error: Invalid input

 ---------------------- End Sample Run(3) ---------------- */


