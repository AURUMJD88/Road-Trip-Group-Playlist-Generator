#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;
struct Song
{
  string title;
  string artist;
  int rating;
};
class Music
{
private:
  int rating;
  double songAvg;
  int listLimit;
  int plistLimit;
  double hours;
    vector < Song > allSongs;
public:
    Music (double h, int passengers):songAvg (17.15), hours (h)
  {
    listLimit = static_cast < int >((hours) * songAvg);
      plistLimit = listLimit / passengers;
  }
  int getListLimit () const
  {
    return plistLimit;
  }
  void addSong (const Song & s)
  {
    if (allSongs.size () < listLimit)
      {
	allSongs.push_back (s);
      }
    else
      {
	cout << "Song limit reached.\n";
      }
  }
  void display ()
  {
    cout << "________________________________________________";
    cout << "\n\nGenerated Song List Below: \n" <<endl;
  for (const auto & s:allSongs)
      {
	cout << "Title: " << s.title << ", Artist: " << s.
	  artist << "\n";
      }
  }
  void shuffleSongs ()
  {
    shuffle (allSongs.begin (), allSongs.end (),
		  default_random_engine (time (0)));
  }
  void sortSongsByRating ()
  {
    sort (allSongs.begin (), allSongs.end (),
	       [](const Song & a, const Song & b)
	       {
	       return a.rating < b.rating;}
    );
  }
};

int
main ()
{
  double hours;
  int passengers;
  int choice;
  int create = 1;
  int leave = 2;



  cout << "\n" <<endl;
  cout << " Welcome to the Roadtrip Generator!\n";

    cout << " At this time we will be asking a few questions to\n calculate how many songs will be needed for the trip.";

    cout <<" To make everything fair we will let you know how\n many songs each passenger can type in.";

    cout <<" Once typed in we will be able to randomize the list by rating\n and show you the playlist for the summer!";
    cout <<" Please print out list once done to have list ready\n prior to having issuer create CD.";
    cout << " \n";
    cout << "\n Let's Begin!\n";

  while (true)
    {
      cout << "Enter the number of hours: ";
      cin >> hours;
      cout << "Enter the number of passengers: ";
      cin >> passengers;
      Music playlist (hours, passengers);
      cout << "The limit of songs per passenger is: " << playlist.getListLimit () <<endl;
      for (int i = 0; i < passengers; i++)
	{
	  string name;
	  cout << "\n \nEnter passenger " << i + 1 << "'s name: ";
	  cin >> name;

	  for (int j = 0; j < playlist.getListLimit (); j++)
	    {
	      Song s;
	      cout << "\nEnter song title: ";
	      cin.ignore ();
	      getline (cin, s.title);
	      cout << "Enter song artist: ";
	      getline (cin, s.artist);
	      cout << "Enter song rating (1-5): ";
	      cin >> s.rating;
	      playlist.addSong (s);
	    }
	}
      playlist.shuffleSongs ();
      playlist.sortSongsByRating ();
      playlist.display ();


      cout << "Good Job! Please select an option below\n" <<endl;

	cout <<	"Would you like to create a new one or leave the program? \n (create(1)/leave(2)): ";
      cin >> choice;
      if (choice == 1)
	{

	    cout <<"-----------------------------------------------------------------------\n \n";
	  continue;
	}
      else if (choice == 2)
	{
	  return 0;
	}
    }
  return 0;
}




