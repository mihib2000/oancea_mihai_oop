#pragma once
#include "Movie.h"
#include <vector>
#include <string>
#include <fstream>

using std::vector;
using std::string;
using std::ifstream;

// template<typename container_type>
// clasa singleton
class Repository
{
private:
	// int len; // nu cred ca are rost; o pot lua direct din `list.size()` chiar
	// daca implica un calcul; cred ca e relativ instant
	 vector<Movie> list;
	 
	 ifstream get_input(string file);
	 void parse_line(string, string&, string&, string&, int&, int&, string&);
	 vector<Movie> parse_input(ifstream file);
	vector<Movie> read_database(string file = "Movies.txt");
	 // vector<Movie> read_database();
	 	 
	 // int exists(string id); // de asta am nevoie !



//	 static Repository* getInstance();
	// Repository() {};



public:
	
	//Repository(vector<Movie> lista = vector<Movie>() );
	
//	Repository(vector<Movie> lista = read_database() );
	
	Repository(string file = "Movies.txt");

	vector<string> getIds();

//	vector<Movie> read_database(string file = "Movies.txt");

	int exists(string id);

	void add(Movie);

	void del(string);

	void edit(string, Movie); // se va inlocui primul film pasat(daca se gaseste
	// in lista, cu cel de-al doilea; altfel, se arunca exceptie

	// string toString();
	void toString();
	// de destructor cred ca se ocupa automat
	
	vector<Movie>& getList();

	vector<Movie> generateUserGenreList(string = ""); // vad ca pot sa nu ii specific numele aici
};