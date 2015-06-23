//
//  CS 2A - Assignment 2
//  Arithmetic, Data Types, Boolean Expressions
//  Created by Tarun Banda on 4/21/15.


#include <iostream>
using namespace std;

int main()
{
   int myId;
   int nLet;
   int intResult; //will store results for all ints
   double doubleResult;  //will store results for all doubles
   bool boolResult; //will store sreulsts for all boolean values

   //Set values for variables
   myId = 23;
   nLet = 5;

   //FoothillID and Last name
   cout << "My last(family) name is Banda" << endl << endl;
   cout << "My Student ID is 20190146" << endl << endl;
   cout << "The value of myId is " << myId << endl << endl;
   cout << "the number of characters in my last name is " << nLet
      << endl << endl;

   //Run through the expressions
   intResult = myId/2;
   cout << "Expression #1 -------------: " << intResult << endl << endl;

   intResult = myId % 2;
   cout << "Expression #2 -------------: " << intResult << endl << endl;

   intResult = 2 + 3 + 4 + 5;
   cout << "Expression #3 -------------: " << intResult << endl << endl;

   intResult = myId + nLet;
   cout << "Expression #4 -------------: " << intResult << endl << endl;

   intResult = myId * nLet;
   cout << "Expression #5 -------------: " << intResult << endl << endl;

   intResult = myId += nLet;
   cout << "Expression #6 -------------: " << intResult << endl << endl;

   intResult = myId *= nLet;
   cout << "Expression #7 -------------: " << intResult << endl << endl;

   intResult = nLet++;
   cout << "Expression #8 -------------: " << intResult << endl << endl;

   intResult = ++nLet;
   cout << "Expression #9 -------------: " << intResult << endl << endl;

   doubleResult = (double)(myId)/(nLet + 1100);
   cout << "Expression #10 -------------: " << doubleResult << endl << endl;

   boolResult = (nLet % nLet) && (myId * myId);
   cout << "Expression #11 -------------: " << boolResult << endl << endl;

   boolResult = (nLet -= nLet) || (myId);
   cout << "Expression #12 -------------: " << boolResult << endl << endl;
   
   return 0;
   
}

/*-------------------------Run----------------------------------
 
 My last(family) name is Banda

 My Student ID is 20190146

 The value of myId is 23

 the number of characters in my last name is 5

 Expression #1 -------------: 11

 Expression #2 -------------: 1

 Expression #3 -------------: 14

 Expression #4 -------------: 28

 Expression #5 -------------: 115

 Expression #6 -------------: 28

 Expression #7 -------------: 140

 Expression #8 -------------: 5

 Expression #9 -------------: 7

 Expression #10 -------------: 0.126468

 Expression #11 -------------: 0

 Expression #12 -------------: 1

 ---------------------------------------------------------------*/
