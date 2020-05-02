/*
#pragma once
#include "Repository.h"
// template<typename repo_type> 
class Controller
{

private:
	Repository repo;

public:
	Controller(repo_type repository);

	// repo_type* getRepo(); {return &repo;}
	Repository getRepo();

};
*/

#pragma once
#include "Repository.h"
// #include "UI.h"
class Controller
{
private:
	Repository repo;
	// UI ui; // nu are UI !!!

public:

	//Controller();
	//Controller(Repository r = Repository(), UI ui = UI());
	Controller(Repository r = Repository());

	Repository& getRepo();
	void setRepo(Repository value);
	//////////////////////////////////////

	// void start();

	// 	void select_mode();
};
