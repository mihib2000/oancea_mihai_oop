#include <assert.h>

#include "Tests.h"

using std::cout;
using std::exception;


void Tests::testRepositoryConstructor()
{

	//setpu & run
	Repository r;

	//verify
	vector<Movie>& list = r.getList();
	assert(list.size() == 13);
	assert(list.at(0).getID() == "1");
	assert(list.at(5).getTitle() == "Schindler's List");
	assert(list.at(7).getYear() == 1994);
	assert(list.at(10).getLikes() == 88);
	assert(list.at(12).getTrailer() == "www.imdb.com/video/vi3877612057?playlistId=tt0111161&ref_=tt_ov_vi");
}

void Tests::testExists()
{
	//setup
	Repository r;
	vector<Movie>& database = r.getList();

	//run
	int poz = r.exists(database, "1");
	int poz2 = r.exists(database, "5");
	int poz3 = r.exists(database, "14");

	//verify
	assert(poz == 0);
	assert(poz2 == 4);
	assert(poz3 == -1);
}

void Tests::testExists2()
{
	//setup
	Repository r;
	vector<Movie>& database = r.getList();

	//run
	int poz = r.exists(database, "12");
	int poz2 = r.exists(database, "11");
	int poz3 = r.exists(database, "14");

	//verify
	assert(poz == 11);
	assert(poz2 == 10);
	assert(poz3 == -1);
}


void Tests::testAdd()
{
	//setup
	Repository r("TestData.txt");
	vector<Movie>& database = r.getList();

	//run
	try
	{
		r.add(database, Movie("8", "Pulp Fiction", "Crime Drama", 1994, 89, "www.imdb.com/video/vi2620371481?playlistId=tt0110912&ref_=tt_ov_vi"));
		// daca functia e bine implementata, va arunca exceptie pe randul asta de mai sus deci nu va face `assert(false);`
		assert(false);
	}
	catch (exception& e) { ; }

	// verify
	assert(database.size() == 13);
	assert(Movie("8", "Pulp Fiction", "Crime Drama", 1994, 89, "www.imdb.com/video/vi2620371481?playlistId=tt0110912&ref_=tt_ov_vi") == database[7]);
	// fiindca am suprascris operatorul `==` pentru 2 parametri de tip Movie, se va considera egalitatea intre id uri aici!
	assert("Pulp Fiction" == database[7].getTitle());
	assert("Crime Drama" == database[7].getGenre());
	assert(1994 == database[7].getYear());
	assert(89 == database[7].getLikes());

	assert((1890 == database[6].getYear()) == false);
	assert((85 == database[8].getLikes()) == false); // am verificat aleatoriu si 2 atribute ale vecinilor, sa verific daca nu cumva, din intamplare
	// functia modifica atributele acestora, ceea ce nu trebuie sa se intample
}

void Tests::testAdd2()
{
	//setup
	Repository r("TestData.txt");
	vector<Movie>& database = r.getList();

	//run
	try
	{
		r.add(database, Movie("20", "Virgil Abloh", "Documentary", 2019, 62, "www.imdb.com/video/vi2620371481?playlistId=tt0110912&ref_=tt_ov_vi"));
		// daca funcita e bine implementata, va arunca exceptie pe randul asta de mai sus deci nu va face `assert(false);`
	}
	catch (exception& e)
	{
		assert(false);
	}

	// verify
	assert(database.size() == 14);
	assert(Movie("20", "Virgil Abloh", "Documentary", 2019, 62, "www.imdb.com/video/vi2620371481?playlistId=tt0110912&ref_=tt_ov_vi") == database[13]);
	// fiindca am suprascris operatorul `==` pentru 2 parametri de tip Movie, se va considera egalitatea intre id uri aici!
	assert("Virgil Abloh" == database[13].getTitle());
	assert("Documentary" == database[13].getGenre());
	assert(2019 == database[13].getYear());
	assert(62 == database[13].getLikes());

	assert(("Virgil Abloh" == database[12].getTitle()) == false);
	assert(("Documentary" == database[12].getGenre()) == false);
}

void Tests::testAdd3()
{
	//setup
	Repository r("TestData.txt");
	vector<Movie>& watchlist = r.getUserWatchlist();

	//run
	try
	{
		r.add(watchlist, Movie("11", "Marie Curie", "Historical", 1965, 79, "www.imdb.com/video/vi2620371481?playlistId=tt0110912&ref_=tt_ov_vi"));
		// daca funcita e bine implementata, va arunca exceptie pe randul asta de mai sus deci nu va face `assert(false);`
	}
	catch (exception& e)
	{
		assert(false);
	}

	// verify
	assert(watchlist.size() == 1);
	assert(Movie("11", "Marie Curie", "Historical", 1965, 79, "www.imdb.com/video/vi2620371481?playlistId=tt0110912&ref_=tt_ov_vi") == watchlist[0]);
	// fiindca am suprascris operatorul `==` pentru 2 parametri de tip Movie, se va considera egalitatea intre id uri aici!
	assert("Marie Curie" == watchlist[0].getTitle());
	assert("Historical" == watchlist[0].getGenre());
	assert(1965 == watchlist[0].getYear());
	assert(79 == watchlist[0].getLikes());
}

void Tests::testDel()
{
	//setup
	Repository r("TestData.txt");
	vector<Movie>& database = r.getList();

	//run
	try
	{
		r.del(database, "14");
		assert(false);
	}
	catch (exception& e) { ; }

	//verify
	assert(database.size() == 13);
}

void Tests::testDel2()
{
	//setup
	Repository r("TestData.txt");
	vector<Movie>& database = r.getList();

	//run
	try
	{
		r.del(database, "12");
	}
	catch (exception& e)
	{
		assert(false);
	}

	//verify
	assert(database.size() == 12);
}

void Tests::testDel3()
{
	// setup
	Repository r("TestData.txt");
	vector<Movie>& watchlist = r.getUserWatchlist();

	//run
	try
	{
		r.del(watchlist, "5");
		assert(false);
	}
	catch (exception& e) { ; }

	//verify
	assert(watchlist.size() == 0);
}

void Tests::testEdit()
{
	//setup
	Repository r;
	vector<Movie>& list = r.getList();

	//run
	try
	{
		r.edit(list, "1", Movie("1", "proba", "proba", 1, 1, "proba"));
	}
	catch (exception& e)
	{
		assert(false);
	}

	// verify
	assert(list[0].getID() == "1");
	assert(list[0].getTitle() == "proba");
	assert(list[0].getGenre() == "proba");
	assert(list[0].getYear() == 1);
	assert(list[0].getLikes() == 1);
	assert(list[0].getTrailer() == "proba");

	assert(list.size() == 13);
	assert(list[1].getID() != "1");
	assert(list[1].getTitle() != "proba");
}

void Tests::testEdit2()
{
	//setup
	Repository r;
	vector<Movie>& list = r.getList();

	//run
	try
	{
		r.edit(list, "9", Movie("2", "ProbA", "ProbA", 2, 2, "ProbA"));

	}
	catch (exception& e)
	{
		assert(false);
	}

	// verify
	assert(list[8].getID() == "2");
	assert(list[8].getTitle() == "ProbA");
	assert(list[8].getGenre() == "ProbA");
	assert(list[8].getYear() == 2);
	assert(list[8].getLikes() == 2);
	assert(list[8].getTrailer() == "ProbA");

	assert(list.size() == 13);
	assert(list[7].getID() != "1");
	assert(list[9].getTitle() != "ProbA");
}

void Tests::testEdit3()
{
	//setup
	Repository r;
	vector<Movie>& list = r.getList();

	//run
	try
	{
		r.edit(list, "22", Movie("2", "ProbA", "ProbA", 2, 2, "ProbA"));

	}
	catch (exception& e)
	{
		// verify
		assert(true);
	}
}

void Tests::testAll()
{
	testRepositoryConstructor();

	testExists();
	testExists2();

	testAdd();
	testAdd2();
	testAdd3();

	testDel();
	testDel2();
	testDel3();

	testEdit();
	testEdit2();
	testEdit3();
}