#include "Movie.h"
#include "Repository.h"
#include "Validator.h"
#include <assert.h>
#include "Controller.h"
#include <exception>
#include <sstream>
void testAll()
{
	Repository repotest("Moviestest.txt"),repot("Moviestest.txt");
	Controller ctrltest(repotest),ctrlt(repotest);
	vector<string> nou;
	vector<Movie> m;
	Movie film = Movie("1", "Movie1", "Drama", 2001, 93, "https://www.youtube.com/watch?v=V4h7R4GaPbk");
	film.setID("90");
	film.setTitle("Movie99");
	film.setGenre("Comedy");
	film.setYear(2004);
	film.setLikes(100);
	film.setTrailer("https://www.youtube.com/watch?v=nRzoCIALsBg");
	assert("https://www.youtube.com/watch?v=nRzoCIALsBg" == film.getTrailer());
	Validator v;
	assert(v.validate_id("100", repotest.getIds()) == true);
	assert(v.validate_year(2000) == true);
	assert(v.validate_likes(99) == true);
	std::stringstream stream;
	stream << film;

	nou = repotest.getIds();
	assert(ctrltest.getRepo().getList()[0].getID() == "1");
	ctrltest.getRepo().edit("1", Movie("99", "John", "Action", 2019,99,"www.dorianpopa.ro"));
	ctrlt.setRepo(repot);
	try
	{
		Movie mov = Movie("1", "Movie1", "Drama", 2001, 93, "https://www.youtube.com/watch?v=V4h7R4GaPbk");
		repotest.add(mov);}
	catch(std::exception& e)
	{
		assert(true);
	}
	try {
		repotest.del("1000");}
	catch (std::exception & e)
	{
		assert(true);
	}
	try {
		repotest.edit("1000", Movie("1", "Movie1", "Drama", 2001, 93, "https://www.youtube.com/watch?v=V4h7R4GaPbk"));}
	catch (std::exception & e)
	{
		assert(true);
	}
	m = repotest.GenreList("");
	assert(m == repotest.getList());
	m.clear();
	m.push_back(Movie("5", "John Cena", "Comedy", 2000, 1000, "www.dorianpopa.ro"));
	assert(m == repotest.GenreList("Comedy"));

	assert(ctrltest.getRepo().getList()[0].getTitle() == "John");
	assert(ctrltest.getRepo().getList()[0].getGenre() == "Action");
	assert(ctrltest.getRepo().getList()[0].getYear() == 2019);
	assert(ctrltest.getRepo().getList()[0].getLikes() == 99);
	ctrltest.getRepo().add(Movie("101", "Hatz", "Drama", 2018, 101, "www.dorianpopa.ro"));
	int length = ctrltest.getRepo().getList().size();
	assert(ctrltest.getRepo().getList()[length - 1].getID() == "101");
	ctrltest.getRepo().del("101");
	assert(ctrltest.getRepo().getList().size() == length - 1);


}