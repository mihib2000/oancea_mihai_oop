#pragma once
#include <string>
using namespace std;
class Medikament
{
private:
	string name;
	float konzentration;
	int menge;
	float preis;

public:
	Medikament(string n, float k, int m, float p);
	string getName();
	void setName(string n);
	float getKonzentration();
	void setKonzentration(float k);
	int getMenge();
	void setMenge(int m);
	float getPreis();
	void setPreis(float p);


};

