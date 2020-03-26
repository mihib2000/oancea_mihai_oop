#include "MedikamentRepo.h"

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

	return true;
}


void MedikamentRepo::showMedikament(string str) {

}