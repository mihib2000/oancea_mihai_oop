#include <string>
#include "Movie.h"

using std::string;

//Movie::Movie(string title,): title()
Movie::Movie(//int id = -1,
	string id,
	string title, string genre, int year , 
	int likes, string trailer)
	//:id{ id }, title{ title }, genre{ genre }, year{ year }, 
	//likes{ likes }, trailer{ trailer }
{ /* merg ambele variante de initializare in acest caz; prolly ca atunci cand as fi 
     avut de lucrat cu clase drept atribute si nu tipuri de astea predefinite (triviale) s-ar fi schimbat treaba*/

	this->id = id;
	this->title = title;
	this->genre = genre;
	this->year = year;
	this->likes = likes;
	this->trailer = trailer;

}

string Movie::getID() const { return id; }
void Movie::setID(string value) { id = value; }

string Movie::getTitle() const { return title; }
void Movie::setTitle(string value) { title = title; }

string Movie::getGenre() const { return genre; }
void Movie::setGenre(string value) { genre = value; }

int Movie::getYear() const { return year; }
void Movie::setYear(int value) { year = value; }

int Movie::getLikes() const { return likes; }
void Movie::setLikes(int value) { likes = value; }

string Movie::getTrailer() const { return trailer; }
void Movie::setTrailer(string value) { trailer = value; }

bool operator==(const Movie& lhs, const Movie& rhs)
{
	return lhs.getID() == rhs.getID();
}

ostream& operator<<(ostream& os, const Movie& m) // o referinta la un stream pentru ca modific streamul
{
	os << "\"" << m.getTitle() << "\" " << m.getGenre() << " " << m.getYear() << " " << m.getLikes();
	return os;
}

// Movie::~Movie // handled automatically