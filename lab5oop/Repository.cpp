#include "Repository.h"

#include<iostream> // vad ca merge si fara asta
#include <exception>
#include <sstream>

using std::cin;
using std::cout;
using std::getline;
using std::exception;
/*
template<typename container_type>
Repository<container_type>::Repository(container_type lista) : list(lista)
{}
*/

//Repository::Repository(vector<Movie> lista): list(lista), len(lista.size()) // aici nu ii mai dau default parameter; doar in header !!
Repository::Repository(vector<Movie> lista): list(lista)// aici nu ii mai dau default parameter; doar in header !!
// initializer list
{} // parametru default la o lista de tipul `vector<Movie>` goala

vector<Movie>& Repository::getList() { return list; } // ar trebui sa returneze poitner ? sau referinta?

int Repository::exists(string id)
{
	int l = list.size();
	cout << "intra\n";
	for (int i = 0; i < l; i++)
	{
		cout << list.at(i) << '\n';
		cout << list.at(i).getID() << " " << "id = " <<  id << '\n';
		if (list.at(i).getID() == id) { cout << "gasit\n"; return i; } // sau Movie == Movie
	}
	return -1;
}

void Repository::add(Movie m)
{
	if (exists(m.getID()) == -1) list.push_back(m);
	else
	{
		// exception exista("Exista deja filmul"); // !!!!!!!!asa se arunca erorile!!!!!
		// exception exista;// asa se arunca erorile
		// throw exception exista("Exista deja filmul");
		// throw (exception exista("Exista deja filmul"));

		exception already_exists("The movie already exists");
		throw already_exists;
	}
}

void Repository::del(string id)
{
	int poz = exists(id);
	if (poz != -1) list.erase(list.begin() + poz);
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
		exception nu_exista;
		throw nu_exista;
	}
}


void Repository::toString()
{
//	string rez = "";
	/*
	for (int i = 0; i < l; i++)
	{
		rez += string(list[i]);
	}
	rez += '\n';
	*/
	//////////////////////////////////////////////////////////////////////////////////////////////////////de trecut in stream aici!!
	int l = list.size();
	for (int i = 0; i < l; i++)
		cout << i + 1 << ". " << list[i] << '\n'; // de lasat mereu fara '\n' in coada
	cout << '\n';
	//	return rez;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////


vector<Movie> Repository::generateUserGenreList(string genre)
{
	if (genre == "")
	{
		// return getList();
		return list; // sau direct sa afisez pe ecram si sa returnez
		// o lista goala ? cred, totusi, cu tarie ca toate afisarile
		// trebuie facute in User Interface !!
	}

	vector<Movie> preference_list;
//	cout << "gen:" << genre << '\n';
	int l = list.size();
	for (int i = 0; i < l; i++)
	{
		string token;
		std::stringstream stream;
		stream << list[i].getGenre(); // pun intr un stream, pentru: a sparge in token uri(vezi mai jos), folosind getline
//		cout << stream << '\n';
		// cout << "stream:" << list[i].getGenre() << '\n';
		while (getline(stream, token, ' ' )) // cred ca puteam lasa liber campul pentru separator;
		{
	//		cout << token << '\n';
		//	cin.get();
			if (token == genre)
			{
			//	cout << list[i] << '\n';
				// cout << "gasiiiiiiiiiiiiiiiiiiiiiittttttttttttttttt~!\n";
				preference_list.push_back(list[i]);
				break;
			}
				
		}
		/*
		if (list[i].getGenre() == genre)
			preference_list.push_back(list[i]);
		*/
	}
	return preference_list;
}

vector<string> Repository::giveLinksToAdmin()
{
	vector<string> aux;
	int l = list.size();
	for (int i = 0; i < l; i++)
		aux.push_back(list.at(i).getTrailer());
	//	auto aux = [](&aux){}
			// intre paranteze patrate ii dadeam ce sa prinda
	return aux;
}
