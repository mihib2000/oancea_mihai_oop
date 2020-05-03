#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class Validator
{
private:

public:

	const int lowest_likes = 0;
	const int lowest_year = 1887;
	const int highest_year = 2020;

	/* Validate logical value of id */
	bool validate_id(const string&, vector<string>);

	/* Validate logical value of likes*/
	bool validate_likes(const int &); // nu validez tipul, validez logica !!
	
	/* Validate logical value of year */
	bool validate_year(const int &);

	/* Validate logical value of trailer */
	bool validate_trailer(const string&);
	/*
	NOTA: am ales sa implementam `validate_trailer` dar nu am folosit o
	in aplicatie pentru ca ar fi durat foarte mult sa copiati link ul
	daca, de exemplu, nu puteti da copy iar apoi paste in terminal.
	Mai mult, nu stiam sigur daca o functie pe care am folosit-o e "cross-platform".
	deci e posibil sa nu mearga pe Mac; pe Windows mergea.
	Am comentat fiecare fragment de cod, peste tot unde aparea un apel al
	acestei functii
	*/
};