#pragma once
#include "Movie.h"
#include <vector>
#include <string>
#include <fstream>

using std::vector;
using std::string;
using std::ifstream;

class Repository
{
private:
	 vector<Movie> list;
	 
	 /* Method to read to open the file & read its contents */
	 ifstream get_input(string file);

	 /* Method that interprets the read input */
	 vector<Movie> parse_input(ifstream file);

	 /* Method that interprets a string (pertaining to our database) */
	 void parse_line(string, string&, string&, string&, int&, int&, string&);

	 /* Method that reads */
	 vector<Movie> read_database(string file = "Movies.txt");

	 static void del_watchlist(string); 
	 /*
		 am implementat o statica pentru ca va
		 folosita atat de obiecte ale clasei, cat si pentru a sterge
		 din watchlist ul temporar al user ului
	 */

public:
	
	/* Constructor */
	Repository(string file = "Movies.txt");

	/* Returns a list with all the movies' ids*/
	vector<string> getIds();

	/* Checks if there is a movie with the id equal to `id`.
		Returns the position, if it does; returns -1 otherwise.
	*/
	int exists(string id);

	/*
		Adds movie to the repository, if it is not already in the virtual database.
	*/
	void add(Movie);

	/*
		Deletes movie from the repository, if it exists in the virtual database.
	*/
	void del(string);

	/*
		Changes the attributes of the movie with id equal to `id`, if it exists in the virtual database/
	*/
	void edit(string, Movie); 

	/*
		Prints the movies in the repository.
	*/
	void toString();
	
	/* Getter atribut `list` */
	vector<Movie>& getList();

	/* Returns a list with all the movies that have the specified genre */
	vector<Movie> generateUserGenreList(string = "");
};