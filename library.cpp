#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include <string>
#include "library.h"

using namespace std;

MovieList::MovieList(){
  head = NULL;
}

MovieList::~MovieList(){
  while(head != NULL){
    remove(head->title);
  }
}

void MovieList::read_from_file(std::string filename){
  fstream fin;

  fin.open(filename);
  fin.clear();

  string mtitle;
  string dName;
  int length;
  string fType;
  float priceTag;
  int mYear;

  fin.get();
  getline(fin, mtitle);
  getline(fin, dName);
  fin >> length;
  fin >> fType;
  fin >> priceTag;
  fin >> mYear;

  while(fin){
    insert_sorted(mtitle, dName, length, fType, priceTag, mYear);

    fin.get();
    getline(fin, mtitle);
    getline(fin, dName);
    fin >> length;
    fin >> fType;
    fin >> priceTag;
    fin >> mYear;
  }
}

void MovieList::write_to_file(std::string filename){
}

void MovieList::insert_sorted(string mtitle, string dName, int rTime, string filmForm, float priceTag, int fyear){
  Movie *insnode = new Movie;
  Movie *tmpnode = head;
  insnode->next = NULL;

  insnode->title = mtitle;
  insnode->director = dName;
  insnode->runtime = rTime;
  insnode->format = filmForm;
  insnode->price = priceTag;
  insnode->year = fyear;

  if(head == NULL){
    head = insnode;
    return;
  }
  if(insnode->title < head->title){
    tmpnode = head;
    head = insnode;
    head->next = tmpnode;
  }
  else{
    tmpnode = head;

    while(tmpnode->next != NULL && insnode->title > tmpnode->next->title){
      tmpnode = tmpnode->next;
    }
    if(tmpnode->next == NULL){
      tmpnode->next = insnode;
      return;
    }
    insnode->next = tmpnode->next;
    tmpnode->next = insnode;
  }
}

std::string MovieList::find_movie(std::string movieSearch){
}

std::string director_search(std::string directorSearch){
}

void MovieList::print(){
  Movie* current = head;

  while(current != NULL){
    cout << "\t" << current->title << endl;
    cout << "\tDirector: " << current->director << endl;
    cout << "\tRun Time: " << current->runtime << " minutes" << endl;
    cout << "\tFormat: " << current->format << endl;
    cout << "\tCost: $" << current->price << endl;
    cout << "\tYear Released: " << current-> year << endl;
    cout << endl;
  }
  delete current;
}

void MovieList::remove(string movieName){
  Movie *tmp = new Movie();
  Movie *eraser = new Movie();
  tmp->next = NULL;
  eraser->next = NULL;

  if(head == NULL){
    cout << "Uh oh, you don't have any movies" << endl;
    return;
  }

  if(head->title == movieName){
    eraser = head;
    head = head->next;
    //Eraser has been clearned out
    delete eraser;
    return;
  }
  tmp = head;
  
  while(tmp->next != NULL && (tmp->next->title != movieName)){
    tmp = tmp->next;
  }
  if(tmp->next == NULL){
    return;
  }
  eraser = tmp->next;
  tmp->next = eraser->next;
  
  delete eraser;
}
