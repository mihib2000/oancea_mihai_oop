#pragma once
#include "Medikament.h"
#include <vector>
using namespace std;
class MedikamentRepo
{
public:
	vector<Medikament> lista;

	MedikamentRepo();
	void addMedikament(Medikament med);

};

