#include "Medikament.h"

Medikament::Medikament(string n, float k, int m, float p)
{
	name = n;
	konzentration = k;
	menge = m;
	preis = p;

}

string Medikament::getName()
{
	return name;
}

void Medikament::setName(string n)
{
	name = n;
}

float Medikament::getKonzentration()
{
	return konzentration;
}

void Medikament::setKonzentration(float k)
{
	konzentration = k;
}

int Medikament::getMenge()
{
	return menge;
}

void Medikament::setMenge(int m)
{
	menge = m;
}

float Medikament::getPreis()
{
	return preis;
}

void Medikament::setPreis(float p)
{
	preis = p;
}
