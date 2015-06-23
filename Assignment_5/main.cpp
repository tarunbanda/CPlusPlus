//
//  main.cpp
//  Assignment 5
//
//  Created by Tarun Banda on 5/13/15.
//  Copyright (c) 2015 Tarun Banda. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// method prototypes
string getString();
string convertToUpper(string theString);
string convertToLower(string theString);
int countVowels(string theString);
int countConsonants(string theString);
string reverseStr(string theString);
bool isVowel(char character);
void printResults(string upper, string lower, int vowels, int consonants,
                  string reverse);


// main that calls necessary methods
int main()
{
   string userInput, upperCase, lowerCase,reverse;
   int numVowels, numConsonants;

   userInput = getString();
   upperCase = convertToUpper(userInput);
   lowerCase = convertToLower(userInput);
   numVowels = countVowels(userInput);
   numConsonants = countConsonants(userInput);
   reverse = reverseStr(userInput);
   printResults(upperCase, lowerCase,numVowels, numConsonants, reverse);
}


string getString()
{
   string prompt;
   string input;

   prompt = "\nPlease enter a phrase or sentence:";
   cout << prompt;
   getline(cin, input);
   return input;
}

// converts string to upper case
string convertToUpper(string theString)
{
   for (int i = 0; i < theString.length(); i++)
      theString[i] = toupper(theString[i]);

   return theString;
}

// converts string to lower case
string convertToLower(string theString)
{
   for (int i = 0; i < theString.length(); i++)
      theString[i] = tolower(theString[i]);

   return theString;
}

// counts the number of vowels in the string
int countVowels(string theString)
{
   int vowelCount = 0;

   for (int i = 0; i < theString.length(); i++)
   {
      if (isVowel(theString[i]))
         vowelCount++;
   }
   return vowelCount;
}

// counts the number of consonants in the string
int countConsonants(string theString)
{
   int consonantCount = 0;
   for (int i = 0; i < theString.length(); i++)
   {
      if (isalpha(theString[i]) && !isVowel(theString[i]))
         consonantCount++;
   }
   return consonantCount;
}

// creates a replica of the string and reverses it
string reverseStr(string theString)
{
   string revString = theString;

   for(int i = 0; i < theString.length(); i++)
      revString[theString.length() - i - 1] = theString[i];
   return revString;
}

// helper class to check for vowels
bool isVowel(char singleChar)
{

   if (toupper(singleChar) == 'A')
      return true;
   else if (toupper(singleChar) == 'E')
      return true;
   else if (toupper(singleChar) == 'I')
      return true;
   else if (toupper(singleChar) == 'O')
      return true;
   else if (toupper(singleChar) == 'U')
      return true;

   return false;
}

// helper class that prints the necessary out put
void printResults(string upper, string lower, int vowels, int consonants,
                  string reverse)
{
   cout << "UPPER CASED: " << upper << endl;
   cout << "lower cased: " << lower << endl;
   cout << "Number of Vowels: " << vowels << endl;
   cout << "Number of Consonants: " << consonants << endl;
   cout << "In Reverse: " << reverse << endl;
   cout << "\n\nGoodbye..." << endl;
}



/*--------------------Sample Run-------------------------------------

 Please enter a phrase or sentence:ABCxyz123 #$^)#
 UPPER CASED: ABCXYZ123 #$^)#
 lower cased: abcxyz123 #$^)#
 Number of Vowels: 1
 Number of Consonants: 5
 In Reverse: #)^$# 321zyxCBA


 Goodbye...
 
 ----------------------End of Run ----------------------------------*/

