#pragma once

#include "Movie.h"
#include "Repository.h"
#include "Validator.h"
#include "Controller.h"

namespace Tests {
	void testRepositoryConstructor();

	void testExists();
	void testExists2();

	void testAdd();
	void testAdd2();
	void testAdd3();

	void testDel();
	void testDel2();
	void testDel3();

	void testEdit();
	void testEdit2();
	void testEdit3();
	void testAll();
}