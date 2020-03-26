#pragma once
#include "MedikamentRepo.h"
#include <iostream>
#include <string>
#include <sstream>
class Controller
{
public:
	Controller();
	void executa(int i, MedikamentRepo *repo);
};

