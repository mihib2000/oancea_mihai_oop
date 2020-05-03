#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <vector>

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
	Create the layer-architecture of the app.
*/
void start()
{
	Repository repo("Movies.txt");
	Controller ctrl(repo);
	UI ui(ctrl);

	ui.run(); // run the app
}

int main()
{	
	start();

	return 0;
}