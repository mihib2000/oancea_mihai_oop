#pragma once
#include <exception>
#include "Controller.h"
#include "Validator.h"

using std::exception;

class UI
{
private:
	
	Controller contr;

	Validator validator;

	void clear();

	/*Prints the contents of a `vector<Movie>` object*/
	void afis_lista(vector<Movie>&);

	/* aici am incercat ceva cu template dar ar fi trebuit sa folosim ceva numit ""
		ca sa pastram abstractizarea "header-cpp" si era ceva cam complicat, asa ca
		am ramas la overloaded functions
	*/
	/* ask for & get an integer from user*/
	void ask_get(string mesaj, int& var);

	/* ask for & get a string from user*/
	void ask_get(string mesaj, string& var);
	
	/* ask for & get an integer from user*/
	void ask_get(string mesaj, char &c);

	/* ask for & get movie attributes from user*/
	void ask_get_ma(string& id, string& title, string& genre, int& year, int& likes, string& trailer);
	

	
	void invalid_screen(const string&, const string&, const string&);
	void invalid_screen(const string&, const int&, const int&);
	void invalid_screen(const string&, const int&);
	void invalid_screen(const string&);

	void validation_screen(int &year, int &likes );
	void validation_screen(string &id, int &year, int &likes );


	void wrong_option_screen();
	void generic_error_msg(exception&);
	void success_msg(const string&);


	void select_mode_screen();
	void admin_menu_screen(); // admin main menu
	void user_menu_screen(); // user main menu
	void one_by_one_screen(vector<Movie> , vector<Movie>&);
	void go_back_screen();

	
	void execute_amo(); // execute admin menu option
	void execute_umo(vector<Movie>& own_list); // execute user menu option
	
public:
	UI(Controller c = Controller() );

	Controller& getController();

	void run();
};
