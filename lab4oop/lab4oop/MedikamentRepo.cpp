#include "MedikamentRepo.h"
#include <algorithm>


MedikamentRepo::MedikamentRepo() {
	index_undo_redo = 0; // index ul va fi pana la primul undo
	// mereu egal cu dimensiunea listei de medicamente
}

void MedikamentRepo::showUR()
{
	cout << " ISTORIC: " << undo_redo_list.size() << " elemente in lista istoricului" << '\n';
	for (int i = 0; i < undo_redo_list.size(); i++)
	{
		cout << "-------------------------------------------\n";
		for (int j = 0; j < undo_redo_list[i].size(); j++)
			undo_redo_list[i][j].print();
		cout << "-------------------------------------------\n";
		cout << '\n';
	}
	cout << "===========================================\n";
	cout << '\n';
}

void MedikamentRepo::addMedikament(Medikament med) {
	lista.push_back(med);
	if (index_undo_redo == undo_redo_list.size())
		// daca nu s au mai efectuat alte operatii 
		// ( adica daca sunt "actual" cu lista undo_redo("actual" = `lista` coincide cu 
		// `undo_redo_list`
		// intre undo uri si redo uri
	{
		undo_redo_list.push_back(lista); // intai retin stadiul curent, apoi actualizez
		index_undo_redo++;
	}
	else
	{
		undo_redo_list.at(index_undo_redo) = lista;
		index_undo_redo++;
	}
	cout << '\n';
}

void MedikamentRepo::deleteMedikament(string n, float konz) {

	for (int i = 0; i < lista.size(); i++) {
		if (lista.at(i).getName() == n && lista.at(i).getKonzentration() == konz) {
			lista.erase(lista.begin() + i);
			break;
		}
	}

	if (index_undo_redo == undo_redo_list.size())
	{
		undo_redo_list.push_back(lista);
		index_undo_redo++;
	}
	else
	{
		undo_redo_list.at(++index_undo_redo) = lista;
	}
}

bool MedikamentRepo::exists(Medikament med) {

	for (int i = 0; i < lista.size(); i++)
		if (lista.at(i).getName() == med.getName() && lista.at(i).getKonzentration() == med.getKonzentration())
			return true;

	return false;
}


void MedikamentRepo::showMedikament(string str) {

	vector<Medikament> temp;
	auto relatie = [](Medikament a, Medikament b) { return a.getName() < b.getName(); };


	for (int i = 0; i < lista.size(); i++) {
		if (lista.at(i).getName().find(str) != std::string::npos && lista.at(i).getMenge() > 0) {
			temp.push_back(lista.at(i));
		}
	}

	sort(temp.begin(), temp.end(), relatie);
	for (int i = 0; i < temp.size(); i++)
		temp.at(i).print();


}

void MedikamentRepo::showMedikamentBelow(float limit)
{
	vector<Medikament> temp;
	auto relatie = [](Medikament a, Medikament b) { return a.getName() < b.getName(); };

	for (int i = 0; i < lista.size(); i++) {
		if (lista.at(i).getPreis() < limit)
			temp.push_back(lista.at(i));
	}

	sort(temp.begin(), temp.end(), relatie);
	for (int i = 0; i < temp.size(); i++)
		temp.at(i).print();
}

void MedikamentRepo::groupByPriceA()
{
	auto relatie = [](Medikament a, Medikament b) { return a.getPreis() < b.getPreis(); };
	vector<Medikament> temp;

	for (int i = 0; i < lista.size(); i++)			//fac o copie a listei
		temp.push_back(lista.at(i));

	sort(temp.begin(), temp.end(), relatie);		// sortez copia
	for (int i = 0; i < lista.size(); i++)			// afisez copia ascendent
		temp.at(i).print();
}

void MedikamentRepo::groupByPriceD()
{
	auto relatie = [](Medikament a, Medikament b) { return a.getPreis() > b.getPreis(); };
	vector<Medikament> temp;

	for (int i = 0; i < lista.size(); i++)			//fac o copie a listei
		temp.push_back(lista.at(i));

	sort(temp.begin(), temp.end(), relatie);		// sortez copia
	for (int i = 0; i < lista.size(); i++)			// afisez copia sortata descendent
		temp.at(i).print();
}

void MedikamentRepo::undo()
{
	if (index_undo_redo <= 1) { cout << "!NU ESTE POSIBILA COMANDA UNDO IN ACEST MOMENT!"; } // aici ar trebui aruncata exceptie, de fapt
	else
	{
		for (int i = 0; i < lista.size(); i++)
			lista[i].print();

		index_undo_redo--;
		lista = undo_redo_list[index_undo_redo - 1];
	}
}

void MedikamentRepo::redo()
{
	if (index_undo_redo == undo_redo_list.size()) {
		cout << "!NU ESTE POSIBILA COMANDA REDO IN ACEST MOMENT!\n"; cout << '\n';
	}
	else
	{
		lista = undo_redo_list[index_undo_redo];
		index_undo_redo++;
	}
}