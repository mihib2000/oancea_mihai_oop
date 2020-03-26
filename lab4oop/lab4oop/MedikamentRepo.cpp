#include "MedikamentRepo.h"
#include <algorithm>
MedikamentRepo::MedikamentRepo() {

}

void MedikamentRepo::addMedikament(Medikament med) {
	lista.push_back(med);
}

void MedikamentRepo::deleteMedikament(string n, float konz) {
	
	for (int i = 0; i < lista.size(); i++) {
		if (lista.at(i).getName() == n && lista.at(i).getKonzentration() == konz) {
			lista.erase(lista.begin()+i);
			break;
		}
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