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

class library{
 private:
  std::list<Movie> movies;
  
 public:
  library();
  ~library();
  void read_from_file(std::string filename);
  void write_to_file(std::string filename);
  void insert_sorted(std::string mtitle, std::string dName, int rTime, std::string filmForm, float priceTag, int fyear);
  void find_movie(std::string movieSearch);
  void director_search(std::string directorSearch);
  void print();
  void remove(std::string movieName);
};

#endif //LIBRARY_H
