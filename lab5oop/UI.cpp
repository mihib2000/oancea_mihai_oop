/*
template<typename tip_controller>
tip_controller UI<tip_controller>::getController() { return controller; }
*/

#include <iostream>
#include <exception>
#include <windows.h>
// #include <curl/curl.h>

#include "UI.h"

using std::cin;
using std::cout;
using std::cerr;
using std::exception;

/*
UI::UI(Controller c)
{
	contr = c;
}
*/

// returnez o referinta la atributul contr
/*
Controller& UI::getController()
{
	return contr; // nu mai trebuie aici semnul de referinta! contr ESTE o adresa;
	// ca si cum ai scrie int x = 5;  x este o adresa, dar se dereferentiaza automat !
	// at least, I suppose
}
*/

/////////////////////////////////////////////////////////////////////////

/*
// de revenit aici !!
void UI::start(void (func*)() )
{
	menu();
}
*/
#include "Controller.h"

UI::UI(Controller c)
{
	contr = c;
}

Controller& UI::getController()
{
	return contr;
}


/*
void UI::start()
{

	int mode;
	select_mode(mode);
	switch (mode)
	{
	case 1:
		user_mm();
		break;
	case 2:

		break;
	}
	
}
*/


/*
//void UI::select_mode(int &mode)
//template<typename T>
// am incercat aici ceva cu template uri dar nu a mers
*/


///// DE INCERCAT TEMPLATE URI AICI DE INCERCAT TEMPLATE URI AICI DE INCERCAT TEMPLATE URI AICI 
/*
void UI::get_input(string mesaj, int& value) // woww; aparent merge asa !!
// cu template uri trebuia 
{
	cout << mesaj << " = "; cin >> value; cin.get(); // citesc si '\n' ul ramas in buffer
}
*/

/**/
void UI::get_input(string mesaj, string &value)
{
	cout << mesaj << " = "; getline(cin, value);
}
///// DE INCERCAT TEMPLATE URI AICI DE INCERCAT TEMPLATE URI AICI DE INCERCAT TEMPLATE URI AICI 
///// DE INCERCAT TEMPLATE URI AICI DE INCERCAT TEMPLATE URI AICI DE INCERCAT TEMPLATE URI AICI 
void UI::get_option(int& option)
{
	// validator v;
	cout << "Enter option: ";
	cin >> option;
	cin.get(); // citesc '\n' ul ramas in buffer !!
	cout << '\n';
	
}

void UI::get_option(char& option) 
{
	cout << "Enter option: ";
	cin >> option;
	cin.get(); // citesc '\n' ul ramas in buffer !!
	cout << '\n';
}
// DE INCERCAT TEMPLATE URI AICI DE INCERCAT TEMPLATE URI AICI DE INCERCAT TEMPLATE URI AICI 

void UI::wrong_input_msg()
{
//	cout << "!! Va rugam introduceti un numar de ordine corespunzator valorilor afisate !!";
	cout << "Please enter one of the numbers corresponding to the options!!\n";
}

void generic_error_msg(exception& e)
{
	cerr << "===EROARE===\n";	// cerr scrie intr un stream separat de cout
	cerr << e.what() << '\n';
	cerr << "===============\n";
	cout << '\n';
}

void UI::main_menu(int &mode, vector<Movie> &own_list)
{
	switch (mode)
	{
//	case 0:
	//{
		
	//}
	case 1: 
		admin_mm(); // trebuie sa folosesc this aici ? dc?
		// this->admin_mm(); // trebuie sa folosesc this aici ? dc?
		// doar am folosit deja obiectul `ui` in l5_4 cand am pornit
		//cout << "se revine pe aici\n";
		// aplicatia
		break;
	case 2:
		user_mm(own_list);
		break;

	default:
		// std::runtime_error eroare("EROARE\n");
		exception e;
		throw e;
	}
}

void UI::select_mode()
{
	cout << "Select mode:\n"
		<< "1.Administrator\n"
		<< "2.User\n";
		//<< "0. Exit\n";
	
}

void UI::start()
{
	int mode;
	select_mode();
	get_option(mode);
	vector<Movie> user_list;
	while (true)
	{
		try
		{
			main_menu(mode, user_list);
		}
		catch (exception &e) // 
		{
			// cout << eroare << '\n';
			// cout << e << '\n';
			wrong_input_msg();
			get_option(mode);
		}
		/*
		catch ()
		{

		}
		*/
	}
}



void UI::get_movie_attributes(string &id, string &title, string &genre, int &year, int &likes, string &trailer)				//DECOMENTEAZAAAAAAAAAAAAAA
{
/*
	try
	{
		cout << " id = "; cin.get();  getline(cin, id); // cin.get() e ca sa citesc endline ul; sa nu raman in buffer
	}
	except(exista)
	{

	}
*/
	cout << " id = "; // cin.get(); // citesc ultimul caracter '\n' ramas in buffer
	getline(cin, id); // cin.get() e ca sa citesc endline ul; sa nu raman in buffer
	cout << id << '\n';
	//cout << " title = "; getline(cin, title, ','); // Atentie!! a nu se citi titluri ce contin virgule
	cout << " title = ";  getline(cin, title); // Atentie!! a nu se citi titluri ce contin virgule
	cout << title << '\n';
	cout << " genre = "; getline(cin, genre); //cin.getline(genre); // de data aceasta voi folosi getline
	// sa citesc din `cin` care e un obiect de tip ``; la fel de bine puteam face:
	// `cin.getline(genre);` aparent, getline e o metoda a unui obiect de acest tip `` 
	// GRESIT!! sunt total diferite; `getline()` e o functie din `std::` pe cand 
	// `cin.getline()` se ocupa de C-style strings, adica array de caractere!!
	cout << genre << '\n';
	cout << " year = "; cin >> year;
	cout << year << '\n';
	cout << " likes = "; cin >> likes;
	cout << likes << '\n';
	cout << " trailer = "; cin.get(); // cin-ul de mai sus citeste pana la caracterul '\n'
	// asa ca '\n' ramane in buffer; fac `cin.get()` ca sa citesc caracterul '\n' ramas
	// in buffer, nu in variabila `trailer`; apoi citesc in `trailer` ce ma intereseaza
	getline(cin, trailer);
	cout << trailer << '\n';
}


void UI::execute_amm(int option) // execute admin main menu ; //DECOMENTEAZAAAAAAAAAAAAAA
{
	string id, title, genre, trailer;
	int year, likes;
	switch (option)
	{
		case 1:
		{
			// array de pointeri void ca sa iau input de la utilizator
			get_movie_attributes(id, title, genre, year, likes, trailer);
			try { contr.getRepo().add(Movie(id, title, genre, year, likes, trailer)); }
			catch (exception & e)
			{
				// cout << e.what();
				generic_error_msg(e);
			}
			break;
		}
		//break; // il puteam pune si aici; nu conteaza
		case 2:
		{
			string old_id;
			cout << "id (of movie to be updated) = "; cin >> old_id;
			get_movie_attributes(id, title, genre, year, likes, trailer);
			try
			{
				contr.getRepo().edit(old_id, Movie(id, title, genre, year, likes, trailer));
			}
			catch(exception &e)
			{
				generic_error_msg(e);
			}
			break;
		}
		case 3:
		{
			string old_id; 
			cout << "id (of movie to be deleted) = ";  cin >> old_id;
			// cout << "old_id = " << old_id << '\n';
			try
			{
				contr.getRepo().del(old_id); // grija la prostii de genul: era `id` in loc de `old_id`
			}
			//catch(exception nu_exista)
			catch (exception &e) // e bine de prins exceptiile aici prin referinta
			{
				generic_error_msg(e);
			}
			break;
		}
		case 4:
		{
			contr.getRepo().toString();
		}
		case 0:
		{
			exception leave;
			throw leave;
		}
		default:
			wrong_input_msg();
	}
}

	
// void UI::afis_lista(const vector<Movie>& aux)
void UI::afis_lista(vector<Movie>& aux)
{
	int l = aux.size();
	// cout << "nr de filme din lista este: "<< l << '\n';
	for (int i = 0; i < l; i++)
		cout << aux[i] << '\n';
	cout << '\n';
}

void one_by_one(vector<Movie> aux, vector<Movie> &watchlist)
{
	int i = 0;
//	vector<Movie> watchlist;
//	int dim_watchlist = 0;
	char yne; // yes / no / exit 
	string mesaj = "\"y\" = yes  \"n \" = no \"e\" = exit";
	//string auxg(1, '"');
	// cout << "lungimea listei = " << l << '\n';
	int l = aux.size();
	while (i < l)
	{
		// deschide link film in browser !
		cout << aux[i] << '\n';
		cout << "---Check trailer open in Internet browser!---\n";
		string aux1 = '"' + aux[i].getTrailer() + '"';
		cout << aux1 << '\n';
		ShellExecute(NULL, "open",
			// asta e comentariu: "http://dreamincode.net",
			//auxg + aux[i].getTrailer() + auxg,
			//aux1,
// asta e comentariu ::			"http://dreamincode.net",
			aux1.c_str(),	// convertesc la `const char*` (wlstr)
			NULL, NULL, SW_SHOWNORMAL);

		// i++; // asta nu avea ce cauta aici !!!

		
		cout << (" Do you like it? Would you like to add it to your watch list ?\n");
		//Wget_input(mesaj, yne);
		cout << mesaj << '\n';
		cin >> yne;
		
		switch(yne)
		{
		case 'y':
		{
			// cout << "i = "<< i << '\n';
			watchlist.push_back(aux[i]); 
			break;
		}

		case 'n':
			break;
		case 'e':
	//		return watchlist;
			return ;
		}
		i++;		// atentie boss !!!
	}
//	return watchlist;
}

//DECOMENTEAZAAAAAAAAAAAAAA
// void UI::execute_umm(int option, vector<Movie> aux)
void UI::execute_umm(int option, vector<Movie>& own_list)
{
	switch (option)
	{
	//	case 0:
		//	return;
		case 1:
		{
		
			string genre;
			get_input("genre", genre);
			vector<Movie> aux = contr.getRepo().generateUserGenreList(genre);
		
			int l = aux.size();
			//cout << "genre = " << genre << '\n';
			//cout << ";atat cat e pana aici \n";
			//if(genre == "")
		
	//		if(genre == )
		
			//afis_lista(aux);
			//break;
		
			one_by_one(aux, own_list);
			//////cout << "iese\n";
			/////cout << "Your movie list is:\n";
			// afis_lista(watchlist);
			cout << "Your current watchlist is:\n";
			afis_lista(own_list);
			break;
		}
		case 2:
		{
			string id;
			if (!own_list.size()) { cout << "You have not chosen any movie yet!\n"; return; }

			get_input("id", id);
			try
			{
				contr.getRepo().del(id);
				
				/*
				// get_input("Did you like the movie?\n");
				char c;
				string mesaj = "\"y\" = yes  \"n \" = no \"e\" = exit";
				//get_input();
				*/
				char c;
				get_option(c);
				switch (c)
				{
				case 'y': 
				{
					int poz = contr.getRepo().exists(id);
					vector<Movie> aux = contr.getRepo().getList(); // asta e chiar baza mea de date, pentru ca metoda returneaza referinta ! nu e o copie!
					int nr_likes = aux.at(poz).getLikes();
					// aux.at(poz).setLikes(nr_likes++);
					aux.at(poz).setLikes(++ nr_likes);
				}
				case 'n': break;
				}
			}
			catch (exception &e)
			{
				cerr << e.what();
				cout << "(Maybe check id ?)\n";
			}
				/*
						try
						{
							string id;
							get_input("id", id);

						}
						catch (exception e&)
						{
							cerr << e.what() << '\n';
						}
				//		if (!own_list.size()) {    generic_error_msg()  }
				*/
			break;
		}
		case 3:
		{
			if (!own_list.size()) { cout << "You have not chosen any movie yet!\n"; return; }
			afis_lista(own_list);
			break;
		}
		default:
		{
			wrong_input_msg();
			break;

		}
	}
}

void UI::admin_mm()
{
	cout << "===ADMIN MAIN MENU===\n";
	cout << "0. Go back'\n'"
		<< "1. Add movie\n"
		<< "2. Update Movie\n"
		<< "3. Delete movie\n"
		<< "4. Display movies\n\n";
	
	int option;
	get_option(option);
	try
	{
		execute_amm(option); // de vazut de facut cu asta duplicata in user_mm()
	}
	catch(exception &e)
	{
		start();
	}
}

void UI::user_mm(vector<Movie> &own_list)
{
	cout << "===USER MAIN MENU===\n"
		<< "1. View movies by specified genre(leave blank to view all movie trailers)\n"
		<< "2. Delete movie from own watchlist\n"
		<< "3. Display own list\n";
	cout << '\n';
	int option;
	get_option(option);
	execute_umm(option, own_list);
//	cout << "aici::::::::::" << own_list.size() << '\n';
}















/*
void UI::follow_comand(int command)
{
	switch (command)
	{
	case 0:
		return;

	case 1:
		switch (command)
		{

		}
	case 2:
		switch ()
		{

		}

	}

}
*/

