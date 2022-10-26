#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include <string>
#include "library.h"

using namespace std;

library::library(){
  //  head = NULL;
}

library::~library(){
  // while(head != NULL){
  //   remove(head->title);
  // }
}

void library::read_from_file(std::string filename){
  ifstream fin;

  fin.open(filename);
  if (!fin)
    return;

  /*  string mtitle;
  string dName;
  int length;
  string fType;
  float priceTag;
  int mYear;

  getline(fin, mtitle);
  getline(fin, dName);
  fin >> length;
  fin >> fType;
  fin >> priceTag;
  fin >> mYear; */

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

std::string library::find_movie(std::string movieSearch){
  //temp
  return "";
}

std::string director_search(std::string directorSearch){
  //temp
  return "";
}

void library::print(){
 
  for(list<Movie>::iterator current = movies.begin(); current != movies.end(); current++){
    cout << "\t" << current->title << endl;
    cout << "\tDirector: " << current->director << endl;
    cout << "\tRun Time: " << current->runtime << " minutes" << endl;
    cout << "\tFormat: " << current->format << endl;
    cout << "\tCost: $" << current->price << endl;
    cout << "\tYear Released: " << current-> year << endl;
    cout << endl;
  }
}

void library::remove(string movieName){
  // Movie *tmp = new Movie();
  // Movie *eraser = new Movie();
  // tmp->next = NULL;
  // eraser->next = NULL;

  // if(head == NULL){
  //   cout << "Uh oh, you don't have any movies" << endl;
  //   return;
  // }

  // if(head->title == movieName){
  //   eraser = head;
  //   head = head->next;
  //   //Eraser has been clearned out
  //   delete eraser;
  //   return;
  // }
  // tmp = head;
  
  // while(tmp->next != NULL && (tmp->next->title != movieName)){
  //   tmp = tmp->next;
  // }
  // if(tmp->next == NULL){
  //   return;
  // }
  // eraser = tmp->next;
  // tmp->next = eraser->next;
  
  // delete eraser;
}
