#pragma once
#include "Movie.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

// template<typename container_type>
// clasa singleton
class Repository
{
private:
	// int len; // nu cred ca are rost; o pot lua direct din `list.size()` chiar
	// daca implica un calcul; cred ca e relativ instant
	 vector<Movie> list;
	 
	 // int exists(string id);

//	 static Repository* getInstance();
	// Repository() {};

public:
	
	Repository(vector<Movie> = vector<Movie>() );
	
	int exists(string id);

	void add(Movie);

	void del(string);

	void edit(string, Movie); // se va inlocui primul film pasat(daca se gaseste
	// in lista, cu cel de-al doilea; altfel, se arunca exceptie

	// string toString();
	void toString();
	// de destructor cred ca se ocupa automat
	
	///////////////////////////////////////////////////////
	
	vector<Movie>& getList();

	vector<Movie> generateUserGenreList(string = ""); // vad ca pot sa nu ii specific numele aici

	vector<string> giveLinksToAdmin();

// 	void show_movie(string )

};