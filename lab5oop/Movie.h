#pragma once
#include <iostream>
#include <string>

using std::string;
using std::ostream;

class Movie
{
private:

	string id;

	string title;
	string genre;
	int year; //release year
	int likes;
	string trailer; // trailer link

public:

	/* Constructor */
	Movie(string = "-1", string = "N/A", string = "N/A", int = -1, int = -1, string = "N/A");
	
	
	/* getters & setters for all attributes*/

	string getID() const;
	void setID(string);

	string getTitle() const;
	void setTitle(string);
	
	string getGenre() const;
	void setGenre(string);
	
	int getYear() const;
	void setYear(int);
	
	int getLikes() const;
	void setLikes(int);
	
	string getTrailer() const;
	void setTrailer(string);
};
bool operator==(const Movie& lhs, const Movie& rhs);
ostream& operator<<(ostream& os, const Movie& m); // o referinta la un stream pentru ca modific streamul