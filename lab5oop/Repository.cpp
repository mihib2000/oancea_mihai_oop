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


Repository::Repository(string file) : list(read_database(file))
{}


ifstream Repository::get_input(string file)
{
	string mat;
	ifstream input_stream;
	input_stream.open(file);
	return input_stream;
}

vector<string> Repository::getIds()
{
	vector<string> aux;
	int l = list.size();
	for (int i = 0; i < l; i++)
		aux.push_back(list[i].getID());
	return aux;
}

void Repository::parse_line(string line, string& id, string& title, string& genre, int& year, int& likes, string& trailer)
{
	std::stringstream stream; // creez un stream
	stream << line;		// pun in stream linia curent obtinuta

	string token;
	getline(stream, token, ',');
	id = token; // nu am niciun spatiu de eliminat aici

	getline(stream, token, ',');
	token = token.substr(1); // elimin space ul de la inceputul string ului
	title = token;
	getline(stream, token, ',');
	token = token.substr(1); // elimin space ul de la inceputul string ului
	genre = token;

	getline(stream, token, ',');
	token = token.substr(1);	// elimin space ul de la inceputul string ului
	std::stringstream aux2(token);	// convertesc un string
	aux2 >> year;					// la un int 

	getline(stream, token, ',');	// convertesc la int
	token = token.substr(1);	// elimin space ul de la inceputul string ului
	std::stringstream aux3(token);	// convertesc un string
	aux3 >> likes;					// la un int

	getline(stream, token, ',');
	token = token.substr(1);
	trailer = token;
}

vector<Movie> Repository::parse_input(ifstream file)
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
		parse_line(line, id, title, genre, year, likes, trailer);
		lista.push_back(Movie(id, title, genre, int(year), int(likes), trailer));
	}

	return lista;
}

vector<Movie> Repository::read_database(string file)
{
	return parse_input(get_input(file));
}

int Repository::exists(string id)
{
	int l = list.size();
	for (int i = 0; i < l; i++)
	{
		if (list.at(i).getID() == id)  return i; // sau Movie == Movie
	}
	return -1;
}

void Repository::add(Movie m)
{
	if (exists(m.getID()) == -1) list.push_back(m);
	else
	{
		exception already_exists("The movie already exists");
		throw already_exists;
	}
}

void Repository::del(string id) // cred ca oricum vine prin refereinta
{
	int poz = exists(id);
	if (poz != -1) { list.erase(list.begin() + poz); cout << " l a sters\n";} 
	else
	{
		exception not_here("The movie does not exist!");
		throw not_here;

	}
}


void Repository::edit(string old_id, Movie new_m)
{
	int poz = exists(old_id);
	if (poz != -1) { list.at(poz) == new_m; }
	else
	{
		exception nu_exista("The movie does not exist!");
		throw nu_exista;
	}
}


void Repository::toString()
{
	int l = list.size();
	for (int i = 0; i < l; i++)
		cout << i + 1 << ". " << list[i] << '\n';
	cout << '\n';
}

vector<Movie> Repository::generateUserGenreList(string genre)
{
	if (genre == "") return list; 

	vector<Movie> preference_list;
	int l = list.size();
	for (int i = 0; i < l; i++)
	{
		string token;
		std::stringstream stream;
		stream << list[i].getGenre(); 
		while (getline(stream, token, ' ' ))
		{
			if (token == genre)
			{
				preference_list.push_back(list[i]);
				break;
			}				
		}
	}
	return preference_list;
}

vector<Movie>& Repository::getList() { return list; }