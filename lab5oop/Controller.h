#pragma once
#include "Repository.h"

class Controller
{
private:
	Repository repo;

public:

	Controller(Repository r = Repository());

	Repository& getRepo();
	void setRepo(Repository value);
};
