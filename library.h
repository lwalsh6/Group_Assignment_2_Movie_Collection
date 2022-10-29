/**
 * @file library.h
 * @author Logan Walsh/Zachary Rose
 * @date 2022-10-27
 * @brief Movie Collection Header
 * 
 * The header file containing the function prototypes for the Movie Collection
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include <list>
#include <string>
#include "Movie.h"


/**
 * Movie collection class that holds a list of movies, and the ability to read/write to file, search the collection, and sorts alphabetically when added to the collection by the movie title
 *
 * @class library{ library.h "Group_Assignment_2_Movie_Collection/library.h"
 * @brief movie collection class
 *
 */
class library{
 private:
  //Movie list
  std::list<Movie> movies;
  
 public:
  
/**
 * Reads in a list of movies and their information
 *
 * @param std::string filename The name of the movie file
 * @pre called in main
 * @return void returns nothing
 * @post a list has been imported
 * 
 */
  void read_from_file(std::string filename);

/**
 * Writes the current list to a file
 *
 * @param std::string filename The name of the new file
 * @pre Called in main, movies need to be in the list for it to work
 * @post a new file has been written
 * 
 */
  void write_to_file(std::string filename);

/**
 * Imports movies into the list, also used to add movies
 *
 * @param std::string mtitle The title of the movie
 * @param std::string dName the director of the movie
 * @param int rTime the runtime
 * @param std::string filmForm the format of the movie
 * @param float priceTag the cost of the movie
 * @param int fyear the year it was released
 * @pre called in Read_from_file and in main
 * @post Movie has been added to the list in alphabetical order by title
 * 
 */
  void insert_sorted(std::string mtitle, std::string dName, int rTime, std::string filmForm, float priceTag, int fyear);

/**
 * locates a movie in the list based on the title
 *
 * @param std::string movieSearch The user's input
 * @post the movies that line up with that title are printed
 * 
 */
  void find_movie(std::string movieSearch);

/**
 * locates and prints movie information based on the director's name
 *
 * @param std::string directorSearch name of the director to search
 * @post the movies made by the director are printed
 * 
 */
  void director_search(std::string directorSearch);

/**
 * prints out the entire movie collection to the console
 *
 * @post movie collection printed to console
 * 
 */
  void print();

/**
 * removes a particular movie from the collection by title
 *
 * @param std::string movieName title of the movie to remove
 * @post movie is removed from the collection if it was found
 * 
 */
  void remove(std::string movieName);
};

#endif //LIBRARY_H
