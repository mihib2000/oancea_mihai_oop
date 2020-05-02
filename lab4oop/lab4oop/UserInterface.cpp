#include "UserInterface.h"
#include <iostream>

using namespace std;
UserInterface::UserInterface()
{

}

void UserInterface::start() {
	//aici se face meniul din consola
	Controller c;
	MedikamentRepo lista;

	/*
	lista.addMedikament(Medikament("1", 1, 1, 1));
	lista.addMedikament(Medikament("2", 2, 2, 2));
	lista.addMedikament(Medikament("3", 3, 3, 3));
	*/

	int optiune;
	while (true)
	{
		cout << "Meniu Principal" << endl;
		cout << "0. Undo/Redo list" << endl;
		cout << "1. Adauga Medicament" << endl;
		cout << "2. Sterge Medicament" << endl;
		cout << "3. Editeaza Medicament" << endl;
		cout << "4. Vizualizeaza Medicamente" << endl;
		//
		cout << "5. Vizualizeaza Medicamente sub un anumit pret:" << endl;
		cout << "6. Vizualizeaza Medicamente grupate dupa pret:" << endl;
		cout << "7. Undo" << endl;
		cout << "8. Redo" << endl;
		//
		cout << "0. Exit" << endl;
		cout << "Introdu Operatiunea: ";

		cin >> optiune; cout << endl;

		if (optiune == 6)
		{
			cout << "9.ascendent\n";
			cout << "10.descendent\n";
			cout << "Introdu Operatiunea: "; cin >> optiune; cout << endl;

		}

		if (0 <= optiune && optiune <= 10)
			c.executa(optiune, &lista);
		else cout << "Nu s-a introdus o optiune valida!\n"
			<< "Va rugam sa introduceti optiune valida!\n";

	}


}