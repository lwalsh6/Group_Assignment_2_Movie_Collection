# Logan Walsh/Zachary Rose
# 10-27-2022
# Makefile
# Makefile Test Program for compiling the Linked List Phonebook
# Typing "make" compiles the program

# Variables are defined for the compiler and compiler flag
# These variables can be used with $()

CC = g++
CFLAGS = -g -Wall -Wextra

# Set to compile when "Make" is called
# Set to be the default entry

default: library

# List the object files needed to create the executable file.
# Compile with all errors and warnings
library:		library.o main.o
			$(CC) $(CFlags) -o library library.o main.o

# A list of object files needed to create the executable file.
library.o:		library.cpp library.h Movie.h
# Compile stacker.o with all errors and warnings
		$(CC) $(CFLAGS) -c library.cpp

main.o:		main.cpp library.h
# Compile main.o with all errors and warnings
		$(CC) $(CFLAGS) -c main.cpp

#This names the "executable" for the program. After compiling type ./library
clean:
	$(RM) library *.o *~
