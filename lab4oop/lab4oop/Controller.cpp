#include "Controller.h"

Controller::Controller() {

}

void Controller::executa(int i,MedikamentRepo *repo) {
	//aici o sa se execute comanda cu nr i pe lista de medicamente "lista"
	string n="";
	float k, p;
	int m;
	Medikament* medi;
	bool breaked = false;

	switch (i) {
	case 0:
		cout << "Exiting\n";
		break;
	case 1:
		cout << "-Add Medikament-\n";
		cout << "Name: "; cin >> n;
		cout << "Konzentration: "; cin >> k;
		cout << "Menge: "; cin >> m;
		cout << "Preis: "; cin >> p;
		medi =new Medikament(n,k,m,p);
		if (repo->exists(*medi)) {
			cout <<"Medicamentul exista, se modifica cantitatea! \n" ;
			for (int i = 0; i < repo->lista.size(); i++)
				if (repo->lista.at(i).getName() == n && repo->lista.at(i).getKonzentration() == k) {
					repo->lista.at(i).setMenge(m);
					break;
				}


		}
		else {
			repo->addMedikament(*medi);
			delete medi;

		}


		break;
	case 2:
		cout << "-Delete Medikament-\n";
		cout << "Name: "; cin >> n;
		cout << "Konzentration: "; cin >> k;
		repo->deleteMedikament(n, k);
		break;
	case 3:
		cout << "-Edit Medikament-\n";
		cout << "What Medikament do you want to edit?\n";
		cout << "Name: "; cin >> n;
		cout << "Konzentration: "; cin >> k;
		for (int i = 0; i < repo->lista.size() && breaked==false; i++)
			if (repo->lista.at(i).getName() == n && repo->lista.at(i).getKonzentration() == k) {
				breaked = true;
				cout << "New Values:\n";
				cout << "Name: "; cin >> n;
				cout << "Konzentration: "; cin >> k;
				cout << "Menge: "; cin >> m;
				cout << "Preis: "; cin >> p;
				repo->lista.at(i).setName(n);
				repo->lista.at(i).setKonzentration(k);
				repo->lista.at(i).setMenge(i);
				repo->lista.at(i).setPreis(p);
				break;
			}
		break;
	case 4:
		
		cout << "-Display Medikament-\n";
		cout << "Ce sa contina numele medicamentelor? ";   cin >> n;//aici!!!!!
		repo->showMedikament(n);



		break;

	default:
		cout << "Optiunea nu exista, va rugam reincercati!\n";
		break;

	}
		
}
