#pragma once
#include "Medikament.h"
#include <vector>
using namespace std;
class MedikamentRepo
{


public:
	vector<Medikament> lista;

	/*
		Constructor
	*/
	MedikamentRepo();

	/*
		Adauga un medicament in lista de medicamente
		med - medicamentul de adaugat
	*/
	void addMedikament(Medikament med);

	/*
		Sterge un medicament din lista de medicamente
		med - medicamentul de sters
	*/
	void deleteMedikament(string n, float konz);

	/*
		Verifica daca un medicament `med` exista in lista de medicamente(verificarea se face conform cerintei)
	*/
	bool exists(Medikament med);

	/*
		Afiseaza un anumit medicament
	*/
	void showMedikament(string str);
	
	/*
		Afiseaza medicamente cu pretul sub limita `limit`
	*/
	void showMedikamentBelow(float limit);
	
	/*
		Afiseaza medicamentele sortate ascendent, dupa pret.
	*/
	void groupByPriceA();
	
	/*
		Afiseaza medicamentele sortate descendent, dupa pret.
	*/
	void groupByPriceD();

	/*
		Readuce lista de medicamente la stadiul precedent
	*/
	void undo();
	
	/*
		Inversa metodei undo
	*/
	void redo();

	/*
		Afiseaza istoricul listei de medicamente
	*/
	void showUR();

	vector <vector<Medikament>> undo_redo_list;
	int index_undo_redo;

};

