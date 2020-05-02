#include <iostream>
#include <vector>
#include "UserInterface.h"
#include"Tests.h"

using std::cout;

int main()
{
	testAll();
	UserInterface ui;
	ui.start();
}


