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
	int optiune;
	do {
		cout << "Meniu Principal" << endl;
		cout << "1. Adauga Medicament" << endl;
		cout << "2. Sterge Medicament" << endl;
		cout << "3. Editeaza Medicament" << endl;
		cout << "0. Exit" << endl;
		cout << "Introdu Operatiunea: "; cin >> optiune; cout << endl;

		c.executa(optiune, lista);

	} while (optiune !=0);
	

}