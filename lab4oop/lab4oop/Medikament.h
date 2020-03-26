#pragma once
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
	void setName();
	float getKonzentration();
	void setKonzentration();
	int getMenge();
	void setMenge();
	float getPreis();
	void setPreis();


};

