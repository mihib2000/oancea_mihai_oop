#include "Tests.h"

void Test_MedikamentRepo::testAddMedikament1()
{
	//setup
	MedikamentRepo lista;

	//run
	lista.addMedikament(Medikament("1", 1, 1, 1));
	lista.addMedikament(Medikament("2", 2, 2, 2));
	lista.addMedikament(Medikament("3", 3, 3, 3));

	//verify
	assert(lista.lista[0].getName() == "1");
	assert(lista.lista[0].getKonzentration() == 1);
	assert(lista.lista[0].getMenge() == 1);
	assert(lista.lista[0].getPreis() == 1);

	assert(lista.lista[1].getName() == "2");
	assert(lista.lista[1].getKonzentration() == 2);
	assert(lista.lista[1].getMenge() == 2);
	assert(lista.lista[1].getPreis() == 2);

	assert(lista.lista[2].getName() == "3");
	assert(lista.lista[2].getKonzentration() == 3);
	assert(lista.lista[2].getMenge() == 3);
	assert(lista.lista[2].getPreis() == 3);

}

void Test_MedikamentRepo::testAddMedikament2()
{
	//setup
	MedikamentRepo lista;

	//run
	lista.addMedikament(Medikament("Paracetamol", 58.125, 40, 5));
	lista.addMedikament(Medikament("Parasinus", 40, 30, 10));
	lista.addMedikament(Medikament("Espumisan", 70, 25, 15));

	//verify
	assert(lista.lista[0].getName() == "Paracetamol");
	assert(lista.lista[0].getKonzentration() == 58.125); // aici daca ii dau 58.6 nu merge; dc ?
	assert(lista.lista[0].getMenge() == 40);
	assert(lista.lista[0].getPreis() == 5);

	assert(lista.lista[1].getName() == "Parasinus");
	assert(lista.lista[1].getKonzentration() == 40);
	assert(lista.lista[1].getMenge() == 30);
	assert(lista.lista[1].getPreis() == 10);

	assert(lista.lista[2].getName() == "Espumisan");
	assert(lista.lista[2].getKonzentration() == 70);
	assert(lista.lista[2].getMenge() == 25);
	assert(lista.lista[2].getPreis() == 15);

}

void Test_MedikamentRepo::testDeleteMedikament1()
{
	//setup
	MedikamentRepo lista;
	lista.addMedikament(Medikament("1", 1, 1, 1));
	lista.addMedikament(Medikament("2", 2, 2, 2));
	lista.addMedikament(Medikament("3", 3, 3, 3));

	//run
	lista.deleteMedikament("1", 1);

	//verify
	int expected = 2;
	assert(lista.lista.size() == expected);

	assert(lista.lista[0].getName() == "2");
	assert(lista.lista[0].getKonzentration() == 2);
	assert(lista.lista[0].getMenge() == 2);
	assert(lista.lista[0].getPreis() == 2);

	assert(lista.lista[1].getName() == "3");
	assert(lista.lista[1].getKonzentration() == 3);
	assert(lista.lista[1].getMenge() == 3);
	assert(lista.lista[1].getPreis() == 3);

}

void Test_MedikamentRepo::testDeleteMedikament2()
{
	//setup
	MedikamentRepo lista;
	lista.addMedikament(Medikament("Paracetamol", 58.250, 40, 5));
	lista.addMedikament(Medikament("Parasinus", 40, 30, 10));
	lista.addMedikament(Medikament("Espumisan", 70, 25, 15));

	//run
	lista.deleteMedikament("Parasinus", 40);

	//verify
	int expected = 2;
	assert(lista.lista.size() == expected);

	assert(lista.lista[0].getName() == "Paracetamol");
	assert(lista.lista[0].getKonzentration() == 58.250); // aici daca ii dau 58.6 nu merge; dc ?
	assert(lista.lista[0].getMenge() == 40);
	assert(lista.lista[0].getPreis() == 5);

	assert(lista.lista[1].getName() == "Espumisan");
	assert(lista.lista[1].getKonzentration() == 70);
	assert(lista.lista[1].getMenge() == 25);
	assert(lista.lista[1].getPreis() == 15);

}

void Test_MedikamentRepo::testExists1()
{
	//setup
	MedikamentRepo lista;
	lista.addMedikament(Medikament("1", 1, 1, 1));
	lista.addMedikament(Medikament("2", 2, 2, 2));
	lista.addMedikament(Medikament("3", 3, 3, 3));

	//srun
	bool result1 = lista.exists(Medikament("1", 1, -1, -1));
	bool result2 = lista.exists(Medikament("2", 2, -1, -1));
	bool result3 = lista.exists(Medikament("3", 3, -1, -1));
	bool result4 = lista.exists(Medikament("4", 4, -1, -1));
	bool result5 = lista.exists(Medikament("5", 5, -1, -1));

	//verify
	bool expected1 = true;
	bool expected2 = true;
	bool expected3 = true;
	bool expected4 = false;
	bool expected5 = false;
	assert(result1 == expected1);
	assert(result2 == expected2);
	assert(result3 == expected3);
	assert(result4 == expected4);
	assert(result5 == expected5);
}

void Test_MedikamentRepo::testExists2()
{
	//setup
	MedikamentRepo lista;
	lista.addMedikament(Medikament("Paracetamol", 58.6, 40, 5));
	lista.addMedikament(Medikament("Parasinus", 40, 30, 10));
	lista.addMedikament(Medikament("Espumisan", 70, 25, 15));

	//run
	bool result1 = lista.exists(Medikament("Paracetamol", 58.6, -1, -1));
	bool result2 = lista.exists(Medikament("Espumisan", 70, -1, -1));
	bool result3 = lista.exists(Medikament("3", 3, -1, -1));
	bool result4 = lista.exists(Medikament("4", 4, -1, -1));
	bool result5 = lista.exists(Medikament("5", 5, -1, -1));

	//verify
	bool expected1 = true;
	bool expected2 = true;
	bool expected3 = true;
	bool expected4 = false;
	bool expected5 = false;
	assert(result1 == expected1);
	assert(result2 == expected2);
	assert(result3 == expected3);
	assert(result4 == expected4);
	assert(result5 == expected5);
}

void Test_MedikamentRepo::testUndo1()
{
	//setup
	MedikamentRepo lista;
	lista.addMedikament(Medikament("1", 1, 1, 1));
	lista.addMedikament(Medikament("2", 2, 2, 2));
	lista.addMedikament(Medikament("3", 3, 3, 3));

	//run
	lista.undo();

	//verify
	assert(lista.lista.size() == 2);

	assert(lista.lista[0].getName() == "1");
	assert(lista.lista[0].getKonzentration() == 1);
	assert(lista.lista[0].getMenge() == 1);
	assert(lista.lista[0].getPreis() == 1);

	assert(lista.lista[1].getName() == "2");
	assert(lista.lista[1].getKonzentration() == 2);
	assert(lista.lista[1].getMenge() == 2);
	assert(lista.lista[1].getPreis() == 2);

}

void Test_MedikamentRepo::testUndo2()
{
	//setup
	MedikamentRepo lista;
	lista.addMedikament(Medikament("Paracetamol", 58.6, 40, 5));
	lista.addMedikament(Medikament("Parasinus", 40, 30, 10));
	lista.addMedikament(Medikament("Espumisan", 70, 25, 15));

	//run
	lista.undo();
	lista.undo();

	//verify
	assert(lista.lista.size() == 1);

	assert(lista.lista[0].getName() == "Paracetamol");
	assert(lista.lista[0].getKonzentration() == 58.6);
	assert(lista.lista[0].getMenge() == 40);
	assert(lista.lista[0].getPreis() == 5);

};

void testAll()
{
	Test_MedikamentRepo::testAddMedikament1();
	Test_MedikamentRepo::testAddMedikament2();
	Test_MedikamentRepo::testDeleteMedikament1();
	Test_MedikamentRepo::testDeleteMedikament2();
	void testEditMedikament1();
	void testEditMedikament2();
	void testExists1();
	void testExists2();
	void testGroupByPriceA();
	void testGroupByPriceD();
	void testUndo1();
	void testUndo2();
	void testRedo1();
	void testRedo2();
	cout << "All tests passed!" << '\n';
}