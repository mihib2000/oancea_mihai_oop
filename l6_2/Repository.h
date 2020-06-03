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
	 /* Citirea fisierului */
	 vector<Movie> readinput(string file = "Movies.txt");
	 /* Preluare input */
	 ifstream getinput(string file);
	 /* Procesare input */
	 vector<Movie> iterinput(ifstream file);
	 /* Procesarea unei linii */
	 void iterline(string, string&, string&, string&, int&, int&, string&);


public:
	
	/* Constructor */
	Repository(string file = "Movies.txt");

	vector<Movie>& getList();

	/* Returneaza lista id-urilor*/
	vector<string> getIds();

	/* Cauta filmul cu id-ul specificat si returneaza pozitia acestuia in cazul in care este gasit , in caz contrar returneaza -1*/
	int search(string id);

	/*Adauga un film in repo daca nu exista deja ,in caz contrar arunca exceptie*/
	void add(Movie);

	/*Sterge un film din repo in cazul in care acesta exista , in caz contrar arunca exceptie */
	void del(string);

	/*Editeaza detaliile unui anumit film*/
	void edit(string, Movie); 
	void toString();
	/* Returneaza lista filmelor cu genul specificat , in cazul in care nu se specifica genul v-a returna lista tuturor filmelor */
	vector<Movie> GenreList(string = "");
};