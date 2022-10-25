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
  
  getline(fin, temp.title);
  getline(fin, temp.director);
  fin >> temp.runtime;
  fin >> temp.format;
  fin >> temp.price;
  fin >> temp.year;

  while(fin){
    insert_sorted(temp.title, temp.director, temp.runtime, temp.format, temp.price, temp.Year);

    fin.get();
    getline(fin, temp.title);
    getline(fin, temp.director);
    fin >> temp.runtime;
    fin >> temp.format;
    fin >> temp.price;
    fin >> temp.year;
    /* getline(fin, mtitle);
    getline(fin, dName);
    fin >> length;
    fin >> fType;
    fin >> priceTag;
    fin >> mYear; */
  }
}

void MovieList::write_to_file(std::string filename){
  Movie* add = head;
  fstream fin;
  ofstream fout;
  fout.open(filename);
  fin.clear();

  cout << "Writing to new collection...chill out for a sec" << endl;
  while(add != NULL){
    fout << add->title << endl;
    fout << add->director << endl;
    fout << add->runtime << endl;
    fout << add->format << endl;
    fout << add->price << endl;
    fout << add->year << endl;

    add = add->next;
  }
  cout << "Done! Now you can celebrate!" << endl;
  fout.close();
}

void MovieList::insert_sorted(string mtitle, string dName, int rTime, string filmForm, float priceTag, int fyear){
  Movie ins;
  Movie tmp;
  
  ins.title = mtitle;
  ins.director = dName;
  ins.runtime = rTime;
  ins.format = filmForm;
  ins.price = priceTag;
  ins.year = fyear;

  list<movie>::iterator head;
  //?
  if(head == NULL){
    head = ins;
    return;
  }
  if(ins.title < head.title){
    //?
    //tmpnode = head;
    //head = insnode;
    //head->next = tmpnode;
    Movie.push_back(ins);
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

    current = current->next;
  }
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
