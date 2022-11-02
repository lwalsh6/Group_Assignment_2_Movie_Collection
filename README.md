# Group-Assignment-2-Movie-Collection
Names: Logan Walsh, Zachary Rose  
Date: 10/28/2022

This is a program that organizes a list of movies into a sorted list and allows the user to search, add, and remove movies from the list, as well as read from and print to a file.

## Required Files
* movies.txt --> Sample list of movies, some are good and some are complete trash
* main.cpp --> The main driver, used to call the functions in library.cpp
* library.cpp --> The file containing the implementation of the movie collection
* library.h --> The header file containing all the function prototypes for the movie collection
* Movie.h --> Contains the Movie struct, a POD containing info for a single movie
* Makefile --> Used to compile all of the files
* README.md --> A mythical file that is speculated to explain what a program is for

## Compilation instructions

Type "make" to compile the program. 

## Program usage.

To launch the program, type "./library" You will then be prompted with a menu that will allow you to perform 8 different functions. Input a number 1-8 and follow instructions, or enter h to print the instructions again. If using an input text file, it should be in the same folder as the executable. 

## Design Decisions

* Both search functions allow the user to search a substring (a part of the title)
* Helper function in main.cpp cleans up main() and makes reprinting the instructions easy

## Challenges 

* Learning to switch from a user-made linked list to the one that's pre-programmed in C++ was a bit confusing. 
* Using iterator logic not only to move through the data structure but as parameters to methods.

## Work Distribution

* Design decisions and iterator logic were discussed over Discord
* We each did approximately half of the functions and the documentation while discussing implementation 
