#include "Repository.h"

#include<iostream> // vad ca merge si fara asta
#include<fstream> // vad ca merge si fara asta
#include <exception>
#include <sstream>


using std::cin;
using std::cout;
using std::ifstream;
using std::getline;
using std::exception;


Repository::Repository(string file)
{
	list = readinput(file);
}


ifstream Repository::getinput(string file)
{
	ifstream input;
	input.open(file);
	return input;
}

vector<string> Repository::getIds()
{
	vector<string> aux;
	int length = list.size(),i;
	for (i = 0; i < length; i++)
		aux.push_back(list[i].getID());
	return aux;
}

void Repository::iterline(string line, string& id, string& title, string& genre, int& year, int& likes, string& trailer)
{

	std::stringstream stream; // creez un stream
	stream << line;		// linia curenta

	string entity;
	getline(stream, entity, ',');
	id = entity; 
	getline(stream, entity, ',');
	title = entity;
	getline(stream, entity, ',');
	genre = entity;
	getline(stream, entity, ',');
	std::stringstream a1(entity);	
	a1 >> year;		// convertesc la int		
	getline(stream, entity, ',');	
	std::stringstream a2(entity);	
	a2 >> likes;		// convertesc la int
	getline(stream, entity, ',');
	trailer = entity;
}

vector<Movie> Repository::iterinput(ifstream file)
{
	string id;
	string title;
	string genre;
	int year;
	int likes;
	string trailer;

	vector<Movie> lista;

	string line;
	while (getline(file, line))
	{
		iterline(line, id, title, genre, year, likes, trailer);
		lista.push_back(Movie(id, title, genre, int(year), int(likes), trailer));
	}
	return lista;
}

vector<Movie> Repository::readinput(string file)
{
	return iterinput(getinput(file));
}

int Repository::search(string id)
{
	int length = list.size();
	for (int i = 0; i < length; i++)
	{
		if (list[i].getID() == id) return i;
	}
	return -1;
}

void Repository::add(Movie m)
{
	if (search(m.getID()) != -1)
	{
		exception e("Filmul exista deja");
		throw e;}
	else
	{
		list.push_back(m);}
}

void Repository::del(string id)
{
	int i = search(id);
	if (i == -1)  
	{
		exception e("Filmul nu exista");
		throw e;}
	else{

		list.erase(list.begin() + i);
	}
}


void Repository::edit(string id, Movie m)
{
	int i = search(id);
	if (i == -1) {
		exception e("Filmul nu exista");
		throw e;}
	else {
		list[i] = m;
	}
}


void Repository::toString()
{
	int length = list.size(),i;
	for (i = 0; i < length; i++)
		cout << i + 1 << ". " << list[i] << '\n';
	cout << '\n';
}

vector<Movie> Repository:: GenreList(string genre)
{
	if (genre == "") return list; 

	vector<Movie> aux;
	int length = list.size();
	for (int i = 0; i < length; i++)
	{
		string entity;
		std::stringstream stream;
		stream << list[i].getGenre(); 
		while (getline(stream, entity, ' ' ))
		{
			if (entity == genre)
			{
				aux.push_back(list[i]);
				break;
			}				
		}
	}
	return aux;
}

vector<Movie>& Repository::getList() { 
	return list; 
}