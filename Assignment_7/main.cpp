#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class iTune
{
private:
   string name, artist;
   int bitrate, total_time;

public:
   // class constants
   static const int MIN_BITRATE;
   static const int MAX_BITRATE;
   static const int MIN_STR_LENGTH;
   static const int MAX_STR_LENGTH;
   static const int MIN_PLAY_TIME;
   static const int MAX_PLAY_TIME;
   static const int DEFAULT_BITRATE;
   static const int DEFAULT_PLAY_TIME;
   static const int MILLISECONDS_IN_SEC;
   static const int SECONDS_IN_MIN;
   static const string DEFAULT_STRING;



   // accessors
   bool setName(string name);
   string getName();
   bool setArtist(string artist);
   string getArtist();
   bool setBitrate(int bitrate);
   int getBitrate();
   bool setTotal_time(int total_time);
   int getTotal_time();


   //constructors
   iTune();
   iTune(string name,string artist, int bitrate, int total_time);

   //other public methods
   string toString();
   void display();



};

// static member intialization
int const iTune::MIN_BITRATE = 64;
int const iTune::MAX_BITRATE = 705;
int const iTune::MIN_STR_LENGTH = 1;
int const iTune::MAX_STR_LENGTH = 80;
int const iTune::MIN_PLAY_TIME = 1;
int const iTune::MAX_PLAY_TIME = 1000*60*60;
int const iTune::DEFAULT_BITRATE = 64;
int const iTune::DEFAULT_PLAY_TIME = 0;
int const iTune::MILLISECONDS_IN_SEC = 1000;
int const iTune::SECONDS_IN_MIN = 60;
string const iTune::DEFAULT_STRING = " (undefined) ";

// method prototypes


int main()
{
   iTune song1;

   cout << "iTunes Song -------:" << endl << endl;
   // default constructor, should contain default values
   cout << "Song1" << endl;
   song1.display();


   // adding a value for each parameter, using mutators
   song1.setName("Thunderstruck");
   song1.setArtist("AC/DC");
   song1.setTotal_time(180000);
   song1.setBitrate(120);

   // object song1 should contain mutated values
   cout << "Song1" << endl;
   song1.display();

   //constructing song2 using the overloaded constructor
   iTune song2("Let it Go", "Idida Menzel", 240, 150000);

   // song2 should contain each of the arguments that were passed
   // via that constructor
   cout << "Song2" << endl;
   song2.display();


   // entering wrong input values, should result in default numbers
   iTune song3("", "", 63, -234);

   cout << "Song3" << endl;
   song3.display();


   string longName = "TOO LONG A NAME TOO LONG A NAME TOO LONG A NAME TOO LONG"
   "TOO LONG A NAME TOO LONG A NAME TOO LONG A NAME";

   cout << "Song4" << endl;
   iTune song4 (longName , "The Shins", 250, 190000);
   song4.display();

   // show accessor function
   cout << "Song4 getArtist: " << song4.getArtist() << endl;
   cout << "Song4 getName: " << song4.getName() << endl;
   cout << "Song4 getTotal_time: " << song4.getTotal_time() << endl;
   cout << "Song4 getBitrate: " << song4.getBitrate() << endl;



}

iTune::iTune()
{
   setName(DEFAULT_STRING);
   setArtist(DEFAULT_STRING);
   setBitrate(DEFAULT_BITRATE);
   setTotal_time(DEFAULT_PLAY_TIME);
}

iTune::iTune(string name,string artist, int bitrate, int total_time)
{
   if (!setName(name))
      setName(DEFAULT_STRING);
   if (!setArtist(artist))
      setArtist(DEFAULT_STRING);
   if (!setBitrate(bitrate))
      setBitrate(DEFAULT_BITRATE);
   if (!setTotal_time(total_time))
      setTotal_time(DEFAULT_PLAY_TIME);
}


bool iTune::setName(string name)
{
   if (name.length() >= MIN_STR_LENGTH && name.length() <= MAX_STR_LENGTH)
   {
      this->name = name;
      return true;
   }
   else
      return false;
}

string iTune::getName()
{
   return name;
}

bool iTune::setArtist(string artist)
{
   if (artist.length() > MIN_STR_LENGTH && artist.length() <= MAX_STR_LENGTH)
   {
      this->artist = artist;
      return true;
   }
   else
      return false;

}

string iTune::getArtist()
{
   return artist;
}


bool iTune::setBitrate(int bitrate)
{
   if (bitrate >= MIN_BITRATE && bitrate <= MAX_BITRATE)
   {
      this->bitrate = bitrate;
      return true;
   }
   else
      return false;
}

int iTune::getBitrate()
{
   return bitrate;
}


bool iTune::setTotal_time(int total_time)
{
   if (total_time >= MIN_PLAY_TIME && total_time <= MAX_PLAY_TIME)
   {
      this->total_time = total_time;
      return true;
   }
   else
      return false;
}

int iTune::getTotal_time()
{
   return total_time;
}


string iTune::toString()
{
   stringstream retString;
   string finalString;
   int minutes, seconds, modMin;

   minutes = getTotal_time() / (MILLISECONDS_IN_SEC * SECONDS_IN_MIN);
   modMin = getTotal_time() % (MILLISECONDS_IN_SEC * SECONDS_IN_MIN);
   seconds = modMin / MILLISECONDS_IN_SEC;

   retString << "Title: " << getName() << " / Artist: " << getArtist()
   << " / Playing Time: " << minutes << " Minutes and " << seconds
   << " Seconds"<< " / Bit Rate: " << getBitrate() << "k";

   finalString = retString.str();

   return finalString;
}

void iTune::display()
{

   cout << toString() << endl << endl;
}



/*-----------------------------Start Sample Run --------------------------

 iTunes Song -------:

 Song1
 Title:  (undefined)  / Artist:  (undefined)  / Playing Time: 0 Minutes and 0 Seconds / Bit Rate: 64k

 Song1
 Title: Thunderstruck / Artist: AC/DC / Playing Time: 3 Minutes and 0 Seconds / Bit Rate: 120k

 Song2
 Title: Let it Go / Artist: Idida Menzel / Playing Time: 2 Minutes and 30 Seconds / Bit Rate: 240k

 Song3
 Title:  (undefined)  / Artist:  (undefined)  / Playing Time: 0 Minutes and 0 Seconds / Bit Rate: 64k

 Song4
 Title:  (undefined)  / Artist: The Shins / Playing Time: 3 Minutes and 10 Seconds / Bit Rate: 250k

 Song4 getArtist: The Shins
 Song4 getName:  (undefined)
 Song4 getTotal_time: 190000
 Song4 getBitrate: 250
 
 -------------------------- End Sample Run -----------------------------*/