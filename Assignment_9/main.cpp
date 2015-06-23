#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include <cstdlib>
using namespace std;

class PizzaOrder
{
public:
   static const int DEFAULT_SIZE = 0;

private:
   int size;
   string toppings[5];
   int numToppings = 0;
   double mediumConvFactor = 1.15;
   double largeConvFactor = 1.25;


public:
   static const string toppingsOffered[];
   static const double toppingBaseCost;
   static const double basePrice;

   //constructors
   PizzaOrder();
   PizzaOrder(int size);

   // mutators
   bool setSize(int size);
   bool addTopping(string topping);
   bool addTopping(int n);

   // accessor
   int getSize(){return size;}
   double getPrice();
   string stringizeSize();
   int getNumTopings();
   string getToppings(string &listOfToppings);
   void displayPizza();

   //helper methods
   string lowerCase(string inputString);


};

// init const values
string const PizzaOrder::toppingsOffered[] = {"Bacon", "Sausage","Pepperoni",
   "Chicken", "Olives", "Onions",
   "Green Peppers", "Mushrooms"};
double const PizzaOrder::toppingBaseCost = 1.50;
double const PizzaOrder::basePrice = 12.0;

// helper methods
void displayToppings();
bool isInt(string str);
bool isTopping(string str);


int main() {
   PizzaOrder *order = new PizzaOrder[3];


   for (int i = 0; i < 3; i++)
   {
      string pizzaSize;
      cout << "Select size of pizza (small, medium, large) or quit: ";
      while (tolower(pizzaSize[0]) != 'q') {
         getline(cin, pizzaSize);
         bool validSize =  false;

         if (tolower(pizzaSize[0]) == 's')
         {
            order[i].setSize(0);
            validSize = true;
         }
         else if (tolower(pizzaSize[0]) == 'm')
         {
            order[i].setSize(1);
            validSize = true;
         }
         else if (tolower(pizzaSize[0]) == 'l')
         {
            order[i].setSize(2);
            validSize = true;
         }
         else
            cout << "Invalid input, select (small, medium, large) or quit: ";

         while ( validSize && order[i].getNumTopings() <= 5)
         {
            string userSelection;


            if (order[i].getNumTopings() == 5)
            {
               cout << "Cannot chose more than 5 toppings, Thanks for your"
               " order of: ";
               order[i].displayPizza();
               cout << endl;
               break;
            }

            cout << endl << "Current Pizza: ";
            order[i].displayPizza();
            cout << endl;

            cout << "Select an item by number or name (0 when done): " << endl;
            displayToppings();
            cout << "Selection: ";
            getline(cin, userSelection);

            if (isInt(userSelection))
            {
               if (stoi(userSelection) == 0)
               {
                  cout << "Thanks for your order of: ";
                  order[i].displayPizza();
                  cout << endl;
                  break;
               }
               if (order[i].addTopping(stoi(userSelection) - 1))
                  continue;
               else
               {
                  cout << "Invalid selection, please try again" << endl;
                  continue;
               }
            }
            else
            {
               if (order[i].addTopping(userSelection))
                  continue;
               else
               {
                  cout << "Invalid selection, please try again" << endl;
                  continue;
               }
            }
         }
         break;
      }
   }

   order[0].displayPizza();
   order[1].displayPizza();
   order[2].displayPizza();
}

PizzaOrder::PizzaOrder()
{
   setSize(DEFAULT_SIZE);

}

PizzaOrder::PizzaOrder(int n)
{
   if(!setSize(n))
      setSize(DEFAULT_SIZE);
}

bool PizzaOrder::setSize(int size)
{
   // check for correct input
   //
   if (size >= 0 && size < 3)
   {
      this->size = size;
      return true;
   }
   else
      return false;

}

bool PizzaOrder::addTopping(string topping)
{
   int arraySize = sizeof(toppingsOffered) / sizeof(toppingsOffered[0]);

   if (numToppings < 5)
   {
      for (int i = 0; i < arraySize; i++)
      {
         if (lowerCase(toppingsOffered[i]) == lowerCase(topping))
         {
            toppings[numToppings++] = toppingsOffered[i];
            return true;
         }
      }
   }
   return false;
}


bool PizzaOrder::addTopping(int n)
{
   int arraySize = sizeof(toppingsOffered) / sizeof(toppingsOffered[0]);

   if (numToppings < 5)
   {
      if (n >= 0 && n < arraySize)
      {
         toppings[numToppings++] = toppingsOffered[n];
         return true;
      }
   }
   return false;
}

double PizzaOrder::getPrice()
{
   double price = 0;

   double toppingCost = numToppings * toppingBaseCost;
   if (getSize() == 0)
      price = basePrice + toppingCost;
   else if (getSize() == 1)
      price = basePrice * mediumConvFactor + toppingCost;
   else
      price = basePrice * largeConvFactor + toppingCost;

   return price;
}

string PizzaOrder::stringizeSize()
{
   if (getSize() == 0)
      return "Small";
   else if (getSize() == 1)
      return "Medium";
   else
      return "Large";
}

string PizzaOrder::getToppings(string &listOfToppings)
{

   for (int i = 0; i < numToppings; i++)
   {
      listOfToppings += " + " + toppings[i];
   }

   return listOfToppings;

}

void PizzaOrder::displayPizza()
{
   string toppings = "";

   cout << stringizeSize() << getToppings(toppings) << ", $" << getPrice()
   << endl;
}

int PizzaOrder::getNumTopings()
{
   return numToppings;
}


string PizzaOrder::lowerCase(string inputString)
{
   string resultString;

   for (int i = 0; i < inputString.length(); i++)
   {
      resultString += tolower(inputString[i]);
   }

   return resultString;
}

void displayToppings()
{
   int arraySize = sizeof(PizzaOrder::toppingsOffered) /
   sizeof(PizzaOrder::toppingsOffered[0]);

   for (int i = 0; i < arraySize; i++)
   {
      cout << " " << i + 1 << ". " << PizzaOrder::toppingsOffered[i] << endl;
      cout << endl;
   }
}

bool isInt(string str)
{
   bool isValid = false;

   for (int i = 0; i < str.length(); i++)
   {
      if(isdigit(str[i]))
         isValid = true;
      else
      {
         isValid = false;
         break;
      }
   }
   return isValid;
}


/*--------------------------- Start Run ------------------------------
 Select size of pizza (small, medium, large) or quit: s

 Current Pizza: Small, $12

 Select an item by number or name (0 when done):
 1. Bacon

 2. Sausage

 3. Pepperoni

 4. Chicken

 5. Olives

 6. Onions

 7. Green Peppers

 8. Mushrooms

 Selection: 1

 Current Pizza: Small + Bacon, $13.5

 Select an item by number or name (0 when done):
 1. Bacon

 2. Sausage

 3. Pepperoni

 4. Chicken

 5. Olives

 6. Onions

 7. Green Peppers

 8. Mushrooms

 Selection: 0
 Thanks for your order of: Small + Bacon, $13.5

 Select size of pizza (small, medium, large) or quit: m

 Current Pizza: Medium, $13.8

 Select an item by number or name (0 when done):
 1. Bacon

 2. Sausage

 3. Pepperoni

 4. Chicken

 5. Olives

 6. Onions

 7. Green Peppers

 8. Mushrooms

 Selection: 2

 Current Pizza: Medium + Sausage, $15.3

 Select an item by number or name (0 when done):
 1. Bacon

 2. Sausage

 3. Pepperoni

 4. Chicken

 5. Olives

 6. Onions

 7. Green Peppers

 8. Mushrooms

 Selection: 3

 Current Pizza: Medium + Sausage + Pepperoni, $16.8

 Select an item by number or name (0 when done):
 1. Bacon

 2. Sausage

 3. Pepperoni

 4. Chicken

 5. Olives

 6. Onions

 7. Green Peppers

 8. Mushrooms

 Selection: 0
 Thanks for your order of: Medium + Sausage + Pepperoni, $16.8

 Select size of pizza (small, medium, large) or quit: l

 Current Pizza: Large, $15

 Select an item by number or name (0 when done):
 1. Bacon

 2. Sausage

 3. Pepperoni

 4. Chicken

 5. Olives

 6. Onions

 7. Green Peppers

 8. Mushrooms

 Selection: 1

 Current Pizza: Large + Bacon, $16.5

 Select an item by number or name (0 when done):
 1. Bacon

 2. Sausage

 3. Pepperoni

 4. Chicken

 5. Olives

 6. Onions

 7. Green Peppers

 8. Mushrooms

 Selection: 2

 Current Pizza: Large + Bacon + Sausage, $18

 Select an item by number or name (0 when done):
 1. Bacon

 2. Sausage

 3. Pepperoni

 4. Chicken

 5. Olives

 6. Onions

 7. Green Peppers

 8. Mushrooms

 Selection: 3

 Current Pizza: Large + Bacon + Sausage + Pepperoni, $19.5

 Select an item by number or name (0 when done):
 1. Bacon

 2. Sausage

 3. Pepperoni

 4. Chicken

 5. Olives

 6. Onions

 7. Green Peppers

 8. Mushrooms

 Selection: 4

 Current Pizza: Large + Bacon + Sausage + Pepperoni + Chicken, $21

 Select an item by number or name (0 when done):
 1. Bacon

 2. Sausage

 3. Pepperoni

 4. Chicken

 5. Olives

 6. Onions

 7. Green Peppers

 8. Mushrooms

 Selection: 5
 Cannot chose more than 5 toppings, Thanks for your order of: Large + Bacon + Sausage + Pepperoni + Chicken + Olives, $22.5
 
 Small + Bacon, $13.5
 Medium + Sausage + Pepperoni, $16.8
 Large + Bacon + Sausage + Pepperoni + Chicken + Olives, $22.5
 ------------------------------ End Run -------------------------------*/