#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include <string>

struct Movie{
  std::string title;
  std::string director;
  int runtime;
  std::string format;
  float price;
  int year;
};

class MovieList{
 private:
  Movie* head;
  
 public:
  MovieList();
  ~MovieList();
  void read_from_file(std::string filename);
  void write_to_file(std::string filename);
  void insert_sorted(std::string mtitle, std::string dName, int rTime, std::string filmForm, float priceTag, int fyear);
  std::string find_movie(std::string movieSearch);
  std::string director_search(std::string directorSearch);
  void print();
  void remove();
};

#endif //LIBRARY_H
