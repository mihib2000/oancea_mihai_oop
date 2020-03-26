#include "MedikamentRepo.h"

MedikamentRepo::MedikamentRepo() {

}

void MedikamentRepo::addMedikament(Medikament med) {
	lista.push_back(med);
}
