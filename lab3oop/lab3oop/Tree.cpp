//schimbari: am pus mai mic strict in functia de insert (ca sa pot vizualiza mai bine ceva, ca am gasit un site misto) dar numai temporar!!
#include "Tree.h"
#include <vector>
#include <iostream>

Tree::Tree(Node r) {
	root = r;
	std::cout << " s a bagat radacina " << r.wert << '\n';
}

void Tree::insert(int v, Node* r) {

	if (v < r->wert)					// daca valoarea nodului de inserat e mai mica decat valoarea nodului radacina
	{									// inseamna ca nodul de inserat va fi adaugat in subarborele stang
										// (ne raportam la subarborele curent)
		if (r->l == nullptr) {			// daca am dat de o frunza, inseamna ca nodul de inserat va deveni copil stang al acesteia; astfel:
			r->l = new Node();			// cream un nou nod, iar acesta devine copil stang al fostei frunze
			r->l->wert = v;
			r->l->l = nullptr;
			r->l->r = nullptr;			// orice nod adaugat devine frunza, deci nu are copii momentan

			std::cout << r->l->wert << " a fost bagat in stanga lui " << r->wert << std::endl;
		}
		else							// alftel ("altfel" = nu am dat de o frunza),
			insert(v, r->l);			// continua cautarea in subarborele stang
	}
	else								// daca valoarea nodului de inserat e mai mare deca valoarea nodului radacina
	{									// inseamna ca nodul de inserat va fi adaugat in subarborele drept
										// (ne raportam la subarborele curent)
		if (r->r == nullptr) {			// daca am dat de o frunza, inseamna ca nodul de inserat va deveni copil drept al acesteia; astfel:
			r->r = new Node();			// cream  un nou nod, iar acesta devine copil drep al fostei frunze
			r->r->wert = v;
			r->r->l = nullptr;
			r->r->r = nullptr;			// orice nod adaugat devine frunza, deci nu are copii momentan

			std::cout << r->r->wert << " a fost bagat in dreapta lui " << r->wert << std::endl;
		}
		else                            // altfel ("altfel" = nu am dat de o frunza),
			insert(v, r->r);			// continua cautarea in subarborele drept
	}

}

Node* Tree::FindMin(Node* root)
{
	while (root->l != NULL) root = root->l;
	return root;
}

Node* Tree::del(int data, Node* root) {
	if (root == NULL) return root;					// daca se pointeaza catre o valoare nula, inseamna ca nu este nimic de sters, deci returnam null
	else
		if (data < root->wert)
			root->l = del(data, root->l);
		else
			if (data > root->wert)
				root->r = del(data, root->r);
	// root = nodul de sters
			else {
				// Case 1:  Frunza
				if (root->l == NULL && root->r == NULL) {
					delete root;
					root = NULL;
				}
				//Case 2: Un singur copil 
				else if (root->l == NULL) {
					Node* temp = root;
					root = root->r;
					delete temp;
				}
				else if (root->r == NULL) {
					Node* temp = root;
					root = root->l;
					delete temp;
				}
				// case 3: 2 copii
				else {
					Node* temp = FindMin(root->r);
					root->wert = temp->wert;
					root->r = del(temp->wert, root->r);
				}
			}
	return root;
}

std::string Tree::postorder(Node* node)
{
	if (node == NULL)
		return "";
	// postordine:	stanga					dreapta								radacina

	//return postorder(node->l) +" "+ postorder(node->r) + " " + std::to_string(node->wert) + " ";
	return postorder(node->l) + postorder(node->r) + std::to_string(node->wert) + " ";
}

std::string Tree::inorder(Node* node)
{
	if (node == NULL)
		return "";
	// inordine:	stanga							radacina					dreapta
	return inorder(node->l) + std::to_string(node->wert) + " " + inorder(node->r);
}

std::string Tree::preorder(Node* node)
{
	if (node == NULL)
		return "";
	// preordine:			radacina					stanga					dreapta
	return std::to_string(node->wert) + " " + preorder(node->l) + preorder(node->r);
}

int Tree::countNodes(Node* node) {

	if (node == NULL) {
		return 0;
	}
	else {
		return 1 + countNodes(node->l) + countNodes(node->r);
	}
}

int Tree::countEdges(Node* node) {

	return countNodes(node) - 1;
}


int Tree::height(Node* node) {

	if (node == NULL)
		return -1;
	else
	{

		int l_height = height(node->l);
		int r_height = height(node->r);

		//return l_height > r_height ? : 
		if (l_height > r_height)
			return(l_height + 1);
		else
			return(r_height + 1);
	}
}