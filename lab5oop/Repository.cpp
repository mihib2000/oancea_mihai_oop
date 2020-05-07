#include<iostream> // vad ca merge si fara asta
#include<fstream> // vad ca merge si fara asta
#include <exception>
#include <sstream>

#include "Repository.h"

using std::cin;
using std::cout;
using std::getline;
using std::ifstream;
using std::exception;

Repository::Repository(string database_file, string watchlist_file) :
	list(read_database(database_file)), user_watchlist(read_database(watchlist_file))
{}

vector<Movie>& Repository::getList() { return list; }

vector<Movie>& Repository::getUserWatchlist() { return user_watchlist; }

ifstream Repository::get_input(string file)
{
	ifstream input_stream;
	input_stream.open(file); // va arunca oricum exceptie aici daca nu exista fisierul, iar o exceptie netratata
	// ( uncaught ) va opri executia programului
	return input_stream;
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
	if (file == "") return vector<Movie>();
	return parse_input(get_input(file));
}

vector<string> Repository::getIds()
{
	vector<string> aux;
	int l = list.size();
	for (int i = 0; i < l; i++)
		aux.push_back(list[i].getID());
	return aux;
}

/*
vector<Movie> & Repository::get_ref(const int &option)
{
	switch (option)
	{
	case 1:
		return list;
	case 2:
		return user_watchlist;
	}
}
*/

int Repository::exists(const vector<Movie>& list, const string& id) // database or watchlist
{
	int l = list.size();
	for (int i = 0; i < l; i++)
		if (list.at(i).getID() == id)  return i;

	return -1;
}

void Repository::add(vector<Movie>& list, const Movie& m)
{
	if (exists(list, m.getID()) == -1) list.push_back(m);
	else
	{
		exception already_exists("The movie already exists in the respective list!");
		throw already_exists;
	}
}

void Repository::del(vector<Movie>& list, const string& id) // cred ca oricum vine prin refereinta
{
	int poz = exists(list, id);
	if (poz != -1) list.erase(list.begin() + poz);
	else
	{
		exception not_here("The movie does not exist in the respective list!");
		throw not_here;
	}
}

void Repository::edit(vector<Movie>& list, const string& id, const Movie& new_movie)
{
	int poz = exists(list, id);
	if (poz != -1)
		list[poz] = new_movie;
	else
	{
		exception nu_exista("The movie does not exist in the respective list!");
		throw nu_exista;
	}
}

vector<Movie> Repository::generateUserWatchlist(const string& genre)
{
	if (genre == "") return list;

	vector<Movie> preference_list;
	int l = list.size();
	for (int i = 0; i < l; i++)
	{
		string token;
		std::stringstream stream;
		stream << list[i].getGenre();
		while (getline(stream, token, ' '))
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

ostream& operator<<(ostream& os, const vector<Movie>& list)
{
	int l = list.size();
	for (int i = 0; i < l; i++)
		os << i + 1 << ". " << list[i] << '\n';
	return os;
}