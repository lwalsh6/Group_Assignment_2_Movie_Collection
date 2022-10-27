/**
 * @file Movie.h
 * @author Logan Walsh/Zachary Rose
 * @date 2022-10-27
 * @brief Movie Node Struct
 * 
 * This only contains the struct for the movie node
 */

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include <string>
//#include "library.h"

struct Movie{
  std::string title;
  std::string director;
  int runtime;
  std::string format;
  float price;
  int year;
};

#endif //MOVIE_H
