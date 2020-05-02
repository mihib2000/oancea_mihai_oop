/*
#include "Controller.h"

template<typename repo_type>
Controller<repo_type>::Controller(repo_type repository) : repo(repository)
{
}


template<typename repo_type>
repo_type Controller<repo_type>::getRepo() { return repo; }
*/

#include "Controller.h"
//Controller::Controller( Repository r, UI ui )
Controller::Controller( Repository r ) //
{
//	this->repo = r;

	repo = r;

	//	this->ui = ui;
}

/*
Controller::Controller()
{
	repo = 
}
*/

Repository& Controller::getRepo()
{
	// return (this);
//	return &repo;
	return repo; // "returnez exact acea locatie de memorie" , sa zic asa; acea adresa
}

void Controller::setRepo(Repository value)
{
	repo = value;
}