#include <iostream>
#include "library.h"

using namespace std;

int main() {
  MovieList MyFilms;

  string filename;
  string selection;

  cout << "Oh No! This movie collection is really disorganized, pick an option to help fix it" << endl;
  cout << "1 Open a collection of Movies" << endl;
  cout << "2 Write the movie collection to a file" << endl;
  cout << "3 Print the collection of Movies" << endl;
  cout << "4 Search for a Movie" << endl;
  cout << "5 Search for a Director" << endl;
  cout << "6 Add a Movie to the collection" << endl;
  cout << "7 Sell a movie" << endl;
  cout << "8 Leave this program" << endl;

  cout << "Make your selection now: ";
  cin >> selection;

  while(selection != 8){
    
    cout << "Enter another command: ";
    cin >> selection;
  }
  return 0;
}
