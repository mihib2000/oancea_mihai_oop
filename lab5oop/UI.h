#pragma once

// #include "Controller.h" // atentie la circular dependency !!!

//template<typename tip_controller>
#include "Controller.h"
class UI
{
private:
	
	Controller contr;
//	UI ui;

	void afis_lista(vector<Movie>&);

	void get_option(int&);
	void get_option(char&);

	//	template<typename T>
		/*
		void get_input(string, int&);
		void get_input(string, string&);
		*/

	//template <typename T>f
	void get_input(string mesaj, int& var);
	void get_input(string mesaj, string& var);

	void wrong_input_msg();

	//========================================================================

	void select_user();




	//========================================================================

	//	void main_menu(const int&); // asta cauza o eroare in alta parte da nu inteleg dc

	void get_movie_attributes(string& id, string& title, string& genre, int& year, int& likes, string& trailer);

	void main_menu(int&, vector<Movie>&); // asta cauza o eroare in alta parte da nu inteleg dc
	//ostream& operator<<main_menu()
	//string main_menu();

	void execute_amm(int option);
	void execute_umm(int option, vector<Movie>& own_list);

	// log_in_mode

	void select_mode();

	void user_mm(vector<Movie>&); // user main menu

	void admin_mm(); // admin main menu

	void add_screen();

	void follow_command();


public:
	// UI(Controller c /*= Controller()*/);
	UI(Controller c = Controller() );

	// doar getter imi trebuie!!
	// Controller& getController();

	Controller& getController();


//	void start(void(func*)() = &main_menu); // pointer la o alta metoda de aici
	// eventual, de revenit aici !!
	void start();

	
};
