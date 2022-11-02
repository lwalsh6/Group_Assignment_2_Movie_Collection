/**
 * @file library.cpp
 * @author Logan Walsh/Zachary Rose
 * @date 2022-10-27
 * @brief Movie Collection Functions
 * 
 * Movie collection implementation file
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include <string>
#include "library.h"
#include "Movie.h"

using namespace std;

void library::read_from_file(std::string filename){
  ifstream fin;

  fin.open(filename);
  if (!fin)
    return;

  Movie temp;
  // priming read
  getline(fin, temp.title);

  while(fin){

    getline(fin, temp.director);
    fin >> temp.runtime;
    fin >> temp.format;
    fin >> temp.price;
    fin >> temp.year;
    
    insert_sorted(temp.title, temp.director, temp.runtime, temp.format, temp.price, temp.year);
    // priming read
    fin.get();
    getline(fin, temp.title);
  }
  fin.close();
}

void library::write_to_file(std::string filename){
  list<Movie>::iterator write = movies.begin();
  
  ofstream fout;
  fout.open(filename);
  if (!fout)
    return;
  if (movies.empty()){
    fout.close();
    return;
  }
  
  cout << "Writing to new collection...chill out for a sec" << endl;
  while(write != movies.end()){
    fout << write->title << endl;
    fout << write->director << endl;
    fout << write->runtime << endl;
    fout << write->format << endl;
    fout << write->price << endl;
    fout << write->year << endl;
    write++;
  }
  cout << "Done! Now you can celebrate!" << endl;
  fout.close();
}

void library::insert_sorted(string mtitle, string dName, int rTime, string filmForm, float priceTag, int fyear){

  Movie ins;
  
  ins.title = mtitle;
  ins.director = dName;
  ins.runtime = rTime;
  ins.format = filmForm;
  ins.price = priceTag;
  ins.year = fyear;

  if (movies.empty()){
    movies.push_front(ins);
    return;
  }
  // the iterator will move until it hits past the last item or its title comes after the new Movie to add
  list<Movie>::iterator i = movies.begin();
  while (i != movies.end() && i->title < ins.title){
    i++;
  }
  // insert the new movie before the iterator i
  movies.insert(i, ins);
}

void library::find_movie(std::string movieSearch){
  cout << fixed << setprecision(2);
  cout << endl;
  
  for(list<Movie>::iterator search = movies.begin(); search != movies.end(); search++){
    //Searches for similarities until the end of the string
    if(search->title.find(movieSearch) != string::npos){
      cout << "\t" << search->title << endl;
      cout << "\tDirector: " << search->director << endl;
      cout << "\tRun Time: " << search->runtime << " minutes" << endl;
      cout << "\tFormat: " << search->format << endl;
      cout << "\tCost: $" << search->price << endl;
      cout << "\tYear Released: " << search-> year << endl << endl;
    }
  }
}

void library::director_search(std::string directorSearch){
  cout << fixed << setprecision(2);
  cout << endl;
  
  for(list<Movie>::iterator altsearch = movies.begin(); altsearch != movies.end(); altsearch++){
    if(altsearch->director.find(directorSearch) != string::npos){
      cout << "\t" << altsearch->title << endl;
      cout << "\tDirector: " << altsearch->director << endl;
      cout << "\tRun Time: " << altsearch->runtime << " minutes" << endl;
      cout << "\tFormat: " << altsearch->format << endl;
      cout << "\tCost: $" << altsearch->price << endl;
      cout << "\tYear Released: " << altsearch-> year << endl << endl;
    }
  } 
}

void library::print(){
  cout << fixed << setprecision(2);
  cout << endl;
  
  for(list<Movie>::iterator current = movies.begin(); current != movies.end(); current++){
    cout << "\t" << current->title << endl;
    cout << "\tDirector: " << current->director << endl;
    cout << "\tRun Time: " << current->runtime << " minutes" << endl;
    cout << "\tFormat: " << current->format << endl;
    cout << "\tCost: $" << current->price << endl;
    cout << "\tYear Released: " << current-> year << endl << endl;
  }
}

void library::remove(string movieName){
  list<Movie>::iterator rem = movies.begin();

  //Checks if there's nothing in the list
  if(movies.empty()){
    cout << "Uh oh, there's no movies in this collection!" << endl;
    return;
  }
  //Goes through the list checking every title
  while(rem != movies.end() && rem->title != movieName){
    //Next line in rem
    rem++;
  }
  //Removes movie from list if it exists
  if (rem != movies.end())
    movies.erase(rem);
}
