#pragma once
#include "Medikament.h"
#include "MedikamentRepo.h"
#include <cassert>

namespace Test_Medikament
{
	void testMedikament1();
	void testMedikament2();
	// Medikament 
};

namespace Test_MedikamentRepo {

	void testAddMedikament1();
	void testAddMedikament2();
	void testDeleteMedikament1();
	void testDeleteMedikament2();
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
};

void testAll();