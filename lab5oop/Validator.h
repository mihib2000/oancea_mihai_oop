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
	//const int highest_likes = 10005;

	const int lowest_year = 1887;
	const int highest_year = 2020;

	bool validate_id(const string&, vector<string>);
	bool validate_likes(const int &); // nu validez tipul, validez logica !!
	bool validate_year(const int &);
	bool validate_trailer(const string&);
};