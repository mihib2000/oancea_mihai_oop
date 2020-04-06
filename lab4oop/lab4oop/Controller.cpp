#include "Controller.h"

Controller::Controller() {

}

void Controller::executa(int i, MedikamentRepo* repo) {
	//aici o sa se execute comanda cu nr i pe lista de medicamente "lista"
	string n = "";
	float k, p;
	int m;
	Medikament* medi;
	bool breaked = false;

	switch (i) {
	case 0:
		cout << "-Show history-";
		repo->showUR();

		break;

	case 1:
		cout << "Name: "; cin >> n;
		cout << "Konzentration: "; cin >> k;
		cout << "Menge: "; cin >> m;
		cout << "Preis: "; cin >> p;
		medi = new Medikament(n, k, m, p);
		if (repo->exists(*medi)) {
			cout << "Medicamentul exista, se modifica cantitatea! \n";
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
		for (int i = 0; i < repo->lista.size() && breaked == false; i++)
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


	case 5:

		float l;
		cout << "-Show Below-'\n";
		cout << "Care este pretul-limita?"; cin >> l;
		repo->showMedikamentBelow(l);



		break;

	case 7:

		repo->undo();



		break;

	case 8:

		repo->redo();



		break;

	case 9:
		cout << "-Group By Price-\n";
		cout << "-----ascendent\n";
		repo->groupByPriceA();



		break;

	case 10:
		cout << "-Group By Price-\n";
		cout << "-----descendent\n";
		repo->groupByPriceD();



		break;

	}

}
