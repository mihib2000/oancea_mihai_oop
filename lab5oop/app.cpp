/*
	NOTA: pentru deschiderea link urilor in browser am folosit o varianta
	care nu stiu daca e cross-platform, dar pe windows mergea! Nu stiu sigur 
	pe MacOS sau alte sisteme de operare
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <vector>
// #include <exception>

#include "Movie.h"
#include "Repository.h"
#include "Controller.h"
#include "UI.h"

using std::cin;
using std::cout;
using std::ifstream;
using std::getline;


using std::string;
using std::vector;

/*
	reads a file & returns a stream with the contents of a file
*/
/*
ifstream get_input(string file)
{
	string mat;
	ifstream input_stream;
	while (true)
	{
		try
		{
			input_stream.open(file);
			return input_stream;
		}
		catch (...)
		{
			asl_get("file", file);
		}
	}
}
*/

/*
	Parse one line (pertaining to our database); turn read contents into meaningful variables.
*/
void parse_line(string line, string& id, string& title, string& genre, int& year, int& likes, string& trailer)
{
	std::stringstream stream; // creez un stream
	stream << line;		// pun in stream linia curent obtinuta

	string token;
	getline(stream, token, ',');
	//std::stringstream aux(token);	// convertesc la int
	//aux >> id;
	id = token; // nu am niciun spatiu de eliminat aici

	getline(stream, token, ',');
	token = token.substr(1); // elimin space ul de la inceputul string ului
	title = token;
	getline(stream, token, ',');
	token = token.substr(1); // elimin space ul de la inceputul string ului
	genre = token;

	getline(stream, token, ',');
	token = token.substr(1);	// elimin space ul de la inceputul string ului
	std::stringstream aux2(token);	// convertesc la int
	aux2 >> year;

	getline(stream, token, ',');	// convertesc la int
	token = token.substr(1);	// elimin space ul de la inceputul string ului
	std::stringstream aux3(token);
	aux3 >> likes;

	getline(stream, token, ',');
	token = token.substr(1);
	trailer = token;
}
/*
	Parse the contents read from the file (pertaining to our database)
*/
vector<Movie>parse_input(ifstream file)
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
/*
	read & parse & return movie database
*/
/*
vector<Movie> create_list(string file)
{
	return parse_input(get_input(file));
}
*/
/*
	Create the layers of the app.
*/
void start()
{
	//vector<Movie> lista = create_list("Movies.txt");	
	//Repository repo = Repository(lista);

	Repository repo("Movies.txt");
	Controller ctrl(repo);
	UI ui(ctrl);

	ui.run();
}

int main()
{	
	// start();
	
	
	/*
	string s1 = "ab";
	string s2 = "abc";
	if (s1 < s2) cout << "da\n";
	if (s2 < s1) cout << "s2 mai mare\n";
	*/
	
	/*
	ifstream file;
	if(file.open()) cout << "returneaza true pt ca s a deschis fisierul\n";
	*/

	start();

	return 0;
}