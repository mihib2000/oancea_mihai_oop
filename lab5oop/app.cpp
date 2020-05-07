#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <vector>

#include "Movie.h"
#include "Repository.h"
#include "Controller.h"
#include "UI.h"
#include "Tests.h"

using std::cin;
using std::cout;
using std::ifstream;
using std::getline;
using std::string;

using std::vector;

using Tests::testAll;

void run_tests()
{
	testAll();
	cout << "All tests were successfully run. App is good to go!\n";
}


/*
	Create the layered-architecture of the app.
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
	run_tests();
	start();

	return 0;
}