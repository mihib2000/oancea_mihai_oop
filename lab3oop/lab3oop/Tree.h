#pragma once
#include "Node.h"
#include <vector>
#include <string>
class Tree
{

public:
	Node root;

	/*
	Constructor
	*/
	Tree(Node r);

	/*
	Creeaza un nou nod, cu valoarea v, si-l insereaza pe pozitia corespunzatoare.
	*/
	void insert(int v, Node* r);

	/*
	Gaseste nodul cu valoarea 'v' si il sterge din arbore.
	NOTA: In implementare propusa s-a optat pentru a aduce in locul nodului radacina din subarborele curent 
	cea mai mica valoare din subarborele drept al subarborelui curent.
	*/
	Node* del(int v, Node* r);

	/*
		Gaseste si returneaza valoarea minima din arbore.
	*/
	Node* FindMin(Node* root);

	/*
		Afiseaza arborele in postordine.
	*/
	std::string postorder(Node* node);

	/*
		Afiseaza arborele in inordine.
	*/
	std::string inorder(Node* node);

	/*
		Afiseaza arborele in preordine
	*/
	std::string preorder(Node* node);

	/*
		Returneaza numarul de noduri din arbore
	*/
	int countNodes(Node* node);

	/*
	Returneaza numarul de muchii dintr-un nod.
	*/
	int countEdges(Node* node);

	/*
	Returneaza inaltimea arborelui (distanta, in numar de muchii, de la radacina arborelui pana la cea mai indepartata frunza a sa)
	*/
	int height(Node* node);

};