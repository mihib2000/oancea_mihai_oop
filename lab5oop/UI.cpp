#include <iostream>
#include <exception>
#include <windows.h>

#include "UI.h"

using std::cin;
using std::cout;
using std::cerr;
using std::exception;

UI::UI(Controller c)
{
	contr = c;
}

Controller& UI::getController()
{
	return contr;
}


void UI::ask_get(string mesaj, int& value)
{
	cout << '\n';
	cout << mesaj << ": ";
	cin >> value; cin.get();  // citesc 1 caracter ca sa nu ramana "trailing" in buffer si sa ma incurce la alte eventuale citiri cu `cin`
}

void UI::ask_get(string mesaj, char& value)
{
	cout << '\n';
	cout << mesaj << ": ";
	cin >> value; cin.get(); // citesc caracterul ca sa nu ramana "trailing" in buffer si sa ma incurce la alte eventuale citiri cu `cin`
}

void UI::ask_get(string mesaj, string& value)
{
	cout << '\n';
	cout << mesaj << ": ";
	getline(cin, value);

}

void UI::run()
{
	int mode;
	vector<Movie> user_watchlist;

	while (true)
	{
		select_mode_screen();
		ask_get("mode", mode);
		switch (mode)
		{
		case 1:
		{
			execute_amo();
			break;
		}
		case 2:
		{
			execute_umo();
			break;
		}
		case 0:
		{
			cout << "Exiting...\n See you soon!";
			return;
		}
		default: { wrong_option_screen(); break; }
		}
	}
}


void UI::ask_get_ma(string& id, string& title, string& genre, int& year, int& likes, string& trailer)
{
	ask_get("id", id);
	id_validation_screen(id);
	cout << '\n';
	ask_get("title", title);
	ask_get("genre", genre);
	ask_get("year", year);
	year_validation_screen(year);
	cout << '\n';
	ask_get("likes", likes);
	cout << '\n';
	likes_validation_screen(likes);
	ask_get("trailer", trailer);
}

void UI::invalid_screen(const string& token, const string& low_boundary, const string& high_boundary, const int& option)
{
	string aux;
	switch (option)
	{
	case 1:
		aux = "NOT BE";
		break;
	case 2:
		aux = "BE";
	}
	cout << "Invalid value for "
		<< token.c_str() << "! Must " << aux.c_str() << " between: "
		<< low_boundary << " and " << high_boundary << '\n';
}

void UI::invalid_screen(const string& token, const int& low_boundary, const int& high_boundary)
{
	cout << "Invalid value for "
		<< token.c_str() << "! MUST be between: "
		<< low_boundary << " and " << high_boundary << '\n';
}

void UI::invalid_screen(const string& token, const int& low_boundary)
{
	cout << "Invalid value for "
		<< token.c_str() << "! MUST be higher than: "
		<< low_boundary << '\n';
}

void UI::invalid_screen(const string& token)
{
	cout << "Invalid value for "
		<< token.c_str();
}

//void UI::id_validation_screen(string& id, const int& option, const string& old_id)
void UI::id_validation_screen(string& id, const int& option)
{
	cout << "checking integrity of id\n";
	//	if (id == old_id) { cout << "`id` attribute is valid!\n";  return; }

	vector<string> ids_list = contr.getRepo().getIds();
	int l = ids_list.size();

	bool changed = false;
	switch (option)
	{
	case 1:
	{
		while (validator.id_exists(id, ids_list))
		{
			changed = true;
			invalid_screen("id", ids_list[0], ids_list[l - 1]);
			cout << "Re-enter!\n";
			ask_get("id", id);
		}
		break;
	}																				///////////////////////////////////////////////////////////////////////////////////////////////////////
	case 2:
	{
		while (validator.id_does_not_exist(id, ids_list))
		{
			changed = true;
			invalid_screen("id", ids_list[0], ids_list[l - 1], 2);
			cout << "Re-enter!\n";
			ask_get("id", id);
		}
	}
	}
	if (changed) cout << "`id` attribute has been validated!";
	else cout << "`id` attribute is valid!\n";
}

void UI::year_validation_screen(int& year)
{
	cout << "checking integrity of year\n";
	vector<string> ids_list = contr.getRepo().getIds();
	int l = ids_list.size();
	bool changed = false;
	while (!validator.validate_year(year))
	{
		changed = true;
		invalid_screen("year", validator.lowest_year, validator.highest_year);
		cout << "Re-enter!\n";
		ask_get("year", year);
	}
	if (changed) cout << "`year` attribute has been validated!";
	else cout << "`year` attribute is valid!\n";
}

void UI::likes_validation_screen(int& likes)
{
	cout << "checking integrity of likes\n";
	vector<string> ids_list = contr.getRepo().getIds();
	int l = ids_list.size();

	bool changed = false;
	while (!validator.validate_likes(likes))
	{
		changed = true;
		invalid_screen("likes", validator.lowest_likes);
		cout << "Re-enter!\n";
		ask_get("likes", likes);
	}
	if (changed) cout << "`likes` attribute has been validated!";
	else cout << "`likes` attribute is valid!\n";
}


void UI::execute_amo()
{
	vector<Movie>& list = contr.getRepo().getList();

	string id, title, genre, trailer;
	int year, likes;
	int option;


	while (true)
	{
		admin_menu_screen();
		ask_get("option", option);
		switch (option)
		{
		case 1:
		{
			ask_get_ma(id, title, genre, year, likes, trailer);
			try
			{
				Movie m(id, title, genre, year, likes, trailer);
				contr.getRepo().add(list, m);
				success_msg("added");
			}
			catch (exception& e)
			{
				generic_error_msg(e);
				admin_menu_screen();
			}
			break;
		}
		case 2:
		{
			string old_id;
			afis_lista(list);
			ask_get("id (of movie to be updated)", old_id);
			id_validation_screen(old_id, 2);
			// validez intai sa existe id ul !!

			int poz = contr.getRepo().exists(list, old_id);
			contr.getRepo().del(list, old_id); // sterg din baza de date filmul precedent

			ask_get_ma(id, title, genre, year, likes, trailer); // iau de la utilizator atributele noului film

			year_validation_screen(year);
			likes_validation_screen(likes);

			Movie new_movie(id, title, genre, year, likes, trailer);

			list.insert(list.begin() + poz, new_movie); // si inserez noul film

			afis_lista(list);
			break;
		}
		case 3:
		{
			string id_toDelete;
			ask_get("id (of movie to be deleted)", id_toDelete);
			try
			{
				contr.getRepo().del(list, id_toDelete);
				success_msg("deleted");
			}
			catch (exception& e)
			{
				generic_error_msg(e);
			}
			break;
		}
		case 4:
		{
			afis_lista(list);
			break;
		}
		case 0:
		{
			go_back_screen();
			return;
		}
		default:
		{
			wrong_option_screen();
			break;
		}
		}
	}
}

void UI::afis_lista(const vector<Movie>& list)
{
	cout << "Current list is:\n";
	if (!list.size()) { cout << "This list is empty at the moment!\n"; return; }

	cout << list << '\n';
}
void UI::one_by_one_screen()
{
	vector<Movie>& watchlist = contr.getRepo().getUserWatchlist();

	string genre;
	cout << " (leave blank to view all movie trailers)\n";
	ask_get("genre", genre);

	string mesaj = "( \"y\" = yes / \"n\" = no / \"e\" = exit) option";
	char yne; // yes / no / exit 

	vector<Movie>& genre_list = contr.getRepo().generateUserWatchlist(genre);
	int l = genre_list.size();

	for (int i = 0; i < l; i++)
	{
		cout << genre_list[i] << '\n';
		cout << "-----Check trailer open in Internet browser!-----\n"
			<< "we kindly ask you to wait while the browser is being open\n";

		string aux1 = '"' + genre_list[i].getTrailer() + '"';

		ShellExecute(NULL, "open",
			aux1.c_str(),	// convertesc la `const char*` (asa cere functia `ShellExecute`) adica LPSWTR
			NULL, NULL, SW_SHOWNORMAL);

		cout << (" Do you like this trailer? Would you like to add the movie to your watch list ?\n");
		ask_get(mesaj, yne);

		switch (yne)
		{
		case 'y':
		{
			try
			{
				contr.getRepo().add(watchlist, genre_list[i]);
			}
			catch (exception& e)
			{
				generic_error_msg(e);
			}
			break;
		}
		case 'n': break;
		case 'e': return;
		}
	}
}

void UI::execute_umo()
{
	vector<Movie>& watchlist = contr.getRepo().getUserWatchlist();

	int option;
	while (true)
	{
		user_menu_screen();
		ask_get("option", option);
		switch (option)
		{
		case 1:
		{
			cout << "Please check file database so that you do not misspell any genre!\n"
				<< " Any genre shall be typed in precisely as in the database!\n";

			one_by_one_screen();
			break;
		}
		case 2:
		{
			afis_lista(watchlist);
			if (!watchlist.size()) break;

			string id;
			ask_get("id (of movie to be deleted)", id);
			try
			{
				contr.getRepo().del(watchlist, id);

				char c;
				cout << "Did you enjoy the movie?\n(answering yes will increment the number of likes for that movie in the repository)\n";
				ask_get("(\"y\" = yes / \"n\" = no / \"e\" = exit)\n option", c);
				switch (c)
				{
				case 'y':
				{
					cout << watchlist << '\n';

					vector<Movie>& list = contr.getRepo().getList();

					int poz = contr.getRepo().exists(list, id);
					int nr_likes = list.at(poz).getLikes();

					list.at(poz).setLikes(++nr_likes); // incrementez numarul de like uri

					success_msg("incremented");
				}
				case 'n': break;
				case 'e': return;
				}
			}
			catch (exception& e)
			{
				cerr << e.what();
				cout << "(Maybe check id ?)\n";
			}
			break;
		}
		case 3:
		{
			afis_lista(watchlist);
			break;
		}
		case 0:
		{
			go_back_screen();
			return;
		}
		default:
		{
			wrong_option_screen();
			break;
		}
		}
	}
}

void UI::select_mode_screen()
{
	cout << "Select mode:\n"
		<< "1.Administrator\n"
		<< "2.User\n"
		<< "0.Exit\n";
}

void UI::admin_menu_screen()
{
	cout << "===ADMIN MAIN MENU===\n";
	cout << "0. Go back\n"
		<< "1. Add movie\n"
		<< "2. Update Movie\n"
		<< "3. Delete movie\n"
		<< "4. Display movies\n\n";

}

void UI::user_menu_screen()
{
	cout << "===USER MAIN MENU===\n"
		<< "0. Go back\n"
		<< "1. View movies by specified genre\n"
		<< "2. Delete movie from own watchlist\n"
		<< "3. Display own list\n";
	cout << '\n';
}

void UI::wrong_option_screen()
{
	cout << "Please enter one of the numbers corresponding to the options!!\n";
}

void UI::generic_error_msg(exception& e)
{
	cerr << "===EROARE===\n";	// cerr scrie intr un stream separat de cout; in cazul nostru, coincide stream urile, tho
	cerr << e.what() << '\n';
	cerr << "===============\n";
	cout << '\n';
}


void UI::success_msg(const string& state)
{
	cout << "Change succesful in the respective list:" << state << "!\n";
}

void UI::go_back_screen()
{
	cout << "Going back...\n";
	cout << '\n';
}

// void UI::clear(){ cout << "\x1B[2J\x1B[H"; }