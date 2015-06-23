#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

class DateProfile
{
private:
   char gender;
   char searchGender;
   int romance;
   int finance;
   string  name;

public:
   static const char DEFAULT_GENDER;
   static const char DEFAULT_SEARCH_GENDER;
   static const int DEFAULT_ROMANCE;
   static const int DEFAULT_FIANCE;
   static const string DEFAULT_NAME;

   static const int MIN_INT_VALUE;
   static const int MAX_INT_VALUE;
   static const int MAX_NAME_LENGTH;
   static const double DEFAULT_TRUE_DOUBLE;


public:
   // accessors
   char getGender(){ return gender;}
   char getSearchGender() { return searchGender; }
   int getRomance() { return romance; }
   int getFinance() { return finance; }
   string getName() { return name; }

   // mutators
   bool setGender(char gender);
   bool setSearchGender(char searchGender);
   bool setRomance(int romance);
   bool setFinance(int finance);
   bool setName(string name);

   // constructors
   DateProfile();
   DateProfile(char gender, char searchGender, int romance, int finance,
               string name);

   // public methods
public:
   double fitValue(DateProfile partner);
   string toString();
   void display();

   // other methods
private:
   double determineGenderFit(DateProfile partner);
   double determineRomanceFit(DateProfile partner);
   double determineFinanceFit(DateProfile partner);

   // helper methods
   double compareFit(double a, double b);


};

const char DateProfile::DEFAULT_GENDER = 'M';
const char DateProfile::DEFAULT_SEARCH_GENDER = 'F';
const int DateProfile::DEFAULT_ROMANCE = 0;
const int DateProfile::DEFAULT_FIANCE = 0;
const string DateProfile::DEFAULT_NAME = "undefined name";
const int DateProfile::MAX_NAME_LENGTH = 30;
const int DateProfile::MIN_INT_VALUE = 0;
const int DateProfile::MAX_INT_VALUE = 10;
const double DateProfile::DEFAULT_TRUE_DOUBLE = 1.0;


int main() {

   // check default constuctor
   cout << "check default constuctor" << endl << endl;
   DateProfile applicant1;
   applicant1.display();

   // check argument constructor
   cout << "check argument constructor" << endl << endl;
   DateProfile applicant2('M', 'F', 10, 7, "Tarun Banda");
   applicant2.display();

   DateProfile applicant3('f', 'm', 8, 7, "Jennifer Lawrence");
   applicant3.display();

   // check fitVal
   cout << "check fitValue between applicant2 and applicant 3: ";
   double app2_match_app3 = applicant2.fitValue(applicant3);
   cout << app2_match_app3 << endl << endl;

   cout << "create applicant 4" << endl;
   DateProfile applicant4('f', 'f', 2, 3, "Ellen DeGeneres");
   applicant4.display();

   cout << "check match between applicant2 and applicant 4: ";
   double app2_match_app4 = applicant2.fitValue(applicant4);
   cout << app2_match_app4 << endl << endl;

   //check mutators
   cout << "check mutator functionality" << endl << endl;
   applicant1.setName("Bradley Cooper");
   applicant1.setGender('M');
   applicant1.setSearchGender('F');
   applicant1.setRomance(7);
   applicant1.setFinance(9);

   // display new applicant1
   applicant1.display();

   string illegalString = "ABCDEFGHABCDEFGHABCDEFGHABCDEFGHABCDEFGHABCDEFGH";

   //check for illegal values, which should still have the last valid values
   cout << "check impact of illegal parameters, applicant should have last"
         "known valid parameter" << endl << endl;
   applicant1.setName(illegalString);
   applicant1.setGender('z');
   applicant1.setSearchGender('0');
   applicant1.setRomance(4000);
   applicant1.setFinance(-1);

   applicant1.display();

   DateProfile dateProfileArray[] = {applicant1, applicant2, applicant3,
                                    applicant4};

   int arraySize = sizeof(dateProfileArray) / sizeof(dateProfileArray[0]);

   cout << "Show match matrix between all four applicants" << endl << endl;
   for (int i = 0; i < arraySize; i++)
   {
      cout << "Name: " << dateProfileArray[i].getName() << endl << endl;
      for ( int j = 0; j < arraySize; j++)
      {
         cout << " " << dateProfileArray[j].getName() << " fit: ";
         cout << dateProfileArray[i].fitValue(dateProfileArray[j]) << endl
            << endl;
      }
   }




}

DateProfile::DateProfile()
{
   setGender(DEFAULT_GENDER);
   setSearchGender(DEFAULT_SEARCH_GENDER);
   setRomance(DEFAULT_ROMANCE);
   setFinance(DEFAULT_FIANCE);
   setName(DEFAULT_NAME);
}

DateProfile::DateProfile(char gender, char searchGender, int romance,
                        int finance, string name)
{
   if (!setGender(gender))
      setGender(DEFAULT_GENDER);
   if (!setSearchGender(searchGender))
      setSearchGender(DEFAULT_SEARCH_GENDER);
   if (!setRomance(romance))
      setRomance(DEFAULT_ROMANCE);
   if (!setFinance(finance))
      setFinance(DEFAULT_FIANCE);
   if (!setName(name))
      setName(DEFAULT_NAME);

}


bool DateProfile::setGender(char gender)
{
   if (toupper(gender) == 'M' || toupper(gender) == 'F')
   {
      this->gender = toupper(gender);
      return true;
   }
   else
      return false;
}


bool DateProfile::setSearchGender(char searchGender)
{
   if (toupper(searchGender) == 'M' || toupper(searchGender) == 'F')
   {
      this->searchGender = toupper(searchGender);
      return true;
   }
   else
      return false;
}

bool DateProfile::setRomance(int romance)
{
   if (romance > MIN_INT_VALUE && romance <= MAX_INT_VALUE)
   {
      this->romance = romance;
      return true;
   }
   else
      return false;
}

bool DateProfile::setFinance(int finance)
{
   if (finance > MIN_INT_VALUE && finance <= MAX_INT_VALUE)
   {
      this->finance = finance;
      return true;
   }
   else
      return false;
}

bool DateProfile::setName(string name)
{
   bool valid = false;

   if (name.length() < MAX_NAME_LENGTH)
   {
      for (int i = 0; i < name.length(); i++)
      {
         if(isalpha(name[i]) || isspace(name[i]))
            valid = true;
         else
         {
            valid = false;
            break;
         }
      }
      this->name = name;
   }
   return valid;
}

double DateProfile::fitValue(DateProfile partner)
{
   double genFit = determineGenderFit(partner);
   double finFit = determineFinanceFit(partner);
   double romFit = determineRomanceFit(partner);

   double fitVal = genFit*finFit*romFit;

   return fitVal;
}

double DateProfile::determineGenderFit(DateProfile partner)
{

   if (this ->getSearchGender() == partner.getGender())
   {
      if (this->getGender() == partner.getSearchGender())
         return DEFAULT_TRUE_DOUBLE;
   }
   return 0;
}


double DateProfile::determineFinanceFit(DateProfile partner)
{
   double financeFit = compareFit(this->getFinance(), partner.getFinance());
   return financeFit;
}

double DateProfile::determineRomanceFit(DateProfile partner)
{

   double romanceFit = compareFit(this->getRomance(), partner.getRomance());
   return romanceFit;
}


double DateProfile::compareFit(double a, double b)
{
   // divide the difference between two scores by the range of score
   // and then subtract from 1.0
   double diff = DEFAULT_TRUE_DOUBLE - (abs(a - b)/MAX_INT_VALUE);

   return diff;
}


string DateProfile::toString()
{
   stringstream retString;


   retString << "Name: " << getName() << endl << "Gender: " << getGender()
         << endl << "Looking for: " << getSearchGender() << endl
         << "Romance: " << getRomance() << endl << "Finance: "
         << getFinance() << endl;

   return retString.str();
}

void DateProfile::display()
{
   cout<< toString() << endl;
}



/*----------------------- Start Sample Run --------------------------------
 
 check default constuctor

 Name: undefined name
 Gender: M
 Looking for: F
 Romance: 0
 Finance: 0

 check argument constructor

 Name: Tarun Banda
 Gender: M
 Looking for: F
 Romance: 10
 Finance: 7

 Name: Jennifer Lawrence
 Gender: F
 Looking for: M
 Romance: 8
 Finance: 7

 check fitValue between applicant2 and applicant 3: 0.8

 create applicant 4
 Name: Ellen DeGeneres
 Gender: F
 Looking for: F
 Romance: 2
 Finance: 3

 check match between applicant2 and applicant 4: 0

 check mutator functionality

 Name: Bradley Cooper
 Gender: M
 Looking for: F
 Romance: 7
 Finance: 9

 check impact of illegal parameters, applicant should have lastknown valid parameter

 Name: Bradley Cooper
 Gender: M
 Looking for: F
 Romance: 7
 Finance: 9

 Show match matrix between all four applicants

 Name: Bradley Cooper

 Bradley Cooper fit: 0

 Tarun Banda fit: 0

 Jennifer Lawrence fit: 0.72

 Ellen DeGeneres fit: 0

 Name: Tarun Banda

 Bradley Cooper fit: 0

 Tarun Banda fit: 0

 Jennifer Lawrence fit: 0.8

 Ellen DeGeneres fit: 0

 Name: Jennifer Lawrence

 Bradley Cooper fit: 0.72

 Tarun Banda fit: 0.8

 Jennifer Lawrence fit: 0

 Ellen DeGeneres fit: 0

 Name: Ellen DeGeneres

 Bradley Cooper fit: 0

 Tarun Banda fit: 0
 
 Jennifer Lawrence fit: 0
 
 Ellen DeGeneres fit: 1

 ------------------------------ End Sample Run ----------------------*/





