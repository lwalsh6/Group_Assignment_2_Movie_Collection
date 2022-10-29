/**
 * @file Movie.h
 * @author Logan Walsh/Zachary Rose
 * @date 2022-10-27
 * @brief Movie Node Struct
 * 
 * Contains all the information needed for a particular movie node
 */

#ifndef MOVIE_H
#define MOVIE_H

#include <string>


/**
 * A movie with a title, director, runtime, format such as DVD, price, and a year released
 *
 * @class Movie{ Movie.h "Group_Assignment_2_Movie_Collection/Movie.h"
 * @brief Movie struct
 *
 */
struct Movie{
  std::string title;
  std::string director;
  int runtime;
  std::string format;
  float price;
  int year;
};

#endif //MOVIE_H
