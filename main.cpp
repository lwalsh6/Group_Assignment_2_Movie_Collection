/**
 * @file main.cpp
 * @author Logan Walsh/Zachary Rose
 * @date 2022-10-27
 * @brief Movie Collection Program
 * 
 * This program allows the user to import and alter a list of movies from a file
 */

#include <iostream>
#include "library.h"

using namespace std;

int main() {
  library MyFilms;

  string filename;
  string selection;

  string mTitle;
  string directName;
  int fLength;
  string form;
  float cost;
  int releaseYear;
  
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

  while(selection != "8"){

    if (selection == "1"){
      cout << "Enter the filename of the collection: ";
      cin >> filename;

      MyFilms.read_from_file(filename);
    }

    else if (selection == "2"){
      string newFile;
      cout << "Enter a file to write to: ";
      cin >> newFile;
      
      MyFilms.write_to_file(newFile);
    }
    
    else if (selection == "3"){
      MyFilms.print();
    }

    else if (selection == "4"){
      cout << "Enter the Title (Case Sensitive): ";
      cin.get();
      getline(cin, mTitle);

      MyFilms.find_movie(mTitle);
    }

    else if (selection == "5"){
      cout << "Enter the Name of the Director (Case Sensitive): ";
      cin.get();
      getline(cin, directName);

      MyFilms.director_search(directName);
    }
    
    else if (selection == "6"){
      cout << "Enter the Title: ";
      cin.get();
      getline(cin, mTitle);
      cout << "Enter the Director's Name: ";
      getline(cin, directName);
      cout << "Enter the Runtime (in Minutes): ";
      cin >> fLength;
      cout << "Enter the Movie's Format (Blu-Ray, DVD, Laserdisc etc.): ";
      cin >> form;
      cout << "Enter how much you paid for the movie: ";
      cin >> cost;
      cout << "Enter the year when the movie was released: ";
      cin >> releaseYear;

      MyFilms.insert_sorted(mTitle, directName, fLength, form, cost, releaseYear);
    }
    else if (selection == "7"){
      cout << "Enter the Title: ";
      cin.get();
      getline(cin, mTitle);
      
      MyFilms.remove(mTitle);
    }
    else{
      cout << "That is not an option..." << endl;
    }
    
    cout << "Enter another command: ";
    cin >> selection;
  }
  return 0;
}
