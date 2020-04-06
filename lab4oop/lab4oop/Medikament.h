#pragma once
#include <string>
#include <iostream>
using namespace std;
class Medikament
{
private:
	string name;
	float konzentration;
	int menge;
	float preis;

public:

	/*
		Constructor
	*/
	Medikament(string n, float k, int m, float p);

	/*
		Getter atribut name
	*/
	string getName();

	/*
		Setter atribut nume
	*/
	void setName(string n);

	/*
		Getter atribut konzentration
	*/
	float getKonzentration();

	/*
		Setter atribut Konzentration
	*/
	void setKonzentration(float k);

	/*
		Getter atribut menge
	*/
	int getMenge();

	/*
		Setter atribut menge
	*/
	void setMenge(int m);

	/*
		Getter atribut preis
	*/
	float getPreis();

	/*
		Setter atribut preis
	*/
	void setPreis(float p);

	/*
		Afiseaza toate atributele obiectului.
	*/
	void print();
};