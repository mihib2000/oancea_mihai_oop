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
	vector<Movie> user_watchlist;

	/* Method to read to open the file & read its contents */
	ifstream get_input(string file);

	/* Method that interprets the read input */
	vector<Movie> parse_input(ifstream file);

	/* Method that interprets a string (pertaining to our database) */
	void parse_line(string line, string&, string&, string&, int&, int&, string&); // linia de interpretat urmata de atributele specifice unui film

	/* Method that reads */
	vector<Movie> read_database(string file = "Movies.txt");

public:

	/* Constructor */
	Repository(string database_file = "Movies.txt", string watchlist_file = "");

	/* Getter atribut `list` */
	vector<Movie>& getList();

	/* Getter atribut `user_watchlist` */
	vector<Movie>& getUserWatchlist();

	/* Returns a list with all the movies' ids*/
	vector<string> getIds();

	/* Checks if there is a movie with the id equal to `id` in the virtual database
	OR in user's watch list (according to the reference passed to it in the `lista` parameter).
		Returns the position, if the movie exists; returns -1 otherwise.
	*/
	int exists(const vector<Movie>& lista, const string& id);

	/*
		Adds movie to the repository, if it is not already in the virtual database.
	*/
	void add(vector<Movie>& lista, const Movie& m);

	/*
		Deletes movie from the movie virtualdatabase, if it exists in the virtual database.
		-or-
		Deletes movie from user's watchlist, if it exists in the user_watch_list
	*/
	void del(vector<Movie>& lista, const string& id);

	/*
		Changes the attributes of the movie with id equal to `id`, if it exists in the virtual database/
	*/
	void edit(vector<Movie>& lista, const string& id, const Movie& new_movie);

	/* Returns a list with all the movies that have the specified genre */
	vector<Movie> generateUserWatchlist(const string & = "");

	/* Returns a reference to the first or the second attribute of the class, based on the `option` variable */
//	vector<Movie>& get_ref(const int& option = 1); // reference to a pointer !! adica pointer pasat prin referinta
};
ostream& operator<<(ostream& os, const vector<Movie>& list);